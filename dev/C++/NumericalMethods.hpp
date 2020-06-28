//#ifndef NUMERICALMETHODS_HPP
//#define NUMERICALMETHODS_HPP

#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
namespace misc{

    bool sign(double num);
    bool sign(int num);

    int abs(int num);
    double abs(double num);

    int closestVal(std::vector<double> vec, double val);
    int closestVal(double vec[]);

}
namespace math{
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
}
namespace calculus{
    std::vector<double> numDerivative(std::vector<double> x, std::vector<double> y);
    //std::array<double> numDerivative(double x[], double y[]);

    double funcDerivative(double (*func)(double), double point, double TOL);
}
namespace roots{
    
}

//#endif