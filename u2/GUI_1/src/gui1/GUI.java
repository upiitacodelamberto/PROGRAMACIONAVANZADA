/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui1;
import java.awt.*;   /*Frame,*/
import java.awt.event.*;
/**
 *
 * @author Sala1
 */
public class GUI {
    Frame F;
    Button B1,B2,B3;
    
    /*Constructor por defecto*/
    public GUI(){
        F=new Frame("Interfaz grafica 1");
        F.setLayout(new FlowLayout());
        B1=new Button("BOTON 1");
        B2=new Button("BOTON 2");
        B3=new Button("BOTON 3");
        F.add(B1);
        F.add(B2);
        F.add(B3);
        F.addWindowListener(new WindowAdapter(){
          public void windowClosing(WindowEvent e){
              F.dispose();/*Liberar recursos*/
              System.exit(0);
          }
        });
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }
    public static void main(String[] args) {
        new GUI();
    }
}//end class GUI
