#include "ReturnType.h"
#include <iostream>
#include <type_traits>

// Deduce return type as `int`.
auto f1(int i) {
  return i;
}

template <typename T>
auto& f2(T& t) {
  return t;
}

void ReturnTypeDeduction()
{
  std::cout << "Using an auto return type in C++14, the compiler will attempt to deduce the type for you. With lambdas, you can now deduce its return type using auto, \n" <<
    "which makes returning a deduced reference or rvalue reference possible.\n";

  std::cout << "Deduce return type as `int`.\n";
  std::cout << f1(1) << "\n";

  // Returns a reference to a deduced type.
  auto g = [](auto& x) -> auto& { return f2(x); };
  int y = 123;
  int& z = g(y); // reference to `y`
}

void DecltypeAuto()
{
  /*The decltype(auto) type-specifier also deduces a type like auto does.
    However, it deduces return types while keeping their references and cv-qualifiers,
    while auto will not.*/

  const int x = 0;
  auto x1 = x; // int
  decltype(auto) x2 = x; // const int
  int y = 0;
  int& y1 = y;
  auto y2 = y1; // int
  decltype(auto) y3 = y1; // int&
  int&& z = 0;
  auto z1 = std::move(z); // int
  decltype(auto) z2 = std::move(z); // int&&
}

constexpr int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  else {
    return n * factorial(n - 1);
  }
}

void RelaxingConstraintsConstexpr()
{
  /* In C++11, constexpr function bodies could only contain a
  very limited set of syntaxes, including (but not limited to):
  typedefs, usings, and a single return statement. In C++14, the
  set of allowable syntaxes expands greatly to include the most common
  syntax such as if statements,
  multiple returns, loops, etc.
  */

  factorial(5); // == 120

}