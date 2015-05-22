/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzadamarzojulio2015.interfacesimple;

/**
 *
 * @author lamberto
 */
public class Fecha {
    int dia, mes, anyio;
    public Fecha(int d, int m, int a){
        dia = d; mes = m; anyio = a;
    }
    public static void main(String[] args) {
        Fecha F = new Fecha(22, 5, 2015);
        MuestraFechaNEspanyiol MFNE = new MuestraFechaNEspanyiol();
        MFNE.mostrar(F);
        MuestraFecha MF = new MuestraFecha();
        MF.mostrar(F);
    }
}
