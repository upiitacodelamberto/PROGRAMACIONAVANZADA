package herenciayreutilizacion;
import java.awt.Dialog;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Frame;
public class MyDialog{
Dialog D;
Checkbox CB;
Button BC, BA;
public MyDialog(String puesto[]){
  D=new Dialog(new Frame(),"Tipo de elección");
  CB=new Checkbox();
  BC=new Button("Cancelar");
  BA=new Button("Aceptar");
 // GridBagLayout
  D.setSize(300,200);
  D.setVisible(true);
  D.setLocationRelativeTo(null);
  
}
public static void main(String[] args){
new MyDialog(args);
}
}

