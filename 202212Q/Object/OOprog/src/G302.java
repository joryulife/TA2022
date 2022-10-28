import java.awt.event.*;
import javax.swing.JButton;
import jp.ac.ryukoku.math.cards.*;

class G302 implements ActionListener {
    Pile p;

    G302(Pile p) {
        this.p = p;
    }

    public void actionPerformed(ActionEvent e) {
        p.shuffleAsync();
    }

    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        ActionListener l = new G302(d);
        JButton b = new JButton("シャッフル");
        b.addActionListener(l);
        d.flip();
        f.add(d);
        f.add(b, 352, 380);
    }
}