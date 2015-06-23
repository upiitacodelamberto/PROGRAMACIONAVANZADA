package u3.mygregcal.view;

import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;//PASO 1/5
import java.awt.event.WindowAdapter;//PASO 1/5
import java.awt.event.WindowEvent;
import javax.swing.JOptionPane;
import u3.mygregcal.model.Fecha;
import java.util.*;
/**
 * 
 * @author Lamberto, Adrian
 * @version 2015.06.08
 */

public class FechasGUI implements ActionListener{//PASO 2/5
    Frame F;
    MenuBar MB;
    Menu M;
    MenuItem MI;
    
    Fecha f;
    public FechasGUI(){
        F = new Frame("Fechas del calendario Gregoriano");
        F.setSize(400, 300);
        F.setMenuBar(MB = new MenuBar());
        MB.add(M = new Menu("Fecha"));
        M.add(MI = new MenuItem("Mostrar"));
        
        //f = new Fecha(Calendar.DAY_OF_MONTH, Calendar.MONTH, Calendar.YEAR);
        f = new Fecha(23, 6, 2015);
        
        f.setDyM();
        
        MI.addActionListener(this);//PASO 3/5
        F.addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent we){
            F.dispose();
            System.exit(0);
        }
        });
        
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }//End FechasGUI()

    @Override
    public void actionPerformed(ActionEvent arg0) {//PASO 4/5
        if(arg0.getActionCommand().equals("Mostrar")){//PASO 5/5
            JOptionPane.showMessageDialog(F, f);
        }
    }
    public static void main(String[] args) {
        new FechasGUI();
    }
}
