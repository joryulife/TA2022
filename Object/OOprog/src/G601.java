import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G601Panel extends GamePanel {
    Deck deck = new Deck();
    JButton button = new JButton("シャッフル");

    G601Panel() {
        deck.flip();
        add(deck);
        add(button, 352, 380);
        button.addActionListener(new ShuffleButtonHandler(deck));
    }
}

class G601 implements Runnable {
    public void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(new G601Panel());
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G601());
    }
}
