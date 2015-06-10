//https://github.com/upiitacodelamberto/programacionavanzadamarzojulio2015
package programacionavanzadamarzojulio2015.u2.dnc;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.Button;
//import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.TextField;
import java.awt.TextArea;
import java.awt.event.ActionEvent;//paso 1 de 5
import java.awt.event.ActionListener;//PASO 1/5
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;//paso 1/5
import javax.swing.JOptionPane;

/**
 *
 * @author Sala1
 */
public class ventana implements ActionListener, WindowListener {//PASO 2/5

    Frame F;
    Button B, B1;
    Button BNorth, BSouth, BEast, BWest, BCenter;
    TextField TF;
    TextArea TA;
    Label L;
    MenuBar MB;
    Menu M;
    MenuItem MI;
    SetOfInts SOI;
    String placa[] = {"131-SMB", "596-JBA", "433-DFG"};

    public ventana() {
        F = new Frame("Dias de Hoy no circula");
        F.setMenuBar(MB = new MenuBar());//Agregamos una barra de menu
        MB.add(M = new Menu("Placa"));
        M.add(MI = new MenuItem("Buscar"));
        MI.addActionListener(this);//PASO 3/5 para el MenuItem MI

        F.addWindowListener(this);//Paso 3/5 de WindowListener
        F.setSize(400, 300);
        B = new Button("da click aqui");
        F.setLayout(new BorderLayout());
        // BNorth = new Button("NORTE");
        TF = new TextField(10);
        B1 = new Button("Dias de no circular");
        F.add(CreaPanelNorte(), BorderLayout.NORTH);
        TA = new TextArea();
        F.add(TA, BorderLayout.CENTER);
        //BSouth = new Button("SUR");
        //F.add(BSouth, BorderLayout.SOUTH);
        //BWest = new Button("Oeste");
        //F.add(BWest, BorderLayout.WEST);
        //BCenter = new Button("CENTRO");
        //  F.add(BCenter, BorderLayout.CENTER);
        // BEast = new Button("ESTE");
        //F.add(BEast, BorderLayout.EAST);
        //F.add(B);
        L = new Label("Dias que no circula");
        //F.add(L);
        //B1 = new Button("arergar");
        //F.add(B1);
        //TF = new TextField(10);
        //F.add(TF);
        B.addActionListener(this);//3 de 5
        B1.addActionListener(this);//PASO 3/5 (Boton B1
        SOI = new SetOfInts();
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }

    Panel CreaPanelNorte() {
        Panel P = new Panel();
        P.setLayout(new GridLayout(1, 2));
        TF = new TextField(10);
        P.add(TF);
        P.add(B1);
        return P;
    }

    public void actionPerformed(ActionEvent e) {//4 de 5
        String s;
        boolean b = false;
        if (e.getActionCommand().equals("de click aqui")) {
            L.setText("Aqui debera anotarse los dias que no circule el auto");
        }
        if (e.getActionCommand().equals("agregar")) {
            SOI.add(Integer.parseInt(TF.getText()));
            TA.setText(SOI.toString());
        }
        if (e.getSource().equals(MI)) {//PASO 5/5 para el MenuItem MI
            s = JOptionPane.showInputDialog("Placa a buscar:");
            for (int i = 0; i < placa.length; ++i) {
                if (s.equals(placa[i])) {
                    b = true;
                    break;
                }
            }
            if (b) {
                JOptionPane.showMessageDialog(F, "La placa si existe!!");
                TF.setText(s);
            }else JOptionPane.showMessageDialog(F, "La placa no existe!!");
            b = false;
        }
        if(e.getActionCommand().equals("Dias de no circular")){
            TA.setText("Aqui debera anotarse los dias que no circule el auto");
        }
    }

    public static void main(String[] args) {
        new ventana();
    }

    //Paso 4/5 de WindowListener
    @Override
    public void windowOpened(WindowEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void windowClosing(WindowEvent e) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        F.dispose();
        System.exit(0);
    }

    @Override
    public void windowClosed(WindowEvent e) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void windowIconified(WindowEvent e) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void windowDeiconified(WindowEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void windowActivated(WindowEvent e) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        System.out.println("La ventana esta activada");
//        JOptionPane.showMessageDialog(null, "usted activo la ventana" + "la aplicacion");
    }

    @Override
    public void windowDeactivated(WindowEvent e) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
