/*

 */
package pa00;

import java.util.Scanner;
import java.awt.Frame;
import java.awt.Label;
import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
/**
 *
 * @author Toshiba
 */
class HolaMundo {
    static int intA;
    Frame F;
    Button B;
    Label L;
    public HolaMundo(){
        F=new Frame("HolaMundo.class");
        F.setLayout(new FlowLayout());
        F.add(B=new Button("Botón"));
        F.add(L=new Label("Hola Mundo GUI!!!"));
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent we){
                F.dispose();
                System.exit(0);
            }
        });
        
        F.setVisible(true);
    }
    public static void main(String[] args) {
        System.out.println("Hola Mundo JAVA JAVA DOOO!!!");
        System.out.print("Teclea un entero: ");
        Scanner scanner=new Scanner(System.in);
        intA=scanner.nextInt();
        for(int i=31;i>=0;i--){
            System.out.printf("%d",(intA>>i)&0x1);
        }
        new HolaMundo();
    }
}
