import java.awt.*;
import javax.swing.ImageIcon;
import jp.ac.ryukoku.math.cards.*;

class G402Card extends Card {
    static Image img = new ImageIcon("card.png").getImage();

    G402Card() {
        super();
    }

    G402Card(int no) {
        super(no);
    }

    G402Card(Suit suit, Rank rank) {
        super(suit, rank);
    }

    protected void paintComponent(Graphics g) {
        if (isFacedUp()) {
            super.paintComponent(g);
            return;
        }else{
        int w = getWidth();
        int h = getHeight();
        int iw = img.getWidth(null);
        int ih = img.getHeight(null);

        g.drawImage(img, 0, 0,w,h,iw,0,0,ih, null);
        }
    }

    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        G402Card c = new G402Card();
        f.add(c);
        c.flipAsync();
        c.flipAsync();
    }
}
