import jp.ac.ryukoku.math.cards.*;

public class P306 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Card c1 = new Card(Suit.HEARTS,Rank.ACE);
        Card c2 = new Card(Suit.HEARTS,Rank.DEUCE);
        Card c3 = new Card(Suit.HEARTS,Rank.THREE);
        Card c4 = new Card(Suit.HEARTS,Rank.FOUR);
        f.add(c1,100,100);
        f.add(c2,200,100);
        f.add(c3,300,100);
        f.add(c4,400,100);
        c4 = c3;
        c1 = c4;
        c2 = c3;
        c1.flip();
        c2.flip();
        c3.flip();
        c4.flip();
    }
}