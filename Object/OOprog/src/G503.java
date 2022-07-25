import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

public class G503 implements Runnable, ActionListener {

    JMenuItem flip = new JMenuItem("裏返す");
    JMenuItem quit = new JMenuItem("終了");
    Card card = new Card();

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == flip) {
            card.flipAsync();
        } else {
            System.exit(0);
        }
    }

    public void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        flip.addActionListener(this);  // JMenuItem に actionListener を登録
        quit.addActionListener(this);  // JMenuItem に actionListener を登録
        JMenuBar menuBar = new JMenuBar();      // メニューバーを作成
        JMenu menu = new JMenu("メニュー");     // メニューを作成
        menu.add(flip);                         // メニュー項目を追加
        menu.add(quit);                         // メニュー項目を追加
        menuBar.add(menu);            // メニューをメニューバーに追加
        f.setJMenuBar(menuBar);       // メニューバーを JFrame に追加
        f.getContentPane().add(card);
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G503());
    }
}
