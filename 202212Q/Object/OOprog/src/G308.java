import javax.swing.SwingUtilities;
import jp.ac.ryukoku.math.cards.*;

class G308 implements CardListener, Runnable {
    GameFrame f = new GameFrame();
    Pile p1 = new Pile();
    Pile p2 = new Pile();
    Deck d = new Deck(2);

    public boolean cardSelected(CardEvent e) {
        if(e.getCard().isFacedDown()){
            return false;
        }
        return true;
    }

    public boolean cardMoved(CardEvent e) {
        Card card = e.getCard();
        Pile from = e.getPile();
        Pile to = e.getDest();
        if (to == null || from == null || from == to|| from.top() != card) {
            return false;
        }
        Card top = to.top();
        if (top == null || ((card.isJoker() || top.isJoker() || top.isRed() == card.isRed()) && top.isFacedUp())) {
            card.moveAsyncTo(to);
            return true;
        }
        return false;
    }

    public void cardPicked(CardEvent e) {
        e.getCard().flip();
    }

    public void run() {
        for (Card c : d.getCards()) {
            c.addCardListener(this);
        }
        d.shuffle();
        d.flip();
        f.add(d);
        f.add(p1, 300, 400);
        f.add(p2, 420, 400);
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G308());
    }
}
