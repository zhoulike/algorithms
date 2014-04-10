#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double sqrt_newton(double x)
{
    if (x <= 0)
        return x;

    double val = x, prev;

    do {
        prev = val;
        val = (prev + x / prev) / 2;
    } while(abs(val - prev) > numeric_limits<double>::epsilon());

    return val;
}

double sqrt_bi(double x)
{
    if (x <= 0)
        return x;

    double low = 0, high = x;
    double mid = (low + high) / 2, prev;

    do {
        if (mid * mid > x)
            high = mid;
        else
            low = mid;

        prev = mid;
        mid = low + (high - low) / 2;
    } while(abs(mid - prev) > numeric_limits<double>::epsilon());

    return mid;
}

float sqrt_magic(float x)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5;
    
    x2 = x * 0.5;
    y = x;
    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *) &i;
    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs - (x2 * y * y));

    return 1 / y;
}

void test()
{
    for (int i = 1; i < 20; ++i) {
        cout << sqrt_newton(i) << " " << sqrt_bi(i) << " " << sqrt_magic(i)  << " " << sqrt(i) << endl;
    }
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
