/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzadamarzojulio2015.u2.diasnocircula;
import java.awt.Frame;
import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;//PASO 1/5
import java.awt.event.ActionListener;//PASO 1/5
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;//PASO 1/5
import javax.swing.JOptionPane;
/**
 *
 * @author lamberto
 */
public class Ventana implements ActionListener, WindowListener{//PASO 2/5
    Frame F;
    Button B, B1;
    Label L;
    TextField TF;
    SetOfInts SOI;
    public Ventana(){
        F = new Frame("Dias de Hoy no circula");
        F.addWindowListener(this);//PASO 3/5 de WindowListener
        F.setSize(400, 300);
        B = new Button("De clic aqui");
        F.setLayout(new FlowLayout());
        F.add(B);
        L = new Label("DIAS DE NO CIRCULA");
        F.add(L);
        B1 = new Button("AGREGAR");
        F.add(B1);
        TF = new TextField(10);
        F.add(TF);
        B.addActionListener(this);//PASO 3/5
        B1.addActionListener(this);//PASO 3/5 (Boton B1)
        SOI = new SetOfInts();
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }
    public void actionPerformed(ActionEvent e){//PASO 4/5
        if(e.getActionCommand().equals("De clic aqui")){//PASO 5/5
//            L.setText("Aqui debera anotarse los dias que no circule el auto");
            JOptionPane.showMessageDialog(F, SOI);
        }
        if(e.getActionCommand().equals("AGREGAR")){
            SOI.add(Integer.parseInt(TF.getText()));
        }
    }
    public static void main(String[] args) {
        new Ventana();
    }

//    PASO 4/5 del WindowListener
    @Override
    public void windowOpened(WindowEvent arg0) {
//        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void windowClosing(WindowEvent arg0) {
//        throw new UnsupportedOperationException("Not supported yet.");
        F.dispose();
        System.exit(0);
    }

    @Override
    public void windowClosed(WindowEvent arg0) {
//        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void windowIconified(WindowEvent arg0) {
//        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void windowDeiconified(WindowEvent arg0) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void windowActivated(WindowEvent arg0) {
//        throw new UnsupportedOperationException("Not supported yet.");
        System.out.println("La ventana esta activada");
//        JOptionPane.showMessageDialog(null, "Uste acaba de activar la ventana de "
//                + "la aplicaciom");
    }

    @Override
    public void windowDeactivated(WindowEvent arg0) {
//        throw new UnsupportedOperationException("Not supported yet.");
    }
}
