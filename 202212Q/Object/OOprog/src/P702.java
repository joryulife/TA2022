import jp.ac.ryukoku.math.cards.*;

class P702 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        f.add(d);
        d.shuffle();
        Hand[] hands = {
            new SortedHand(160, 400),
            new SortedHand(160, 80, false)
        };
        Hand.fillHands(hands, d);
    }
}
