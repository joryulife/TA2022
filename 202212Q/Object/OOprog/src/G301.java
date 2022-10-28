import java.awt.event.ActionListener;
import javax.swing.JButton;
import jp.ac.ryukoku.math.cards.*;

class G301 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        ActionListener l = new ShuffleButtonHandler(d);
        JButton b = new JButton("シャッフル");
        b.addActionListener(l);
        d.flip();
        f.add(d);
        f.add(b, 352, 380);
    }
}