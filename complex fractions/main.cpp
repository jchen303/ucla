#include <iostream>
#include "Fracs.hpp"
#include "ComplexFracs.hpp"
using namespace std;

int main() {
//    Frac shit:
//    for (int den1=1; den1<10; ++den1)
//    {
//        for (int num1=0; num1<den1; ++num1)
//        {
//            for (int den2=1; den2<10; ++den2)
//            {
//                for (int num2=1; num2<den2; ++num2)
//                {
//                    const Frac f1(num1,den1);
//                    const Frac f2(num2,den2);
//
//                    f1.print();            cout << " / ";
//                    f2.print();            cout << " = ";
//                    f1.divide(f2).print(); cout <<  endl;
//                }
//            }
//        }
//    }
//    cout << endl;
//    Complex Frac shit:
    
    const ComplexFrac z;
    z.print(); cout << endl;
    
    const ComplexFrac zeta(Frac(3, 4));
    zeta.print(); cout << endl;
    const ComplexFrac zesta(Frac(27, 36));
    zesta.print(); cout << endl;
    
    const ComplexFrac zelta(Frac(6, 12), Frac(30, 19));
    zelta.print(); cout << endl;
    const ComplexFrac zeltad(Frac(1, 2), Frac(30, 19));
    
    zeltad.print(); cout << endl;
    const ComplexFrac zesty(3);
    zesty.print(); cout << endl;
    const ComplexFrac zebra(3, 7, 3, 2);
    zebra.print(); cout << endl;
    
    cout << boolalpha;
    cout << zelta.isEqual(zeltad) << endl;
    cout << zesta.isEqual(zesty) << endl;
    
    const ComplexFrac test = zelta.add(zebra);
    test.print(); cout << endl;
    const ComplexFrac test2 = zelta.subtract(zebra);
    test2.print(); cout << endl;
    const ComplexFrac test3 = zelta.multiply(zebra);
    test3.print(); cout << endl;
    const ComplexFrac test4 = zelta.divide(zebra);
    test4.print(); cout << endl;

    return 0;
}
