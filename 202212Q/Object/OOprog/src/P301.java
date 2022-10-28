import jp.ac.ryukoku.math.cards.*;

class P301 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        Pile reds = new Pile();         // ハートとダイヤを集める山
        Pile blacks = new Pile();       // スペードとクラブを集める山
        f.add(d, 100, 100);
        f.add(blacks, 510, 400);
        f.add(reds, 210, 400);
        d.shuffle();
        while (d.count() > 0) {
            Card c = d.pickUp();
            c.flip();
            /* カードのインスタンス変数 suit を調べる */
            if (c.suit == Suit.HEARTS || c.suit == Suit.DIAMONDS) {
                c.moveTo(reds);
            } else {
                c.moveTo(blacks);
            }
        }
    }
}