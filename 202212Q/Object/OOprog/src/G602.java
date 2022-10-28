import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G602Panel extends GamePanel{
    JButton button1 = new JButton("シャッフル");
    JButton button2 = new JButton("シャッフル");
    JButton button3 = new JButton("シャッフル");

    G602Panel() { //G602Panelインスタンス生成するときに3つそれぞれやってやれ精神
        final Deck deck1 = new Deck();//インスタンス変数で覚えてるから↓
        final Deck deck2 = new Deck();
        final Deck deck3 = new Deck();
        deck1.flip(); deck2.flip(); deck3.flip();
        add(deck1, 160, 240); add(deck2, 360, 240); add(deck3, 560, 240);
        add(button1, 152, 380);add(button2, 352, 380);add(button3, 552, 380);
        button1.addActionListener(e -> deck1.shuffleAsync());//(続き)ここで区別しながらそれぞれのdeckに対してシャッフルできるってわけ
        button2.addActionListener(e -> deck2.shuffleAsync());
        button3.addActionListener(e -> deck3.shuffleAsync());
    }
}

class G602 implements Runnable {
    public void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(new G602Panel());
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G602());
    }
}
