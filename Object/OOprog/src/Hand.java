import jp.ac.ryukoku.math.cards.*;

public class Hand {
    
    int x, y; // 左端の手札の位置
    int deltaX = 100; // 隣り合った手札の x 座標の差
    int numCards; // 手札の枚数
    Card[] cards = new Card[5]; // 手札の配列

    Hand(int x,int y){
        this.x = x;
        this.y = y;
    }

    void add(Card c){
        if(numCards < cards.length){
            c.moveTo(x+numCards*deltaX,y);
            cards[numCards++] = c;
        }
    }

    void draw(Deck d){
        if(!d.isEmpty() && numCards < 5){
            Card c = d.pickUp();
            c.flip();
            add(c);
        }
    }

    void draw2(Deck d){
        if(!d.isEmpty()){
            add(d.pickUp());
        }
    }

    int count(){
        return numCards;
    }

    Card get(int i){
        if(i < 0 || numCards < i){
            return null;
        }else{
            return cards[i];
        }
    }

    void discard(int i,Pile p){
        if(i < 0 || numCards < i){
            return;
        }else{
            Card c = cards[i];
            c.moveTo(p);
            int j = count();
            int I = i;
            while(i < j-1){
                cards[i] = cards[i+1];
                cards[i].moveTo(x+i*deltaX,y);
                i++;
            }
            for(i = I;i < j;i++){
                cards[i] = cards[i+1];
                cards[i].moveTo(x+i*deltaX,y);
            }
            numCards--;
        }
    }
}
