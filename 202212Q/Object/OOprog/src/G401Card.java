import java.awt.*;
import javax.swing.ImageIcon;
import jp.ac.ryukoku.math.cards.*;

class G401Card extends Card {
    static Image img = new ImageIcon("card.png").getImage();

    G401Card() {
        super();
    }

    G401Card(int no) {
        super(no);
    }

    G401Card(Suit suit, Rank rank) {
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
        f.add(new G401Card());
    }
}
