/*

 */
package manejodexcepciones;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * ExIndexOutOfBound.java Gestion de la excepcion que se presenta cuando un 
 * indice para un array esta fuera de los limites en los que debe estar.
 * @author Toshiba
 * @version 2017.11.17
 */
public class ExIndexOutOfBound {
    static BufferedReader BR;
    static InputStreamReader ISR;
//    public static void main(String[] args) throws IOException{
    public static void main(String[] args){
        java.util.Scanner S=new java.util.Scanner(System.in);
        int[] myArray;
        int arr[],i=0;
        arr=new int[5];
        while(i<5){
            arr[i]=suma_indices_previos(i);
            i++;
        }
        show_array_dInts(arr);
        ISR=new InputStreamReader(System.in);
        BR=new BufferedReader(ISR);
        while(true){
            System.out.print("[<0 para salir] Índice? ");
//            i=S.nextInt();
            String Str;
            try {
                Str = BR.readLine();
                i=Integer.parseInt(Str);
            }catch(NumberFormatException nfe){
                nfe.printStackTrace();
            }
            catch (IOException ex) {
                Logger.getLogger(ExIndexOutOfBound.class.getName()).log(Level.SEVERE, null, ex);
            }finally{
                System.out.println("BLOQUE finally");
            }
            
            if(i<0){
                System.exit(0);
            }else{
                try{
                  System.out.printf("%d\n",arr[i]);
                }catch(ArrayIndexOutOfBoundsException aiooe){
                    aiooe.printStackTrace();
                }
            }
        }
    }
    static int suma_indices_previos(int intI){
        int sum=0;
        for(int i=0;i<=intI;i++)
            sum+=i;
        return sum;
    }
    static void show_array_dInts(int a[]){
        for(int j=0;j<a.length;j++){
            System.out.printf("%d\t",a[j]);
        }
        System.out.println();
    }
}//end class ExIndexOutOfBound















