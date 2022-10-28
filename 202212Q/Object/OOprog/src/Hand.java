import jp.ac.ryukoku.math.cards.*;

/* Hand クラスのクラス宣言 */
class Hand {
    /* このクラスのクラス変数 */
    static final int CAPACITY = 5;

    /* このクラスのインスタンス変数の宣言 */
    int x, y;                           // 左端の手札の位置
    int deltaX = 100;                   // 隣の手札との x 座標の差
    int numCards;                       // 手札の枚数
    Card[] cards = new Card[CAPACITY];  // 手札の配列
    boolean open = true;

    /* このクラスのコンストラクタの宣言*/
    Hand(int x, int y) {
        this.x = x;
        this.y = y;
    }

    Hand(int x, int y, int deltaX) {
        this(x, y);
        this.deltaX = deltaX;
    }

    Hand(int x, int y, int deltaX,boolean open){
        this(x, y, deltaX);
        this.open = open; 
    }

    Hand(int x, int y,boolean open){
        this(x,y);
        this.open = open;
    }

    static Hand[] createHands(int num, int x, int y, int dx, int shift) {
        Hand[] hands = new Hand[num];
        for (int i = 0; i < num; i++) {
            hands[i] = new Hand(x, y, dx);
            x += shift;
        }
        return hands;
    }

    static void fillHands(Hand[] hands, Deck d) {
        for (int i = 0; i < CAPACITY; i++) {
            for (Hand h : hands) {
                h.draw(d);
            }
        }
    }

    /* このクラスのインスタンスメソッド add の宣言 */
    void add(Card c) {
        if (numCards < CAPACITY) {
            c.moveTo(x + numCards * deltaX, y);
            cards[numCards++] = c;
        }
    }

    /* このクラスのインスタンスメソッド draw の宣言 */
    void draw(Deck d) {
        if (!d.isEmpty() && numCards < CAPACITY) {
            Card c = d.pickUp();
            add(c);
            if(this.open){
                c.faceUp();
            }
        }
    }

    void fill(Deck d) {
        while (!d.isEmpty() && numCards < CAPACITY) {
            draw(d);
        }
    }

    int count() {
        return numCards;
    }

    Card get(int i) {
        return (0 <= i && i < numCards) ? cards[i] : null;
    }

    void discard(int i, Pile p) {
        if (0 <= i && i < numCards) {
            cards[i].moveTo(p);
            numCards--;
            while (i < numCards) {
                cards[i] = cards[i + 1];
                cards[i].moveTo(x + i * deltaX, y);
                i++;
            }
        }
    }
}
