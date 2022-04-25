import jp.ac.ryukoku.math.cards.*;

class P203 {
    public static void main(String[] args) {
        GameFrame f;                            // 変数 f の宣言
        Card c1, c2;                            // 変数 c1 と c2 の宣言
        f = new GameFrame();                    // GemeFrame のインスタンスを生成 (ゲーム盤)
        c1 = new Card(Suit.HEARTS, Rank.ACE);   // Card のインスタンスを生成 (ハートのエース)
        c2 = new Card(Suit.SPADES, Rank.JACK);  // Card のインスタンスを生成 (スペードのジャック)
        f.add(c1);                              // ハートのエースをゲームへ追加
        f.add(c2);                              // スペードのジャックをゲーム盤へ追加
        c2.moveTo(300, 400);                    // スペードのジャックを (300, 400) へ移動
        c2.flip();                              // スペードのジャックを裏返す
        c1.moveTo(400, 400);                    // ハートのエースを (400, 400) へ移動
        c1.flip();                              // ハートのエースをを裏返す
    }
}
