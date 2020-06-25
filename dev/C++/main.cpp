#include "NumericalMethods.hpp"
#include <iostream>

using namespace std;

double test(){
    return 50.002;
}

void test2(double(*func)()){
   // double function = ;
    cout << func() << endl;
}

int main(){
    test2(test);
    double TOL = 1e-6;
    cout << 1/TOL << endl;
}