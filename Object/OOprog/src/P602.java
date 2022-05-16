class P602 {
    public static void main(String[] args) {
        jp.ac.ryukoku.math.cards.GameFrame f = new jp.ac.ryukoku.math.cards.GameFrame();
        jp.ac.ryukoku.math.cards.Deck d = new jp.ac.ryukoku.math.cards.Deck(1);
        jp.ac.ryukoku.math.cards.Pile p = new jp.ac.ryukoku.math.cards.Pile();
        f.add(d);
        f.add(p, 100, 240);
        d.shuffle();
        Hand h = new Hand(160, 400);
        do {
            h.fill(d);
            int i = 0;
            while (i < h.count()) {
                jp.ac.ryukoku.math.cards.Card c = h.get(i);
                if (c.suit != jp.ac.ryukoku.math.cards.Suit.SPADES || (!c.isPictureCard()
                        && c.rank != jp.ac.ryukoku.math.cards.Rank.rankOf(10))) {
                    h.discard(i, p);
                    continue;
                }
                i++;
            }
        } while (h.count() < Hand.CAPACITY);
    }
}
