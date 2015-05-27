/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzadamarzojulio2015.interfacesimple;

public class MuestraFechaNEspanyiol implements Shower{
    int pnm[] = {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0};
    String NdD[] = {"Lunes", "Martes", "Miercoles", 
        "Jueves", "Viernes", "Sabado", "Domingo"};
    public void mostrar(Fecha f){
        System.out.println( NdD[(f.dia + 7 - pnm[f.mes - 1]) % 7] + ", "
                + f.dia + " del mes "
                + f.mes + " del año " + f.anyio);
    }
}
