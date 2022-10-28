import java.awt.event.*;
import jp.ac.ryukoku.math.cards.*;
class G603Panel extends GamePanel {
    //G603Panel内でstaticではないサブクラスとしてCardMoverクラスを定義する
    class CardMover implements MouseListener {//MouseListenerの実装箱のクラスに移す
        public void mousePressed(MouseEvent e) {//mousePressed, mouseReleased, mouseClicked, mouseEnterd, mouseExistedはCardMoverクラス内で定義する
            card.moveAsyncTo(e.getX() - card.getWidth() / 2,
            e.getY() - card.getHeight() / 2);
        }
        public void mouseReleased(MouseEvent e) { }
        public void mouseClicked(MouseEvent e) { }
        public void mouseEntered(MouseEvent e) { }
        public void mouseExited(MouseEvent e) { }
    }

    Card card = new Card();
    G603Panel() {
        add(card);
        addMouseListener(new CardMover());//staticではないサブクラスだから引数(card)なしでも自動で関連づく(6-5参照)
    }
}
