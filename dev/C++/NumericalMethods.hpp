//#ifndef NUMERICALMETHODS_HPP
//#define NUMERICALMETHODS_HPP

#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
namespace misc{

    int closestVal(std::vector<double> vec, double val);
    int closestVal(double vec[]);

}
namespace math{
    bool sign(double num);
    bool sign(int num);

    int abs(int num);
    double abs(double num);

    /**
     * 3-D Vector Class <x,y,z>
     * @param double x : X-Value
     * @param double y : Y-Value
     * @param double z : Z-Value
    */ 
    class Vector{
    public:
        double x,y,z;
        Vector(double x, double y, double z);
        double mag();
    };

    double dot(Vector v1, Vector v2);
    Vector cross(Vector v1, Vector v2);

    double vectorAvg(Vector vec);
    double vectorAvg(std::vector<double> vec);

    std::vector<double> linspace(double a, double b, int divs=0);
}
namespace calculus{
    std::vector<double> numDerivative(std::vector<double> x, std::vector<double> y);
    double funcDerivative(double (*func)(double), double point, double TOL);
    double avgDerivative(std::vector<double> x, std::vector<double> y);

    double numIntegral(std::vector<double> x, double a, double b, int divs=100000);
    double funcIntegral(double (*func)(double), double a, double b, double TOL=1e-6);
}
namespace roots{
    double bisection(double (*func)(double), double a, double b, double TOL=1e-6);
    double newton(double (*func)(double), double x, double TOL=1e-6, int max_iter=100);

}

//#endif