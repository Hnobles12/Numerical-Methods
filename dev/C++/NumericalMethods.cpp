#include "NumericalMethods.hpp"
#include <iostream>

//*Misc Functions (misc::)
/**
 * Closest Value index in vector
 * @param std::vector<double> vec
 * @param double value
 * @return int index
*/
int misc::closestVal(std::vector<double> vec, double val){
    double diff;
    std::vector<double> diffs;

    for (int i=0; i< (vec.size()-1); i++){
        diffs.push_back(math::abs(vec[i]));
    }

    int index = *std::min_element(diffs.begin(),diffs.end());
    return index;
}


//*Math Fucntions (math::)
/**
* Sign of a Double
* @param double num : Number
* @return {bool} True : Positive | False : Negative
*/
bool math::sign(double num){
    if (num >= 0){return true;}
    else {return false;}
}
/** 
 * Sign of an Integer
 * @param int num : Number
 * @return {bool} True : Positive | False : Negative
*/
bool math::sign(int num){
    if (num >= 0){return true;}
    else {return false;}
}
/**
 * Absolute value of an integer
 * @param int num 
 * @return int num : absolute value
*/
int math::abs(int num){
    if (num < 0){return num*-1;}
    else{return num;}
}
/**
 * Absolute value of a double
 * @param double num
 * @return double num : absolute value
*/
double math::abs(double num){
    if (num < 0){return num*-1;}
    else{return num;}
}
/**
*Vector Type Constructor
* @param double x_val : X Value
* @param double y_val : Y Value
* @param double z_val : Z Value
*/
math::Vector::Vector(double x_val=0, double y_val=0, double z_val=0){
    Vector::x = x_val;
    Vector::y = y_val;
    Vector::z = z_val;
}
/** 
 * Vector Magnitude
 * @return {double} Magnitude
*/
double math::Vector::mag(){
    return pow(pow(Vector::x, 2)+pow(Vector::y, 2)+pow(Vector::z ,2),0.5);
}
/** 
 * Vector Dot Product
 * @param math::Vector v1 : Vector 1
 * @param math::Vector v2 : Vector 2
 * @return {double} Dot Product
*/
double math::dot(math::Vector v1, math::Vector v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}
/** 
 * Vector Cross Product
 * @param math::Vector v1 : Vector 1
 * @param math::Vector v2 : Vector 2
 * @return {math::Vector} vec : Resultant Vector
*/
math::Vector math::cross(math::Vector v1, math::Vector v2){
    math::Vector vec(0,0,0);
    vec.x = (v1.y*v2.z)-(v1.z*v2.y);
    vec.y = (v1.z*v2.x)-(v1.x*v2.z);
    vec.z = (v1.x*v2.y)-(v1.y*v2.x);
    return vec;
}
/**
 * Get average of elements in a vector
 * @param Vector vec : vector
 * @return {double} avg : Average
*/
double math::vectorAvg(Vector vec){
    return (vec.x + vec.y + vec.z)/3;
}
/**
 * Get average of elements in a vector
 * @param std::vector<double> vec : vector
 * @return {double} avg : Average
*/ 
double math::vectorAvg(std::vector<double> vec){
    double len = vec.size();
    double sum = 0;

    for (int i=0; i < len; i++){
        sum += vec[i];
    }
    return sum/len;
}
/**
 * *Linspace: divides distance between two values into a vector with divisions.
 * @param double a : Start value
 * @param double b : End value
 * @param int divs : Number of divisions
 * @return {std::vector<double>} vec : Output vector
*/
std::vector<double> math::linspace(double a, double b, int divs){
    if (a == b){
        throw "Value Error: Start and end values are identical.";
    }
    
    std::vector<double> vec;
    if (divs == 0){
        vec.push_back(a);
        vec.push_back(b);
        return vec;
    }

    double dx = (b-a)/divs;
    double num = a;
    vec.push_back(num);

    for (int i=1; i != divs; i++){
        num = a + i*dx;
        //std::cout << "in loop" << std::endl;
        vec.push_back(num);
        //std::cout << num << std::endl;
    }
    vec.push_back(b);
    return vec;
}


//*Calculus Functions (calculus::)
/**
 * Numerical Derivative (dy/dx) - Finite Difference
* @param std::vector<double> x
* @param std::vector<double> y
* @return {std::vector<double>} diff : Derivative Vector
*/
std::vector<double> calculus::numDerivative(std::vector<double> x, std::vector<double> y){
    //Check Lengths
    int x_size = x.size();
    int y_size = y.size();
    
    if (x_size != y_size){
        throw "Input vector sizes do not match.";
    }

    std::vector<double> diff;
    double dy, h;

    for (int i=0; i<(x_size-1); i++){
        dy = y[i+1]-y[i];
        h = x[i+1]-x[i];
        diff.push_back(dy/h);
    }

    return diff;
}
/**
 * Functional Derivative
 * @param {double (*func)(double)} func : Function to perform derivative on
 * @param double point : Point at which to evaluate derivative
 * @param double TOL : Tolerance for derivative (default 1e-6)
 * @return double avg_diff : Derivative evaluation
*/
double calculus::funcDerivative(double (*func)(double), double point, double TOL=1e-6){

    std::vector<double> x, y, dy;
    double avg_diff;

    double DIVS = 1e6;
    double dh = TOL / DIVS;
    double bound = point - TOL/2;

    while (bound <= (point+TOL/2)){
        x.push_back(bound);
        bound += dh;
    }

    for (int i=0; i < x.size(); i++){
        y.push_back(func(x[i]));
    }

    dy = numDerivative(x,y);
    avg_diff = math::vectorAvg(dy);

    return avg_diff;
}
/**
 * *Average derivative of a vector (dy/dx)
 * @param std::vector<double> x : independent vector
 * @param std::vecotr<double> y : dependant vector
 * @return {double} avg_diff : Average Derivative 
*/
double calculus::avgDerivative(std::vector<double> x, std::vector<double> y){
    std::vector<double> diff = numDerivative(x,y);
    double avg_diff = math::vectorAvg(diff);
    return avg_diff;
}

//*Root-Solving functions (roots::)
/**
 * Bisection Method for root solving
 * @param double_return_function (double(*func) (double)) func : Function for root solving
 * @param double a : first bound
 * @param double b : second bound
 * @return {double} xmid : x-value of root
*/
double roots::bisection(double (*func)(double), double a, double b, double TOL){
    bool a_sign = math::sign(func(a));
    bool b_sign = math::sign(func(b));

    if (a_sign == b_sign){
        throw "Root is not bracketed by [a,b].";
    }

    double xmid = (a+b)/2;
    double eval = func(xmid);
    double i=0;

    while (math::abs(eval) > TOL){
        if (math::sign(func(xmid)) == a_sign){
            a = xmid;
            a_sign = math::sign(func(a));
        }
        else {
            b = xmid;
            b_sign = math::sign(func(b));
        }
        
        xmid = (a+b)/2;
        eval = func(xmid);
    }

    return xmid;
}
/**
 * *Newton Method for root solving
 * @param double_func_ptr func : function for root solving
 * @param double x : starting point for iteration
 * @param double TOL : Tolerance for convergence (default=1e-6)
*/ 
double roots::newton(double(*func)(double), double x, double TOL, int max_iter){
    double diff, i = 0;

    while (math::abs(func(x)) > TOL){
        diff = calculus::funcDerivative(func, x, 1e-6);
        if (diff == 0){
            throw "Division Error: Division by Zero.";
        }
        if (i>max_iter){
            throw "Iteration Error: Maximum number of iterations exceded.";
        }
        std::cout << x << ", " << func(x) << std::endl;
        x = x - (func(x)/diff);
        i++;
    }
    return x;
}