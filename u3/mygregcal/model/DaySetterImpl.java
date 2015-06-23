package u3.mygregcal.model;

public class DaySetterImpl implements DaySetter {

    final static int DMmod[][] = {
        {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
        {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6}
    };
    String NdD[] = {"Domingo", "Lunes", "Martes", "Miercoles",
        "Jueves", "Viernes", "Sabado"};

    @Override
    public void setNomDD(Fecha f) {
        int M[];
        if (f.anyio % 4 == 0)// bisiesto
        {
            M = DMmod[1];
        } else {
            M = DMmod[0];
        }
        f.nomDD = NdD[((f.anyio - 1)%7 + ((f.anyio - 1)/4 - 
                3*((f.anyio - 1)/100 + 1)/4)%7 +M[f.mes - 1] + f.dia%7)%7];
    }
}
