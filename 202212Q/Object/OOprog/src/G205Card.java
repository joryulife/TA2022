import java.awt.*;
import jp.ac.ryukoku.math.cards.*;

public class G205Card extends Card {

    G205Card() { super(); }
    G205Card(int no) { super(no); }
    G205Card(Suit s, Rank r) { super(s, r); }

    protected void paintComponent(Graphics g) {
        if (isFacedUp()) {
            /* 表の面の描画はスーパークラスのまま */
            super.paintComponent(g);
            return;
        }
        /* 背面の描画を行う */
        g.setColor(new Color(255, 255, 255,127));   // 白色
        g.fillRoundRect(0, 0, 80, 120, 7, 7);   // 角の丸い矩形
        g.setColor(new Color(150, 0, 150,127));
        g.fillRect(3, 3, 74, 114);
        g.setColor(new Color(0, 150, 0,127));
        int x[] = {77,3,77};
        int y[] = {3,117,117};
        g.fillPolygon(x,y,3);
        g.setColor(new Color(0,120,200,127));
        g.fillArc(-57,57,120,120,0,90);
        g.setColor(new Color(255,255,255,127));                // 黒色
        g.drawString("龍谷大学", 17, 108);      // 文字列
    }
}
