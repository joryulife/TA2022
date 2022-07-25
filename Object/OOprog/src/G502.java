import java.awt.Container;
import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

public class G502 implements Runnable {
    public void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container p = f.getContentPane();
        p.add(new Card());
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G502());
    }
}
