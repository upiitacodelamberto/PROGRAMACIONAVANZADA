/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzadamarzojulio2015.u2.diasnocircula;

/**
 *
 * @author lamberto
 */
public class SetOfInts {
    static final int NMAX = 100; 
    int N;// Cantidad de enteros en el conjunto
    int arr[];
    public SetOfInts(){
        arr = new int[NMAX];
        N = 0;
    }
    public void add(int n){
        arr[N++] = n;
    }
    @Override
    public String  toString(){
        String s = "";
        for(int i = 0; i < N; i++){
            s += " " + arr[i];
        }
        return s;
    }
}
