#include <vector>
#include <algorithm>
#include <array>
namespace misc{

    bool sign(double num);
    bool sign(int num);

    int abs(int num);
    double abs(double num);

    int closestVal(std::vector<double> vec);
    int closestVal(double vec[]);

}
namespace math{
    #include <cmath>
    class Vector{
    public:
        double x,y,z;
        Vector(double x, double y, double z);
        double mag();
    };

    double dot(Vector v1, Vector v2);
    Vector cross(Vector v1, Vector v2);

}
namespace calculus{
    std::vector<double> numDerivative(std::vector<double> x, std::vector<double> y);
    //std::array<double> numDerivative(double x[], double y[]);

}
namespace roots{
    
}