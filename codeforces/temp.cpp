#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/fwd.hpp>

using namespace std;
using namespace boost::multiprecision;

int main()
{
  long long a, b;
  cin >> a >> b;
  cpp_int a_power_b = 1;
  cpp_int b_power_a = 1;
  for (int i = 0; i < b; i++){
    a_power_b *= a;
  }
  for (int i = 0; i < a; i++){
    b_power_a *= b;
  }
  cpp_int result = a_power_b - b_power_a;
  cout << result << '\n';
}

