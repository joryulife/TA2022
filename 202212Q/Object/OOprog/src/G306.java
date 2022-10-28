import java.awt.event.*;
import javax.swing.*;
import jp.ac.ryukoku.math.cards.*;

class G306 implements ActionListener, Runnable {
    GameFrame f;
    Deck d1,d2,d3;
    JButton b1,b2,b3;

    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == b1){
            d1.shuffleAsync();
        }else if(e.getSource() == b2){
            d2.shuffleAsync();
        }else if(e.getSource() == b3){
            d3.shuffleAsync();
        }
    }

    public void run() {
        f = new GameFrame();
        d1 = new Deck();
        b1 = new JButton("シャッフル");
        d2 = new Deck();
        b2 = new JButton("シャッフル");
        d3 = new Deck();
        b3 = new JButton("シャッフル");
        b1.addActionListener(this);
        d1.flip();
        b2.addActionListener(this);
        d2.flip();
        b3.addActionListener(this);
        d3.flip();
        f.add(d1,160,240);
        f.add(b1, 152, 380);
        f.add(d2,360,240);
        f.add(b2, 352, 380);
        f.add(d3,560,240);
        f.add(b3, 552, 380);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G306());
    }
}
