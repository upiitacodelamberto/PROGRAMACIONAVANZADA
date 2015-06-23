/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package u3.interfacesimple;
//import anotacionesytrackers.anotacionTema;
//@anotacionTema(id="3.1",nomDTema="Introducion a las interfaces")
public class Fecha {
    int dia, mes, anyio;
    String nomDD;// Nombre del dia
    String nomDM;// Nombre del mes
    public Fecha(int d, int m, int a){
        dia = d; mes = m; anyio = a;
    }
//    public Fecha(){ }
    @Override
    public  String toString(){
        return nomDD + " " + dia + " del mes "  + mes + 
                " de " + anyio;
    }
    private void setDyM(){//Esta es la evidencia 
        
    }
    public static void main(String[] args) {
        Fecha F = new Fecha(25, 5, 2015);
        MuestraFechaNEspanyiol MFNE = new MuestraFechaNEspanyiol();
        MFNE.mostrar(F);
        Shower S = new MuestraFechaNEspanyiol();
        S.mostrar(F);
        
        MuestraFecha MF = new MuestraFecha();
        MF.mostrar(F);
        Shower SMF = new MuestraFecha();
        SMF.mostrar(F);
    }
}
