import jp.ac.ryukoku.math.cards.*;

public class G405 {
    public static void main(String[] args) {
        GameFrame f = new GameFrame();
        int x = 60;
        for (String s : args) {
            int suit;
            int rank;
            Card c;
            try{
                suit = "SHDC".indexOf(s.substring(0, 1)) + 1;
                rank = Integer.parseInt(s.substring(1)); 
                c = new Card(Suit.suitOf(suit), Rank.rankOf(rank));
            } catch (NumberFormatException e){
                c = new Card();
            }
            f.add(c, x, 240);
            c.faceUp();
            x += 100;
            
        }
    }
}
