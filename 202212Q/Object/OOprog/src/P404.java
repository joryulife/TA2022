import jp.ac.ryukoku.math.cards.*;

public class P404 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        f.add(d, 100, 100);
        d.shuffle();


        Card [][] fe = new Card[4][5];
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 5;j++){
                Card c = d.pickUp();
                fe[i][j] = c;
                c.moveTo(250+j*100, 45 + i*130);
            }
        }
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 5;j++){
                fe[i][j].flip();
            }
        }
    }
}