#include <bits/stdc++.h>
using namespace std;




int main() {
    long long n;
    cin >> n;

  
    for (long long i = sqrt(n); i > 0; i--) {
       
        if (n % i == 0) {
  
            if (__gcd(i, n / i) == 1) {
                cout << i << ' ' << n / i << endl;
                return 0;  
            }
        }
    }

    return 0;
}
 
