import java.awt.*;
import javax.swing.ImageIcon;
import jp.ac.ryukoku.math.cards.*;

class G403Card extends Card {
    static ImageIcon imgIcon = new ImageIcon("card.png");
    static Image img = imgIcon.getImage();

    G403Card() {
        super();
    }

    G403Card(int no) {
        super(no);
    }

    G403Card(Suit suit, Rank rank) {
        super(suit, rank);
    }

    protected void paintComponent(Graphics g) {
        //System.out.println("paint IN");
        if (isFacedUp()) {
            //System.out.println("is faceup");
            super.paintComponent(g);
            return;
        }else{
            //System.out.println("face down");
            //System.out.print(imgIcon.getImageLoadStatus());
            if(imgIcon.getImageLoadStatus() == MediaTracker.COMPLETE){
                g.drawImage(img, 0, 0, getWidth(), getHeight(), null);
            }else{
                //System.out.println("false");
                super.paintComponent(g);
            }
        }
    }

    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        f.add(new G403Card());
    }
}
