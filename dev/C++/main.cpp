#include "NumericalMethods.hpp"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;
//using namespace math;

double test_func(double x){
    return pow(x,2) + x*5 - 50;
}

int main(){
    /*vector<double> ans = math::linspace(0,10,10);
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    //cout << ans.size() << endl;
    */
   vector<double> x = math::linspace(2,4,100000);
   vector<double> y;
   for (int i=0; i<x.size(); i++){
       y.push_back(test_func(x[i]));
   }
   double ans1 = calculus::numIntegral(x,y);
   double ans2 = calculus::funcIntegral(test_func,2,4);
   cout << ans1 << endl;

}