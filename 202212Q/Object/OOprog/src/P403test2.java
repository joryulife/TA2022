import jp.ac.ryukoku.math.cards.*;

public class P403test2 {
    public static void main(String[] args){
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        Pile p = new Pile();
        f.add(d, 100, 100);
        f.add(p, 300, 100);
        d.shuffle();
        int n = 0;
        boolean [] b = new boolean[13];
        while(n < 5){
            Card c = d.pickUp();
            c.flip();
            int k = (c.getNumber()+4)%13;
            if(b[k] || k >= 5){
                c.moveTo(300,100);
                c.flip();
                p.add(c);
            }else{
                b[k] = true;
                c.moveTo(100+n*100,400);
                n++;
            }
        }
    }
}