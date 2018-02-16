#ifndef Polinomio_h
#define Polinomio_h


class Polinomio {

 public:

    Polinomio& operator+(Polinomio& PolObj);

    Polinomio& operator-(Polinomio& PolObj);

    Polinomio& operator*(Polinomio& PolObj);

    FcnDTrans& operator/(Polinomio& PolObj);

    Polinomio(int intGrado, Rac * RacPt);

    friend ostream& operator<<(ostream& ostreamOut, Polinomio& PolObj);

 public:
    int grado;
    Rac * A;
};

#endif // Polinomio_h
