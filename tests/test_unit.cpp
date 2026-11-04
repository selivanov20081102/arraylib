#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    int a[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(a) / sizeof(a[0]);
    assert(arr_sum(a, n) == 7);
    assert(arr_max(a, n) == 8);
    assert(arr_min(a, n) == -5);
    assert(arr_count_positive(a, n) == 3);
    assert(arr_count_negative(a, n) == 2);
    assert(arr_count_zero(a, n) == 1);
    assert(arr_product(a, n) == 0);
    assert(close(arr_average(a, n), 7.0 / 6.0));

    int one[] = {42};
    assert(arr_sum(one, 1) == 42);
    assert(arr_max(one, 1) == 42);
    assert(arr_min(one, 1) == 42);
    assert(close(arr_median(one, 1), 42.0));

    int neg[] = {-3, -1, -7};
    assert(arr_max(neg, 3) == -1);
    assert(arr_min(neg, 3) == -7);
    assert(arr_count_negative(neg, 3) == 3);
    assert(arr_product(neg, 3) == -21);

    int b[] = {7, 1, 9, 3};
    assert(close(arr_median(b, 4), 5.0));
    int c[] = {5, 1, 3};
    assert(close(arr_median(c, 3), 3.0));
    int e[] = {1, 2};
    assert(close(arr_median(e, 2), 1.5));
    int big[] = {2000000000, 2000000000};
    assert(close(arr_median(big, 2), 2000000000.0));

    int src[] = {7, 1, 9, 3};
    int src_copy[] = {7, 1, 9, 3};
    arr_median(src, 4);
    for (std::size_t i = 0; i < 4; ++i) assert(src[i] == src_copy[i]);

    int d[] = {1, 2, 3, 4};
    assert(arr_product(d, 4) == 24);

    std::cout << "[unit] All tests passed\n";
    return 0;
}
