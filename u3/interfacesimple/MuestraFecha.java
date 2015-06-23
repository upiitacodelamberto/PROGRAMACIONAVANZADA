/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package u3.interfacesimple;

/**
 *
 * @author lamberto
 */
public class MuestraFecha  implements Shower{
    public void mostrar(Fecha f){
        System.out.println( f.dia + ", del mes "
                + f.mes + " del a" +(char)'ñ' + "o " + f.anyio);
    }
}
