#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    int data[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    assert(arr_sum(data, n) == 45);
    assert(arr_max(data, n) == 9);

    double avg = arr_average(data, n);
    assert(avg >= static_cast<double>(arr_min(data, n)));
    assert(avg <= static_cast<double>(arr_max(data, n)));

    int mixed[] = {-4, 0, 6, 0, 2, -1, 9};
    const std::size_t m = sizeof(mixed) / sizeof(mixed[0]);
    assert(static_cast<std::size_t>(arr_count_positive(mixed, m) +
                                    arr_count_negative(mixed, m) +
                                    arr_count_zero(mixed, m)) == m);

    assert(close(arr_median(data, n), 5.0));
    assert(close(arr_median(data, n), arr_average(data, n)));

    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    assert(close(arr_median(sorted, 7), 4.0));

    std::cout << "[integration] All tests passed\n";
    return 0;
}
