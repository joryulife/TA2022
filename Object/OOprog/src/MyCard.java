import java.awt.*;
import jp.ac.ryukoku.math.cards.*;

class MyCard extends Card {
    static Color[] logoColors = {
        new Color(150, 0, 150),     // 紫色
        new Color(0, 150, 0),       // 深緑色
        new Color(0, 120, 200)      // 空色
    };
    static int[][] logoXs = {
        {13, 13, 26, 26}, {43, 43, 56, 56}, {27, 57, 73, 42}
    };
    static int[][] logoYs = {
        {37, 87, 87, 50}, {17, 50, 50, 17}, {50, 87, 87, 50}
    };

    MyCard() { super(); }
    MyCard(int no) { super(no); }
    MyCard(Suit s, Rank r) { super(s, r); }

    protected void paintComponent(Graphics g) {
        if (isFacedUp()) {
            /* 表の面の描画はスーパークラスのまま */
            super.paintComponent(g);
            return;
        }
        /* 背面の描画を行う */
        g.setColor(new Color(255, 255, 255));   // 白色
        g.fillRoundRect(0, 0, 80, 120, 7, 7);   // 角の丸い矩形
        g.setColor(new Color(200, 200, 200));   // 明るい灰色
        g.fillRoundRect(3, 3, 74, 114, 7, 7);   // 角の丸い矩形
        for (int i = 0; i < logoColors.length; i++) {
            /* ロゴマークの3つの四角形を塗り潰す */
            g.setColor(logoColors[i]);
            g.fillPolygon(logoXs[i], logoYs[i], logoXs[i].length);
        }
        g.setColor(Color.BLACK);                // 黒色
        g.drawString("龍谷大学", 17, 108);      // 文字列
    }
}
