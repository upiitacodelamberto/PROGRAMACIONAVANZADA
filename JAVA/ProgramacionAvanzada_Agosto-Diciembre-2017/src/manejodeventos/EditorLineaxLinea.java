/**
 * EditorLineaxLinea.java Una clase para crear archivos de texto introdiciento
 * línea por línea (una línea de texto cada vez).
 *
 */
package manejodeventos;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.event.ActionListener;//1/5 interface ActionListener
import java.awt.event.ActionEvent;//1/5

/**
 *
 * @author Toshiba
 * @version 2017.11.15
 */
//public class EditorLineaxLinea implements WindowListener{
public class EditorLineaxLinea implements ActionListener{//2/5 interface ActionListener

    Frame F;
    TextArea TA;
    Button B;
    TextField TF;
    Panel P;
    GridLayout GL;
    BorderLayout BL;

    public EditorLineaxLinea() {
        F = new Frame("Editor Línea por Línea");
        F.setLayout(BL = new BorderLayout());
        TA = new TextArea();
        F.add(TA, BorderLayout.CENTER);
        P = _hacerPanel();
        B.addActionListener(this);//3/5 interface ActionListener
        F.add(P, BorderLayout.SOUTH);
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                F.dispose();
                System.exit(0);
            }            
        });
        TF.requestFocus();
        F.setVisible(true);
    }

    private Panel _hacerPanel() {
        Panel Presult = new Panel();
        Presult.setLayout(GL = new GridLayout(1, 2));
        Presult.add(TF = new TextField(100));
        B = new Button("AGREGAR");
        B.setMaximumSize(new Dimension(60, 25));
        Presult.add(B);
        return Presult;
    }
    
    public void actionPerformed(ActionEvent ae){//4/5 interface ActionListener
        Boolean Bool=false;
        if(ae.getSource().equals(B)){//5/5 interface ActionListener
            String S=TA.getText(),s="";
            s=(S.equals(s))?s:"\n";
            S=S+s+TF.getText();
            TA.setText(S);
            TF.requestFocus();
        }
    }

    public static void main(String[] args) {
        new EditorLineaxLinea();
    }

//    @Override
//    public void windowOpened(WindowEvent we) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
//    }
//
//    @Override
//    public void windowClosing(WindowEvent we) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
//    }
//
//    @Override
//    public void windowClosed(WindowEvent we) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
//    }
//
//    @Override
//    public void windowIconified(WindowEvent we) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
//    }
//
//    @Override
//    public void windowDeiconified(WindowEvent we) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
//    }
//
//    @Override
//    public void windowActivated(WindowEvent we) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
//    }
//
//    @Override
//    public void windowDeactivated(WindowEvent we) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
//    }
}//end class EditorLineaxLinea

