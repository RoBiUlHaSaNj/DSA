#include <bits/stdc++.h>
using namespace std;




int main()
{

    //two  number gcd __gcd(a,b)
   // hare gave n we need to  a b c such that a+b+c=n;
// gcd(a,b) =c hoite hbe even 4 odd
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        //  c = 1, a = 2, and b = n - 3
       // long long c = 1;
       // long long a = 2;
       // long long b = n - c - a; // n - 1 - 2 = n - 3

      //  cout << a << " " << b << " " << c << endl;
      if(n%2==0)cout<<n-3<<" "<<2<<" "<<1<<endl;
       else if (n % 4 == 1) {
            long long h = n / 2;
            cout << h - 1 << " " << h + 1 << " " << 1 << endl; // a = h-1, b = h+1, c = 1
        }
       else {
            long long h = n / 2;
            cout << h - 2 << " " << h + 2 << " " << 1 << endl; // a = h-2, b = h+2, c = 1
        }
    }

}
