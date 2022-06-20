import java.awt.event.*;
import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G307 implements Runnable {
    GameFrame f;
    Deck d1,d2,d3;
    JButton b1,b2,b3;
    ActionListener l1,l2,l3;

    public void run() {
        f = new GameFrame();

        d1 = new Deck();
        l1 = new ShuffleButtonHandler(d1);
        b1 = new JButton("シャッフル");
        b1.addActionListener(l1);
        
        d2 = new Deck();
        l2 = new ShuffleButtonHandler(d2);
        b2 = new JButton("シャッフル");
        b2.addActionListener(l2);

        d3 = new Deck();
        l3 = new ShuffleButtonHandler(d3);
        b3 = new JButton("シャッフル");
        b3.addActionListener(l3);
        
        d1.flip();
        d2.flip();
        d3.flip();
        f.add(d1,160,240);
        f.add(b1, 152, 380);
        f.add(d2,360,240);
        f.add(b2, 352, 380);
        f.add(d3,560,240);
        f.add(b3, 552, 380);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G307());
    }
}
