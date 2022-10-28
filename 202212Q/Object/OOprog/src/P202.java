import jp.ac.ryukoku.math.cards.*;

class P202 {

    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();            // デッキ(カード1式の山)を生成
        f.add(d);                       // ゲーム盤に追加
        d.shuffle();                    // デッキをシャッフル
        for (int i = 0; i < 5; i++) {
            Card c = d.pickUp();        // デッキから1枚カードを引く
            c.moveTo(i * 100 + 160, 400); // 引いたカードを移動
            c.flip();                   // 移動したカードをめくる
        }
    }
}
