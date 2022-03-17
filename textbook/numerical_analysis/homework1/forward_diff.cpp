#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct ADV
{
public:
    double a; // for storing original value
    double b; // for storing derivative value
    ADV(double a, double b) : a(a), b(b){};
    ~ADV(){};
    friend ADV operator+(ADV const &, ADV const &);
    friend ADV operator*(ADV const &, ADV const &);
    template <typename T>
    friend ADV operator+(ADV const &, T const &);
    template <typename T>
    friend ADV operator+(T const &, ADV const &);
    friend ADV operator/(ADV const &, ADV const &); // function overload for division
    friend ADV e(ADV const &);                      // function overload for exp
};

ADV operator+(ADV const &x, ADV const &y)
{
    // a: (f + g)  = f  + g
    // b: (f + g)' = f' + g'
    return ADV(x.a + y.a, x.b + y.b);
}

template <typename T>
ADV operator+(ADV const &x, T const &y)
{
    return ADV(x.a + y, x.b); // 原函数相加，导函数保留不变
}
template <typename T>
ADV operator+(T const &x, ADV const &y)
{
    return y + x;
}

ADV operator*(ADV const &x, ADV const &y)
{
    return ADV(x.a * y.a, x.b * y.a + x.a * y.b);
}
ADV operator/(ADV const &x, ADV const &y)
{
    double a = 0, b = 0;
    a = x.a / y.a;
    b = (x.b * y.a - x.a * y.b) / (y.a * y.a);
    return ADV(a, b);
}

ADV e(ADV const &x)
{
    double a = 0, b = 0;
    a = exp(x.a);
    b = exp(x.a) * x.b;
    return ADV(a, b);
}
int main(int argc, char const *argv[])
{
    ADV x1(5, 1), x2(6, 1), x22(6, 0), x3(7, 1);
    ADV a1 = e(x1), a22 = e(x22), a3 = e(x3);
    ADV a2 = e(x2);
    ADV dx1 = a22 / (a1 + exp(6) + exp(7));
    ADV dx2 = a2 / (a2 + exp(5) + exp(7));
    ADV dx3 = a22 / (a3 + exp(6) + exp(5));
    cout << setprecision(17) << "dx1= " << dx1.b << endl;
    cout << setprecision(17) << "dx2= " << dx2.b << endl;
    cout << setprecision(17) << "dx3= " << dx3.b << endl;
    return 0;
}