# Shunt Library

This library is a a c++ implementation of the shunt algorithm. It is a library for parsing mathematical expressions and evaluating them. It is designed to be used with Arduino, but can be used in any c++ project by removing the logging statements.

## Usage

The library is header only, so you can just include the header file in your project. The library is under the class `Shunt`:

```cpp
#include "shunt.hpp"

int main() {
    Shunt shunt;
    char formula[] = "(8-4)*3+55";
    float result = shunt.shuntThis(formula); // call the method
    std::cout << result << std::endl;
    return 0;
}
```

## Supported operators

The library supports the following operators:

- `+` addition
- `-` subtraction
- `^` power
- `_` unary minus
- `/` division
- `*` multiplication
- `%` modulo
- `(` and `)` parenthesis

## Supported functions

TBA
