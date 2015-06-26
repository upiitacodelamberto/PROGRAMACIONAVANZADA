package u4.jni00;

public class EjemploString {

    public native String replaceString(String sourceString,
            String strToReplace, String replaceString);
    
    static {
        System.loadLibrary("BibliotecaString");
    }
    
    public static void main(String[] args) {
        EjemploString ex = new EjemploString();
        String str1 = "";
        String str2 = "";
        str1 = "Sky Black";
        str2 = ex.replaceString(str1, "Black", "Blue");
        System.out.println("La cadena antes: " + str1);
        System.out.println("La cadena despues: " + str2);
    }
}//end class EjemploString
