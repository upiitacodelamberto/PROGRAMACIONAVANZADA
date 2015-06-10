package programacionavanzadamarzojulio2015.u2.dnc;

public class SetOfInts {
    static final int NMAX = 100;
    int N;//cantidad de enteros en el oonjunto
    int arr[];
    public SetOfInts(){
        arr = new int[NMAX];
        N = 0;
    }
    public void add (int n){
        arr[N++] = n;
    }
        @Override
        public String toString(){
        String s = "";
        for(int i = 0; i < N; i++){
            s += " " + arr[i];
    }
        return s;
    }
}

