
import java.awt.*;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import jp.ac.ryukoku.math.cards.*;

abstract class Cell extends Pile {

    Cell() {
    }

    Cell(double dx, double dy) {
        super(dx, dy);
    }

    /* card 以下のカードがfree個の空きで移動可能かどうかを戻す */
    abstract boolean movableFrom(Card card, int free);

    /* from の card 以下の列がここへ移動可能かどうかを戻す */
    abstract boolean movableTo(Cell from, Card card, int free);
}

class Free extends Cell {

    boolean movableFrom(Card card, int free) {
        return true;
    }

    boolean movableTo(Cell from, Card card, int free) {
        return isEmpty();
    }
}

class Home extends Cell {

    boolean movableFrom(Card card, int free) {
        return false;
    }

    boolean movableTo(Cell from, Card card, int free) {
        if (isEmpty()) {
            return card.rank == Rank.ACE;
        }
        Card top = top();
        return card.suit == top.suit
                && card.rank.getNumber() == top.rank.getNumber() + 1;
    }
}

class Cascade extends Cell {

    Cascade() {
        super(0.0, 30.0);
    }

    boolean movableFrom(Card card, int free) {
        Card prev = null;
        for (Card c : getCards()) {
            if (prev != null) {
                if (free-- <= 0) {
                    return false;
                }
                if (c.isRed() == prev.isRed() || c.rank.getNumber()
                        != prev.rank.getNumber() - 1) {
                    return false;
                }
                prev = c;
            } else if (c == card) {
                prev = c;
            }
        }
        return true;
    }

    boolean movableTo(Cell from, Card card, int free) {
        /* 空のカスケードへの移動はfreeが1つ減るので再チェック */
        if (isEmpty() && !from.movableFrom(card, free - 1)) {
            return false;
        }
        if (isEmpty()) {
            return true;
        }
        Card top = top();
        return (card.isRed() != top.isRed()
                && card.rank.getNumber() == top.rank.getNumber() - 1);
    }
}

class FreeCellPanel extends GamePanel
        implements CardListener, Runnable {

    Cell[] freeCells = new Cell[4];
    Cell[] homeCells = new Cell[4];
    Cell[] cascades = new Cell[8];
    volatile long time;
    volatile Thread thread;

    public FreeCellPanel() {
        for (int i = 0; i < freeCells.length; i++) {
            freeCells[i] = new Free();
            add(freeCells[i], 30 + i * 90, 30);
        }
        for (int i = 0; i < homeCells.length; i++) {
            homeCells[i] = new Home();
            add(homeCells[i], 420 + i * 90, 30);
        }
        for (int i = 0; i < cascades.length; i++) {
            cascades[i] = new Cascade();
            add(cascades[i], 40 + i * 90, 180);
        }
    }

    /* ゲーム盤を再描画する */
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (time > 0) {
            g.setColor(Color.WHITE);
            g.drawString(String.format("経過時間 %.1f 秒",
                    time / 1000.0), 30, 20);
        }
    }

    /* 新しいゲームをスタートさせる */
    public void start() {
        if (thread != null) {
            Thread oldThread = thread;
            thread = null;
            try {
                oldThread.join();
            } catch (InterruptedException e) {
            }
        }
        thread = new Thread(this);
        thread.start();
    }

    /* カスケードにカードを配った後、経過時間を更新を続ける */
    public void run() {
        reset();
        Deck d = new Deck();
        for (Card c : d.getCards()) {
            c.setSticky(true);
        }
        d.shuffle();
        d.flip();
        add(d, 20, 620);
        int i = 0;
        Card[] cards = d.getCards();
        while (!d.isEmpty()) {
            d.pick();
        }
        d.remove();
        for (Card c : cards) {
            if (thread == null) {
                break;
            }
            c.addCardListener(this);
            c.setSpeed(5000);
            c.moveTo(cascades[i++ % cascades.length]);
            c.setSpeed(Card.DEFAULT_SPEED);
        }
        try {
            long startTime = System.currentTimeMillis();
            while (thread != null && countFree() < 12) {
                Thread.sleep(100);
                time = System.currentTimeMillis() - startTime;
                repaint();
            }
        } catch (InterruptedException e) {
        }
    }

    /* ゲームの状態をリセットする */
    public void reset() {
        for (Pile p : freeCells) {
            p.clear();
        }
        for (Pile p : homeCells) {
            p.clear();
        }
        for (Pile p : cascades) {
            p.clear();
        }
    }

    /* from の1番上のカードをホームセルに移動する
     移動できたら true を、できなかったら false を返す */
    private boolean moveHome(Cell from) {
        Card card = from.top();
        if (card != null) {
            for (Cell to : homeCells) {
                if (to.movableTo(from, card, 0)) {
                    card.moveTo(to);
                    return true;
                }
            }
        }
        return false;
    }

    /* ホームセルに移動できるカードをすべて移動する */
    public void finish() {
        boolean moved;
        do {
            moved = false;
            for (Cell c : freeCells) {
                moved |= moveHome(c);
            }
            for (Cell c : cascades) {
                moved |= moveHome(c);
            }
        } while (moved);
    }

    /* カードの一時退避場所の数を数えて戻す */
    public synchronized int countFree() {
        int free = 0;
        for (Pile p : freeCells) {
            if (p.isEmpty()) {
                free++;
            }
        }
        for (Pile p : cascades) {
            if (p.isEmpty()) {
                free++;
            }
        }
        return free;
    }

    /* カードが選択されたときに起動される */
    public boolean cardSelected(CardEvent e) {
        Cell cell = (Cell) e.getPile();
        cell.raiseAsync();
        return cell.movableFrom(e.getCard(), countFree());
    }

    /* カードのドラッグが終了するときに起動される */
    public boolean cardMoved(CardEvent e) {
        Card card = e.getCard();
        Cell from = (Cell) e.getPile();
        Cell to = (Cell) e.getDest();
        if (from == null || to == null) {
            return false;
        }
        if (to.movableTo(from, card, countFree())) {
            from.moveCardsAsyncTo(card, to);
            return true;
        }
        return false;
    }

    /* カードがダブルクリックされたときに起動される */
    public void cardPicked(CardEvent e) {
        Card card = e.getCard();
        Cell from = (Cell) e.getPile();
        if (!from.movableFrom(card, 0)) {
            new Thread() {
                public void run() {
                    finish();
                }
            }.start();
            return;
        }
        for (Cell to : homeCells) {
            if (to.movableTo(from, card, 0)) {
                card.moveAsyncTo(to);
                return;
            }
        }
    }
}

public class FreeCell implements Runnable {

    public void run() {
        JFrame frame = new JFrame("Free Cells");
        FreeCellPanel panel = new FreeCellPanel();
        frame.setContentPane(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
        panel.start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new FreeCell());
    }
}
