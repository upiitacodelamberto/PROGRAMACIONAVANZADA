/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzadamarzojulio2015.u1.herenciaypolimorfismo;

/**
 * github
 * @author lamberto
 */
public class Rectangulo extends FiguraGeometrica {

    float Base, Altura;

    public Rectangulo(float B, float A) {
        //nombre = "Rectangulo";
        super("Rectangulo");//Se invoca al constructor de la clase base
        Base = B;
        Altura = A;
    }

    @Override
    public float area() {
        return Base * Altura;
    }
}
