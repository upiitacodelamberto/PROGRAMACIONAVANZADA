/*

 */
package manejodalgunoseventos;

/**
 *
 * @author Toshiba
 */
public class CUtil {
    static double longitud;
    static int elecc;
    static java.util.Scanner scanner;
    static Formula InterfFormula;
    static Formula getFormula(){
        System.out.println("1) Cuadro\n2) Círculo\nTeclee 1 ó 2: ");
        scanner=new java.util.Scanner(System.in);
        elecc=scanner.nextInt();
        switch(elecc){
            case 1:{
                System.out.println("lado? ");
                longitud=scanner.nextDouble();
                InterfFormula=new Cuadro(longitud);
                break;
            }
            case 2:{
                System.out.println("radio? ");
                longitud=scanner.nextDouble();
                InterfFormula=new Circulo(longitud);
                break;}
            default:{
                System.exit(0);
                break;}
        }
        return InterfFormula;
    }
}












