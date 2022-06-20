import java.awt.event.*;
import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G304 implements ActionListener, Runnable {
    GameFrame f;
    Deck d;
    JButton b;

    public void actionPerformed(ActionEvent e) {
        d.shuffleAsync();
    }

    public void run() {
        f = new GameFrame();
        d = new Deck();
        b = new JButton("シャッフル");
        b.addActionListener(this);
        d.flip();
        f.add(d);
        f.add(b, 352, 380);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G304());
    }
}