import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G702Target extends Pile {
    G702Target() {
        super(12, 0);
    }

    boolean tryToAdd(Pile from, Card c) {
        synchronized (this) {
            int num = c.rank.getNumber();
            Card t = top();
            if (t == null || t.rank.getNumber() == num - 1|| t.rank.getNumber() == num + 1) {
                
                from.remove(c);
                c.moveTo(this);
                return true;
            }
            return false;
        }
    }
}

class G702 extends GameFrame implements Runnable {
    G702Target target;

    public void run() {
        Pile reds = new Pile(25, 0);
        Pile blacks = new Pile(25, 0);
        target = new G702Target();
        Deck d = new Deck();
        d.shuffle();
        d.flip();
        while (!d.isEmpty()) {
            Card c = d.pick();
            c.moveTo(c.isRed() ? reds : blacks);
        }
        add(reds, 45, 60);
        add(blacks, 45, 420);
        add(target, 45, 240);
        startJob(reds);
        startJob(blacks);
    }

    void startJob(final Pile from) {
        new Thread(() -> {
            while (!from.isEmpty()) {
                for (Card c : from.getCards()) {
                    if (target.tryToAdd(from, c)) {
                        break;
                    }
                }
            }
        }).start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G702());
    }
}
