import jp.ac.ryukoku.math.cards.*;

class P502 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck(1);
        Pile p = new Pile();
        f.add(d);
        f.add(p, 100, 240);
        d.shuffle();
        Hand h = new Hand(160, 400);
        do {
            while (h.count() < 5) {
                h.draw(d);
            }
            int i = 0;
            while (i < h.count()) {
                if (!h.get(i).isJoker() && h.get(i).rank.getNumber() != 1) {
                    h.discard(i, p);
                    continue;
                }
                i++;
            }
        } while (h.count() < 5);
    }
}