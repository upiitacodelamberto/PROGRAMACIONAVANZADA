package u3.mygregcal.model;
import u3.interfacesimple.*;
//import anotacionesytrackers.anotacionTema;
//@anotacionTema(id="3.1",nomDTema="Introducion a las interfaces")
public class Fecha implements DaySetter{
    int dia, mes, anyio;
    String nomDD;// Nombre del dia
    String nomDM;// Nombre del mes
    
    int pnm[] = {0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0};
    String NdD[] = {"Lunes", "Martes", "Miercoles", 
        "Jueves", "Viernes", "Sabado", "Domingo"};
    String NdM[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", 
                     "julio"};
    public Fecha(int d, int m, int a){
        dia = d; mes = m; anyio = a;
    }
//    public Fecha(){ }
    @Override
    public  String toString(){
//        return nomDD + " " + dia + " del mes "  + mes + 
//                " de " + anyio;
        return nomDD + " " + dia + " de " + nomDM + " de " + anyio;
    }
    public void setDyM(){//Esta es la evidencia 
//        nomDD = NdD[(dia + 7 - pnm[mes - 1]) % 7];
        setNomDD(this);
        DaySetter DS = new DaySetterImpl();
        DS.setNomDD(this);
        nomDM = NdM[mes - 1];
    }
    @Override
    public void setNomDD(Fecha f){
        f.nomDD = NdD[(dia + 7 - pnm[mes - 1]) % 7];
    }
//    public static void main(String[] args) {
//        Fecha F = new Fecha(25, 5, 2015);
//        MuestraFechaNEspanyiol MFNE = new MuestraFechaNEspanyiol();
//        MFNE.mostrar(F);
//        Shower S = new MuestraFechaNEspanyiol();
//        S.mostrar(F);
//        
//        MuestraFecha MF = new MuestraFecha();
//        MF.mostrar(F);
//        Shower SMF = new MuestraFecha();
//        SMF.mostrar(F);
//    }
}
