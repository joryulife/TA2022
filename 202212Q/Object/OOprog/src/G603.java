import javax.swing.*;
class G603 {
    public static void main(String[] args) {
        //oinvokeLaterの引数にラムダ式を入れる
        SwingUtilities.invokeLater(() -> {  //Runnableクラスのrun()には引数がないので「() -> {...}」の形になる(eとかいらない)
                final JFrame f = new JFrame();
                f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                f.add(new G603Panel());
                f.pack();
                f.setVisible(true);
            });
    }
}
