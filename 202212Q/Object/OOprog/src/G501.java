import javax.swing.*;

public class G501 implements Runnable  {
    public void run() {
        JFrame f = new JFrame();
        f.setVisible(true);
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G501());
    }
}
