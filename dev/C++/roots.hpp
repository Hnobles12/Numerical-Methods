//#include "misc.hpp"
//#include <vector>

double bisection(double(*func), double bounds[2],double TOL=1e-6){
    //double f = *func;
    if (sign(bounds[0])==sign(bounds[1])){
        throw "Root is not bracketed. Signs of bounds are identical.";
    }
    
    //std::vector<double> data;
    int iter = 0; 
    return 100;
}