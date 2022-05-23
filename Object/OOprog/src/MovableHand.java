public class MovableHand extends SortedHand{
    
    MovableHand(int x,int y){
        super(x, y);
    }

    MovableHand(int x,int y,boolean open){
        super(x, y, open);
    }

    void relocate(int x,int y,int deltaX){
        super.x = x;
        super.y = y;
        super.deltaX = deltaX;
        for(int i = 0;i < numCards;i++){
            cards[i].moveTo(x+deltaX*i, y);
            cards[i].raise();
        }
    }
}
