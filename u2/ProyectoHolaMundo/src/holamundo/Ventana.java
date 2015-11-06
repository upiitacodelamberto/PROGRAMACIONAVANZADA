package holamundo;
import java.awt.*;
//import java.awt.event.*;

public class Ventana {
  Frame F;
  Button B1, B2, B3;
  public Ventana(){
	  F=new Frame("Ventana");
	  F.setLayout(new FlowLayout());
	  F.add(B1=new Button("Boton 1"));
	  F.add(B2=new Button("Boton 2"));
	  F.add(B3=new Button("Boton 3"));
	  
	  F.setSize(600, 400);
	  F.setVisible(true);
  }
  public static void main(String arr[]){
	  new Ventana();
  }
}
