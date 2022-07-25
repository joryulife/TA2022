import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G701Panel extends GamePanel {
    Deck[] decks = new Deck[3];
    JButton button = new JButton("シャッフル");

    G701Panel() {
        int x = 160;
        for (int i = 0; i < decks.length; i++) {
            decks[i] = new Deck();
            decks[i].flip();
            add(decks[i], x, 240);
            x += 200;
        }
        add(button, 352, 380);
        button.addActionListener(e -> shuffleAll());
    }

    void shuffleAll() {
        Thread th = new G701Shuffle();
        th.start();
    }

    class G701Shuffle extends Thread {
        public void run() {
            for (Deck d : decks) {
                d.shuffle();
            }
        }
    }
}

class G701 implements Runnable {
    public void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(new G701Panel());
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G701());
    }
}
