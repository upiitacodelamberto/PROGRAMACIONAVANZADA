package holamundo;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.GridLayout;

public class Ventana1 {
	  Frame F;
	  Button B1, B2, B3, B4;
	  public Ventana1(){
		  F=new Frame("Ventana");
		  F.setLayout(new GridLayout(2,2));
		  F.add(B1=new Button("Boton 1"));
		  F.add(B2=new Button("Boton 2"));
		  F.add(B3=new Button("Boton 3"));
		  F.add(B3=new Button("Boton 4"));
		  
		  F.setSize(600, 400);
		  F.setVisible(true);
	  }
	  public static void main(String arr[]){
		  new Ventana1();
	  }
}
