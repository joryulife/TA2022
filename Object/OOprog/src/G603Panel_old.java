import java.awt.event.*;
import jp.ac.ryukoku.math.cards.*;
class G603Panel_old extends GamePanel implements MouseListener {
    Card card = new Card();
    G603Panel_old() {
        add(card);
        addMouseListener(this);
    }
    public void mousePressed(MouseEvent e) {
        card.moveAsyncTo(e.getX() - card.getWidth() / 2,
        e.getY() - card.getHeight() / 2);
    }
    public void mouseReleased(MouseEvent e) { }
    public void mouseClicked(MouseEvent e) { }
    public void mouseEntered(MouseEvent e) { }
    public void mouseExited(MouseEvent e) { }
}
