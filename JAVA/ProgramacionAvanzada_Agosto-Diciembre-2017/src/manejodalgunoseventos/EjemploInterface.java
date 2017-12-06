/*

 */
package manejodalgunoseventos;

/**
 *
 * @author Toshiba
 */
class FiguraGeom{
    Formula F;
}
public class EjemploInterface {
    public static void main(String[] args) {
        Cuadro C;
        Circulo Ci;
        C=new Cuadro(200);
        Ci=new Circulo(300);
        System.out.println("Circulo de area "+Ci.area());
        System.out.println("Cuadro de area "+C.area());
        FiguraGeom FG=new FiguraGeom();FG.F=CUtil.getFormula();
        System.out.println("Figura geométrica de area "+FG.F.area());
    }
}























