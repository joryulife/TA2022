import jp.ac.ryukoku.math.cards.*;

class P601 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        f.add(d, 600, 100);
        d.shuffle();
        Hand[] hands = Hand.createHands(3, 70, 400, 25, 240);
        for (int i = 0; i < Hand.CAPACITY; i++) {
            for (Hand h : hands) {
                h.draw(d);
            }
        }
    }
}
