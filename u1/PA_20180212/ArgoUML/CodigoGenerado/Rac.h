#ifndef Rac_h
#define Rac_h



    /** 
     *  Clase para representar n\'umeros racionales
     *  @author Lamberto Maza Casas
     *  @version 2018.02.12
     */
class Rac {

 public:

    int calc_mcd();

    void set_mcd(int MCD);

    Rac& operator+(Rac& RacObj);

    Rac& operator-(Rac& RacObj);

    Rac& operator*(Rac& RacObj);

    Rac& operator/(Rac& RacObj);

    friend ostream& operator<<(ostream& ostreamOut, Rac& RacObj);

    Rac(int intNum, int intDen);

    Rac();

    void simplificar();

 public:
    int n;
    int d;
    int mcd;
};

#endif // Rac_h
