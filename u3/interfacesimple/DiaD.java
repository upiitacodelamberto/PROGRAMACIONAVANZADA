/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package u3.interfacesimple;

//3.3 Uso de super
public class DiaD extends Fecha{
    String acontecimiento;

    
    public DiaD(String celeb, int d, int m, int a){
        super(d, m, a);//Con esto se llama al constructor 
                       //de la superclase que recibe tres ints
        acontecimiento = celeb;
    }
    @Override
    public  String toString(){
        return nomDD + " " + dia + " del mes "  + mes + 
                "("+ acontecimiento + ") de " + anyio;
    }
    public static void main(String[] args) {
        Fecha EDIS = new DiaD("Examen de admision al IPN", 30, 5, 2015);
        EDIS.nomDD = "Sabado";
        Fecha EDID = new DiaD("Examen de admision al IPN", 31, 5, 2015);
        EDID.nomDD = "Domingo";
        Fecha DDP = new DiaD("Dia del padre", 6, 6, 2015);
        DDP.nomDD = "Sabado";
        Fecha CDJ = new DiaD("Cumple de Cosecha de Frutos", 26, 6, 2015);
        CDJ.nomDD = "Viernes";
        Fecha F = new Fecha(28, 5, 2015);
        F.nomDD = "Miercoles";
        Fecha pa[] = new Fecha[5];
        pa[0] = EDIS;
        pa[1] = EDID; 
        pa[2] = DDP; 
        pa[3] = CDJ; 
        pa[4] = F;
        for(int i = 0; i < pa.length; i++)
            System.out.println(pa[i]);
    }
}
