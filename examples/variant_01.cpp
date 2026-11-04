#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    int temperature[] = {
        -8, -5, -3, 0, 2, 1, -1,
        -4, -6, -2, 0, 3, 5, 4,
        2, 1, -2, -7, -9, -4, 0,
        3, 6, 5, 2, -1, -3, -5,
        1, 4
    };
    const std::size_t n = sizeof(temperature) / sizeof(temperature[0]);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Температура воздуха за месяц (" << n << " дней):\n";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << temperature[i] << (i + 1 < n ? ' ' : '\n');
    }

    std::cout << "Средняя температура:       " << arr_average(temperature, n) << '\n';
    std::cout << "Максимальная температура:  " << arr_max(temperature, n) << '\n';
    std::cout << "Минимальная температура:   " << arr_min(temperature, n) << '\n';
    std::cout << "Количество морозных дней:  " << arr_count_negative(temperature, n) << '\n';
    std::cout << "Медиана температур:        " << arr_median(temperature, n) << '\n';
    return 0;
}
