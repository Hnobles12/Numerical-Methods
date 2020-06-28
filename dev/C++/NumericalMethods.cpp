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
/*
/*Numerical Derivative (dy/dx) - Finite Difference
 * @param double x[] : Independent array
 * @param double y[] : Dependent array
 * @return {double*} diff : Double array pointer

std::array<double> calculus::numDerivative(double x[], double y[]){
    int x_size = sizeof(x);
    int y_size =  sizeof(y);

    if (x_size != y_size){
        throw "Input array sizes do not match.";
    }
    std::array<double> diff;
    double diff[x_size-1], dy, h;

    for (int i=0; i<(x_size-1); i++){
        dy = y[i+1]-y[i];
        h = x[i+1]-x[i];
        diff[i] = dy/h;
    }
    return diff;
}
*/