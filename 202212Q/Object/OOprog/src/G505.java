//G503からの変更が前提
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class G505 implements Runnable, ActionListener{

    JMenuItem jmi_start = new JMenuItem("新しいゲーム");    //メニュー内のアイテムを定義
    JMenuItem jmi_exit = new JMenuItem("終了");    //メニュー内のアイテムを定義
    FreeCellPanel freeCell = new FreeCellPanel();   //すぐ下で使うからここで定義に変更

    public void actionPerformed(ActionEvent e) {    //メニューがクリックされた時のイベントハンドラ
        if (e.getSource() == jmi_start) {   //メニュー内のスタートが押された時
            freeCell.start();
        }
        else {  //if(e.getSource() == jmi_exit) メニュー内の終了が押された時
            System.exit(0); //メニューで「終了」がクリックされたら終わる
        }
    }

    public void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container p = f.getContentPane();

        jmi_start.addActionListener(this);  //JMenuItemにactionListenerを登録1
        jmi_exit.addActionListener(this);   //JMenuItemにactionListenerを登録2
        //FreeCellPanel freeCell = new FreeCellPanel();   //定義位置変更
        JMenuBar jmb = new JMenuBar();  //メニューバーを作成
        JMenu jm = new JMenu("フリーセル");   //メニュー作成
        jm.add(jmi_start);  //メニュー項目を追加1
        jm.add(jmi_exit);   //メニュー項目を追加2
        jmb.add(jm);    //メニューをメニューバーに追加
        f.setJMenuBar(jmb); //メニューバーをJFrameに追加

        p.add(freeCell);
        f.pack();
        f.setVisible(true);
        //freeCell.start();   メニュー内のスタートが押されてから始まるようにここの文を削除
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new G505());
    }
}
