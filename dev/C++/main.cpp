#include "NumericalMethods.hpp"
#include <iostream>
#include <cmath>


using namespace std;
//using namespace math;

double test_func(double x){
    return pow(x,2) + x*5 - 50;
}

int main(){
    double zero = roots::newton(test_func, 2000, 1e-20);
    cout << zero << endl;
}