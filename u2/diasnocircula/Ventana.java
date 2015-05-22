/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package u2.diasnocircula;
import java.awt.Frame;
import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.event.ActionEvent;//PASO 1/5
import java.awt.event.ActionListener;//PASO 1/5
/**
 *
 * @author lamberto
 */
public class Ventana implements ActionListener{//PASO 2/5
    Frame F;
    Button B;
    Label L;
    public Ventana(){
        F = new Frame("Dias de Hoy no circula");
        F.setSize(400, 300);
        B = new Button("De clic aqui");
        F.setLayout(new FlowLayout());
        F.add(B);
        L = new Label("DIAS DE NO CIRCULA");
        F.add(L);
        B.addActionListener(this);//PASO 3/5
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }
    public void actionPerformed(ActionEvent e){//PASO 4/5
        if(e.getActionCommand().equals("De clic aqui")){//PASO 5/5
            L.setText("Aqui debera anotarse los dias que no circule el auto");
        }
    }
    public static void main(String[] args) {
        new Ventana();
    }
}
