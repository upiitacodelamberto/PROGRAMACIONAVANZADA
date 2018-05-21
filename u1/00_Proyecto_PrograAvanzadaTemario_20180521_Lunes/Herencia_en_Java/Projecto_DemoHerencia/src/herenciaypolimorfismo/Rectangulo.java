/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package herenciaypolimorfismo;

/**
 *
 * @author Sala1
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