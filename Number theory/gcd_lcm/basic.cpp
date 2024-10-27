#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a = 36, b = 60;

    // Calculate GCD
    int gcd = __gcd(a, b);

    // Calculate LCM
    int lcm = (a * b) / gcd;

  cout << "LCM of " << a << " and " << b << " is: " << lcm << endl;
    return 0;
}
