/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzadamarzojulio2015.u1.herenciaypolimorfismo;

/**
 *
 * @author lamberto
 */
public abstract class FiguraGeometrica {

    public String nombre;
    float Area;

    public abstract float area(); //Una funcion virtual pura y
    //Ejemplo de un metodo abstracto

    public FiguraGeometrica(String name) {//Un constructor que recibe un string
        nombre = name;
    }

    FiguraGeometrica() {
        System.out.println("Constructor por defecto\n");
    }

    //public static void main(String[] args) {
    public static void main(String args[]) {
        //System.out.println(args[0] + " ");// + args[1]);
        Rectangulo R = new Rectangulo(5, 3);
        Triangulo T = new Triangulo(5, 3);

        FiguraGeometrica ARR[] = new FiguraGeometrica[2];
        ARR[0] = R;
        ARR[1] = T;

        for (int i = 0; i < 2; i++) {
            System.out.println(ARR[i].nombre + " " + ARR[i].area());
        }
    }
}
