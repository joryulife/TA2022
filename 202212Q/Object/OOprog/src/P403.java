import jp.ac.ryukoku.math.cards.*;
import java.util.*;

public class P403 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        Deck d = new Deck();
        Pile p = new Pile();
        f.add(d, 100, 100);
        f.add(p, 300, 100);
        d.shuffle();


        ArrayList<Integer> list = new ArrayList<Integer>(Arrays.asList(0,9,10,11,12));
        int j = 0;
        Outer:
        while (!d.isEmpty()) {
            Card c = d.pickUp();
            c.flip();
            int n = c.getNumber();

            /*if(n == 52 && n == 53){
                continue;
            }*/

            int a = n%13;
            for(int i = 0;i < list.size();i++){
                if(list.get(i).equals(a)){
                    c.moveTo(100+j*100,400);
                    j++;
                    list.remove(i);
                    continue Outer;
                }
            }
            
            c.moveTo(300,100);
            c.flip();
            p.add(c);
        }
    }
}
