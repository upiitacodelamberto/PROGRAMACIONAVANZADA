package ejemusodmathlib;

import java.awt.*;
import java.awt.event.*;//1/5

public class UsoDMathlib implements ActionListener {//2/5
  Frame F;
  TextField TF1, TF2, TF3;
  Button BSumar, BMultiplicar;
  static{
    System.loadLibrary("MathLibrary");
  }
  public native int addTwoNumbers(int one, int two);
  public native int multiplyTwoNumbers(int one, int two);

  public UsoDMathlib(){
    F=new Frame("Ejemplo JNI");
    F.setLayout(new BorderLayout());
    F.add(crearPanelNorte(), BorderLayout.NORTH);
    F.add(crearPanelSur(), BorderLayout.SOUTH);
    F.setSize(400,300);
    F.setLocationRelativeTo(null);

    BSumar.addActionListener(this);//3/5
    BMultiplicar.addActionListener(this);

    F.setVisible(true);
  }
  private Panel crearPanelNorte(){
    Panel P=new Panel();
    P.setLayout(new GridLayout(1,3));
    TF1=new TextField(10);P.add(TF1);
    TF2=new TextField(10);P.add(TF2);
    TF3=new TextField(10);P.add(TF3);
    return P;
  }
  private Panel crearPanelSur(){
    Panel P=new Panel();
    P.setLayout(new GridLayout(1,2));
    P.add(BSumar=new Button("SUMAR"));
    P.add(BMultiplicar=new Button("MULTIPLICAR"));
    return P;
  }
  public void actionPerformed(ActionEvent ae){//4/5
    String S=ae.getActionCommand();
    int arg1, arg2, r;
    if(S.equals("SUMAR")){
      arg1=Integer.parseInt(TF1.getText());
      arg2=Integer.parseInt(TF2.getText());
      r=addTwoNumbers(arg1, arg2);
    }
    if(S.equals("MULTIPLICAR")){
      arg1=Integer.parseInt(TF1.getText());
      arg2=Integer.parseInt(TF2.getText());
      r=multiplyTwoNumbers(arg1, arg2);
    }
  }
  public static void main(String arr[]){
    new UsoDMathlib();
  }
}//end class UsoDMathlib
