import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G601Panel extends GamePanel{
    JButton button = new JButton("シャッフル");

    G601Panel() {
        final Deck deck = new Deck();
        deck.flip();
        add(deck);
        add(button, 352, 380);
        button.addActionListener(e -> deck.shuffleAsync());
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
