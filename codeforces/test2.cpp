#include <iostream>
using namespace std;

long long cnt = 0; // Global variable to count trailing zeros

long long calculate(int num) {
    while (num % 10 == 0) {
        num = num / 10;
        cnt++;
    }
    num = num % 100;
    return num;
}

int main() {
    long long n;
    cin >> n;

    long long f = 1;
    for (long long i = 1; i <= n; i++) {
        f = f * i;
        f = calculate(f);
    }

    cout << cnt << endl;
    return 0;
}
