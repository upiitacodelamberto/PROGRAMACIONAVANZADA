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
public class Triangulo extends FiguraGeometrica {

    float Base, Altura;

    public Triangulo(float B, float A) {
        nombre = "Triangulo";
        Base = B;
        Altura = A;
    }

    @Override
    public float area() {
        return Base * Altura / 2;
    }
}
