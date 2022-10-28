import jp.ac.ryukoku.math.cards.*;

class P703 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        f.add(d);
        d.shuffle();
        MovableHand[] hands = {
            new MovableHand(160, 400),
            new MovableHand(160, 80, false)
        };
        Hand.fillHands(hands, d);
        for (MovableHand h : hands) {
            h.relocate(h.x + 100, h.y, 50);
        }
    }
}
