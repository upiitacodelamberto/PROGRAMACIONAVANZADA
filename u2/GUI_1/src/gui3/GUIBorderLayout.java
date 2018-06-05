/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui3;
import java.awt.*;
import java.awt.event.*;
/**
 *
 * @author Sala1
 */
public class GUIBorderLayout {
    Frame F;
    Button BNorte,BSur,BEste,BOeste,BCentro;
    public GUIBorderLayout(){
        F=new Frame("Interfaz grafica 3");
        F.setLayout(new BorderLayout());
        BNorte=new Button("NORTE");
        BSur=new Button("SUR");
        BEste=new Button("ESTE");
        BOeste=new Button("OESTE");
        BCentro=new Button("CENTRO");
        F.add(BNorte, BorderLayout.NORTH);
        F.add(BOeste,BorderLayout.WEST);
        F.add(BCentro, BorderLayout.CENTER);
        F.add(BEste, BorderLayout.EAST);
        F.add(BSur,BorderLayout.SOUTH);
        
        F.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent evt){
                F.dispose();
                System.exit(0);
            }
        });
        
        F.setSize(400,300);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }//end Constructor
    public static void main(String[] args) {
        new GUIBorderLayout();
    }//end main()
    
}//end class GUIBorderLayout
