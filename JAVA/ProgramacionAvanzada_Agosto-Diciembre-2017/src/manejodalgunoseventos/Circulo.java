/*

 */
package manejodalgunoseventos;

/**
 *
 * @author Toshiba
 */
public class Circulo implements Formula{
    double radio;
    public Circulo(double r){
        radio=r;
    }
    public double area(){
        return Math.PI*Math.pow(radio, 2);
    }
}
