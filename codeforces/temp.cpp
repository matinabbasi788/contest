#include <algorithm>
#include <bits/stdc++.h>
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

class Pizza{
  public:
    std::string topping1;

  Pizza(std::string topping1){
    this->topping1 = topping1;

  }
};

using namespace std;
int main(){
  
  Pizza pizza1("pepperoni");

  cout << pizza1.topping1 << '\n';

  return 0;
}
