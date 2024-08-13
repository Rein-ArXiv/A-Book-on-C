#include "find_roots.h"

// dbl bisection(pfdd, dbl, dbl);
// dbl bisection(pfdd f, dbl a, dbl b);
// dbl bisection(dbl (*)(dbl), dbl a, dbl b);
// dbl bisection(dbl (*f)(dbl), dbl a, dbl b);
// dbl bisection(dbl f(dbl), dbl a, dbl b);
// dbl bisection(dbl f(dbl x), dbl a, dbl b);

dbl bisection(pfdd f, dbl a, dbl b)
{
    assert(f(a) * f(b) < 0.0);
    dbl m = (a + b) / 2.0;  // midpoint
    ++cnt;
    if (f(m) == 0.0 || b - a < eps)
        return m;
    else if (f(a) * f(m) < 0.0)
        return bisection(f, a, m);
    else
        return bisection(f, m, b);
}