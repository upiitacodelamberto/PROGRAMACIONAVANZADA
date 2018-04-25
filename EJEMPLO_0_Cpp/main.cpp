#include <cstdlib>
#include <iostream>


using namespace std;

const float TaxRate = 0.28;

int main(int argc, char *argv[])
{
    float GrossPay = 100.0;
    float ExtraPay = 50.55;
    float NetTotalPay = GrossPay + ExtraPay;
    float NetPay = NetTotalPay - (NetTotalPay * TaxRate);
    cout << "Pago final $"<<NetPay<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}//end main()



