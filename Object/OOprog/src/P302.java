import jp.ac.ryukoku.math.cards.*;

public class P302 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        Pile p = new Pile();
        f.add(d, 100, 100);
        f.add(p, 300, 100);
        d.shuffle();
        int i = 1;
        while (!d.isEmpty()) {
            Card c = d.pickUp();
            c.flip();
            if (c.suit == Suit.SPADES) {
                if(c.rank == Rank.ACE || c.rank == Rank.TEN || c.rank == Rank.JACK || c.rank == Rank.QUEEN || c.rank == Rank.KING){
                    c.moveTo(i*100,400);
                    i++;
                }else{
                    c.moveTo(300,100);
                    c.flip();
                    p.add(c);
                }
            } else {
                c.moveTo(300,100);
                c.flip();
                p.add(c);
            }
        }
    }
}
