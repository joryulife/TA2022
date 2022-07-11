import java.awt.*;
import java.io.*;
import javax.imageio.ImageIO;
import jp.ac.ryukoku.math.cards.*;

class G404Card extends Card {
    static final String IMAGE_FILE_NAME = "card.png";
    static Image img;
    /* クラス初期化子 */
    static {
        try {
            img = ImageIO.read(new File(IMAGE_FILE_NAME));
        } catch (IOException e) {
            System.err.println(e.getMessage());
            System.err.println("画像ファイル "+ IMAGE_FILE_NAME + " を読み込めませんでした");
            System.exit(1);
        }
    }
    G404Card() {
        super();
    }

    G404Card(int no) {
        super(no);
    }

    G404Card(Suit suit, Rank rank) {
        super(suit, rank);
    }

    protected void paintComponent(Graphics g) {
        if (isFacedUp()) {
            super.paintComponent(g);
            return;
        }
        g.drawImage(img, 0, 0, getWidth(), getHeight(), null);
    }

    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        f.add(new G404Card());
    }
}
