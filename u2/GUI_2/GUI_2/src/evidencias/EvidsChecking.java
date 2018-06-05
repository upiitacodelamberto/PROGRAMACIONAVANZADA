/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package evidencias;
import java.awt.*;
import java.awt.event.*;// 1/5
/**
 *
 * @author Sala1
 */
public class EvidsChecking implements ActionListener{// 2/5
    Frame F;
    Panel P;
    TextField TF1,TF2;
    Button BotonAgregarEvid;
    TextArea TA;
    MenuBar MB;
    Menu M,M1;
    MenuItem MIAbrir,MISalir;
    public EvidsChecking(){
        F=new Frame("Evidencias de Discentes");
        F.setMenuBar(MB=new MenuBar());
        M=new Menu("Archivo");
        MB.add(M);M1=new Menu("OTRO");MB.add(M1);
        MIAbrir=new MenuItem("Abrir");
        M.add(MIAbrir);
        M.addSeparator();
        MISalir=new MenuItem("Salir");
        M.add(MISalir);
        MISalir.addActionListener(this);// 3/5
        F.setLayout(new BorderLayout());
        P = _llenar_Panel();
        F.add(P, BorderLayout.NORTH);
        TA=new TextArea();
        F.add(TA, BorderLayout.CENTER);
        F.addWindowListener(new WindowAdapter(){// 3/5 del Frame F
            public void windowClosing(WindowEvent we){
                F.dispose();
                System.exit(0);
            }
        });
        BotonAgregarEvid.addActionListener(this);// 3/5 Button BotonAgregarEvid
        
        F.setLocationRelativeTo(null);
        F.setSize(600,450);
        F.setResizable(false);
        F.setVisible(true);
    }//end EvidsChecking()
    private Panel _llenar_Panel(){
        Panel p=new Panel();
        p.setLayout(new FlowLayout());
        TF1=new TextField(10);
        TF2=new TextField(48);
        TF1.setText("Boleta");
        TF2.setText("Nombre de evidencia");
        BotonAgregarEvid=new Button("Agregar Evidencia");
        p.add(TF1);
        p.add(TF2);
        p.add(BotonAgregarEvid);
        return p;
    }
    public static void main(String[] args) {
        new EvidsChecking();
    }

    @Override
    public void actionPerformed(ActionEvent ae) {// 4/5
        if(ae.getSource().equals(BotonAgregarEvid)){// 5/5
            String str=TF1.getText();
            TF1.setText("");
            String str1=TF2.getText();
            TF2.setText("");
            String str2=TA.getText();
            if(str2.equals("")==false){
              str2=str2+"\n";
            }
            str2=str2+str+"\n"+str1;
            TA.setText(str2);
        }else if(ae.getSource().equals(MISalir)){
            F.dispose();
            System.exit(0);
        }
    }
}//end class EvidsChecking
