/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui2;

//import java.awt.Button;
//import java.awt.FlowLayout;
//import java.awt.Frame;
//import java.awt.GridBagLayout;
//import java.awt.event.WindowAdapter;
//import java.awt.event.WindowEvent;
import java.awt.*;   /*Frame,*/
import java.awt.event.*;
/**
 *
 * @author Sala1
 */
public class GUIgridlayout {
    Frame F;
    Button B1,B2,B3,B4,B5,B6,B7,B8,B9;
    public GUIgridlayout(){
        F=new Frame("Interfaz grafica 1");
        F.setLayout(new GridLayout(3, 3));
        B1=new Button("BOTON 1");
        B2=new Button("BOTON 2");
        B3=new Button("BOTON 3");
        B4=new Button("BOTON 4");
        B5=new Button("BOTON 5");
        B6=new Button("BOTON 6");
        F.add(B1);
        F.add(B2);
        F.add(B3);
        F.add(B4);
        F.add(B5);
        F.add(B6);
        F.add(B7=new Button("BOTON 7"));
        F.add(B8=new Button("BOTON 8"));
        F.add(B9=new Button("BOTON 9"));
        F.addWindowListener(new WindowAdapter(){
          public void windowClosing(WindowEvent e){
              F.dispose();/*Liberar recursos*/
              System.exit(0);
          }
        });
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }//end GUIgridlayout()
    public static void main(String[] args) {
        new GUIgridlayout();
    }//end main()
    
}//end class GUIgridlayout
