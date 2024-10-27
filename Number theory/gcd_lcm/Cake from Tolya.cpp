#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    //cout<<n/10<<" "<<n%10<<"\n";
    int ans =__gcd(n,m);
    int sum = n+m-ans;
    cout<<sum<<endl;
}
