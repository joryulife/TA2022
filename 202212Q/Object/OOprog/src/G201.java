import jp.ac.ryukoku.math.cards.*;

class G201 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        f.add(new MyCard(Suit.HEARTS, Rank.KING), 400, 300);
        f.add(new MyCard());
    }
}
