#include "NumericalMethods.hpp"

//Misc Functions
/**
* Sign of a Double
* @param double num : Number
* @return {bool} True : Positive | False : Negative
*/
bool misc::sign(double num){
    if (num >= 0){return true;}
    else {return false;}
}
/** 
 * Sign of an Integer
 * @param int num : Number
 * @return {bool} True : Positive | False : Negative
*/
bool misc::sign(int num){
    if (num >= 0){return true;}
    else {return false;}
}
/**
 * Absolute value of an integer
 * @param int num 
 * @return int num : absolute value
*/
int misc::abs(int num){
    if (num < 0){return num*-1;}
    else{return num;}
}
/**
 * Absolute value of a double
 * @param double num
 * @return double num : absolute value
*/
double misc::abs(double num){
    if (num < 0){return num*-1;}
    else{return num;}
}
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
        diffs.push_back(misc::abs(vec[i]));
    }

    int index = *std::min_element(diffs.begin(),diffs.end());
    return index;
}


//Math Fucntions
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


//Calculus Functions
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
 * @return double diff : Derivative evaluation
*/
double calculus::funcDerivative(double (*func)(double), double point, double TOL=1e-6){
    double DIVS = 1e6;
    double dh = TOL / DIVS;
    double bound = point - TOL/2;

    std::vector<double> x, y, dy;

    while (bound <= (point+TOL/2)){
        x.push_back(bound);
        bound += dh;
    }
    for (int i=0; i < x.size(); i++){
        y.push_back(func(x[i]));
    }

    dy = numDerivative(x,y);

    
}