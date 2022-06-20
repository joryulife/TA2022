import java.awt.event.*;
import jp.ac.ryukoku.math.cards.Pile;

class ShuffleButtonHandler implements ActionListener {

    Pile p;
    ShuffleButtonHandler(Pile p) {
        this.p = p;
    }
    public void actionPerformed (ActionEvent e) {
        p.shuffleAsync();
    }
}