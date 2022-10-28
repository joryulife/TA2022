import java.awt.Container;
import javax.swing.*;

public class G504 implements Runnable {
    public void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container p = f.getContentPane();
        FreeCellPanel freeCell = new FreeCellPanel();
        p.add(freeCell);
        f.pack();
        f.setVisible(true);
        freeCell.start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G504());
    }
}
