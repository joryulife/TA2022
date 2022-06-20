import jp.ac.ryukoku.math.cards.*;

class G202 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        f.add(new G205Card(Suit.HEARTS, Rank.KING), 400, 300);
        f.add(new G205Card());
    }
}
