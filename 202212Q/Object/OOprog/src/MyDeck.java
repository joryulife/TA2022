import jp.ac.ryukoku.math.cards.*;

public class MyDeck extends Deck {
    
    MyDeck(){
        super();
    }
    MyDeck(int n){
        super(n);
    }
    protected MyCard makeCard(int no){
        return new MyCard(no);
    }

}
