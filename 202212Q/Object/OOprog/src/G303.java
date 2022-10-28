import java.awt.event.*;
import javax.swing.JButton;
import jp.ac.ryukoku.math.cards.*;

class G303 implements ActionListener {
    GameFrame f;
    Deck d;
    JButton b;

    G303() {
        f = new GameFrame();
        d = new Deck();
        b = new JButton("シャッフル");
        b.addActionListener(this);
        d.flip();
        f.add(d);
        f.add(b, 352, 380);
    }

    public void actionPerformed(ActionEvent e) {
        d.shuffleAsync();
    }

    public static void main(String[] args) {
        new G303();
    }
}