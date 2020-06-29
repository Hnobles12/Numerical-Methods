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
    vector<double> ans = math::linspace(0,10,10);
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    //cout << ans.size() << endl;

}