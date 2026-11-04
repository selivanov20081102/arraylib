# arraylib

Кроссплатформенная динамическая библиотека операций над массивами `int`
(сумма, максимум, минимум, среднее, подсчёт положительных/отрицательных/нулевых,
произведение, медиана).

## Сборка

```bash
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

## Запуск

```bash
./build/app
./build/variant_01
```

## Структура

- `include/arraylib.h` — интерфейс библиотеки
- `src/arraylib.cpp` — реализация
- `tests/` — unit- и интеграционные тесты
- `examples/variant_01.cpp` — прикладная программа по варианту 1
