#include <stdio.h>
#include <complex.h>

double _Complex gauss_complex_multiplication (double _Complex  a, double _Complex  b);

int main()
{
    double _Complex a = 3.2 + 4.1 * I;
    double _Complex b = 4.7 + 9.2 * I;
    double _Complex c;
    
    c = gauss_complex_multiplication (a, b);
    printf ("%.2lf + %.2lfi", creal(c), cimag(c));
    return 0;
}


double _Complex gauss_complex_multiplication (double _Complex  a, double _Complex  b)
{
    double t1 = creal (a) * creal (b);
    double t2 = cimag (a) * cimag (b);
    double _Complex c = (t1 - t2) + (((creal (a) + creal (b)) * (cimag (a) + cimag (b))) - t1 - t2) * I;
    return c;
}