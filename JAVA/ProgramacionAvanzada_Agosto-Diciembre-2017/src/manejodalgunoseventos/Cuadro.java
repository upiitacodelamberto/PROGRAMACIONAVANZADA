/*

 */
package manejodalgunoseventos;

/**
 *
 * @author Toshiba
 */
public class Cuadro implements Formula{
    double lado;
    public Cuadro(double lado){
        this.lado=lado;
    }
    public double area(){
        return lado*lado;
    }
}
