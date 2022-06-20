import jp.ac.ryukoku.math.cards.*;

class G203 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck[] decks
            = {new MyDeck(), new Deck(), new MyDeck(1)};
        int x = 200;
        for (Deck d : decks) {
            f.add(d, x, 120);
            d.shuffle();
            x += 160;
        }
        x = 80;
        for (int i = 0; i < 5; i++) {
            for (Deck d : decks) {
                Card c = d.pickUp();
                c.moveTo(x, 400);
                if (i % 2 == 0) {
                    c.flip();
                }
                x += 40;
            }
        }
    }
}
