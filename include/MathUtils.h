#include <math.h>

bool isEqual( double a, double b, const double epsilon=1e-6 ) {
    double c = a - b;
    return fabs( c ) < epsilon;
}
