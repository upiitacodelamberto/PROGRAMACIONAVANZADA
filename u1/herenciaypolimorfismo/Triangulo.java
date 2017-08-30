/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzadamarzojulio2015.u1.herenciaypolimorfismo;

/**
 *
 * @author lamberto
 */
public class Triangulo extends FiguraGeometrica{
  float Base, Altura;
  public Triangulo(float B, float A){
  nombre = "Triangulo";
  Base = B; Altura = A;
}
  @Override
  public float area(){
      return Base * Altura / 2;
  }
}
