#include <iostream>
#include <string>
#include <map>
#include "BinaryLiterals.h"
#include "Lambda.h"

typedef void(*Component)();

std::map<std::string, Component> comp = {
  {"BinaryLiterals", BinaryLiterals},
  {"GenericLambda", GenericLambda}
};

void InsertHeader(std::string str)
{
  std::cout << "\n|------- Start Component - " << str << "\n\n";;
}

void InsertFooter(std::string str)
{
  std::cout << "\n|------- End Component - " << str << "\n\n";
}

void RunFunctions()
{
  for (const auto& elem : comp)
  {
    InsertHeader(elem.first);
    elem.second();
    InsertFooter(elem.first);
  }
}

int main()
{
  std::cout << "Welcome to C++ 14 Playground\n";

  // Run features
  RunFunctions();
}