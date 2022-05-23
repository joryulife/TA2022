import jp.ac.ryukoku.math.cards.*;

class P701 {

    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        f.add(d);
        d.shuffle();
        Hand h = new SortedHand(160, 400);
        for (int i = 0; i < Hand.CAPACITY; i++) {
            h.draw(d);
        }
    }
}
