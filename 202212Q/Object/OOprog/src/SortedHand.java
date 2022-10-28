import jp.ac.ryukoku.math.cards.*;

/* SortedHand クラスのクラス宣言 (Hand のサブクラス) */
class SortedHand extends Hand {

    /* コンストラクタの宣言 (コンストラクタは継承されない) */
    SortedHand(int x, int y, int deltaX) {
        super(x, y, deltaX);        // スーパクラスのコンストラクタの起動
    }

    SortedHand(int x, int y) {
        super(x, y);        // スーパクラスのコンストラクタの起動
    }

    SortedHand(int x, int y,int deltaX,boolean open) {
        super(x, y,deltaX);
        super.open = open;
    }

    SortedHand(int x, int y,boolean open) {
        super(x, y);
        super.open = open;
    }

    /* このクラスのクラスメソッド priority の宣言 */
    static int priority(Card c) {
        if (c.isJoker()) {
            return c.rank.getNumber() + 52;
        }
        return (c.rank.getNumber() + 11) % 13 * 4 + (4 - c.suit.getNumber());
    }

    /* インスタンスメソッド add の再定義 */
    void add(Card c) {
        if (numCards >= CAPACITY) {
            return;
        }
        super.add(c);           // Handクラスの add の起動
        int i, last = numCards - 1;
        /* 挿入位置の決定 */
        for (i = 0; i < last; i++) {
            if (priority(c) < priority(cards[i])) {
                break;
            }
        }
        if (i == last) {
            return;
        }
        /* 挿入位置以降を右へずらす */
        c.moveTo(x + i * deltaX, y - 130);
        for (int j = last; i < j; j--) {
            cards[j] = cards[j - 1];
            cards[j].moveTo(x + j * deltaX, y);
        }
        cards[i] = c;
        c.moveTo(x + i * deltaX, y);
    }
}
