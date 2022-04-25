import jp.ac.ryukoku.math.cards.*;

public class P303 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        Pile p = new Pile();
        f.add(d, 420, 200);
        f.add(p, 300, 200);
        d.shuffle();
        Card c = d.pickUp();
        c.flip();
        Rank tempRank = c.rank;
        Suit tempSuit = c.suit;
        c.pause(3000);
        c.flip();
        d.add(c);
        d.shuffle();

        while (!d.isEmpty()) {
            Card c2 = d.pickUp();
            c2.flip();
            c2.moveTo(300,200);
            p.add(c2);
            if (c2.rank == tempRank && c2.suit == tempSuit) {
                break;
            }
        }
    }
}
