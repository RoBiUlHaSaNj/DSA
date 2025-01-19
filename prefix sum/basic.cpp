#include<bits/stdc++.h>
using namespace std;

when use it 
1.Frequent Range Sum Queries
2.Optimizing Repeated Calculations
3.Transforming Subarray Problems

When Not to Use    

If the array changes frequently (dynamic updates).
If preprocessing overhead outweighs the benefit for a small number of queries.
int main()
{

    int n  ,q; cin>>n>>q;
    vector<int>arr(n),pref(n);
    for(int i =0;i<n;i++)cin>>arr[i];
     pref[0]=arr[0];
        for(int i =1;i<n;i++)
        {
            pref[i]=pref[i-1]+arr[i];

        }
    while(q--)
    {
       int l,r;
       cin>>l>>r;//0 based  index
       int sum=pref[r]-(l>0 ?pref[l-1]:0);
       cout<<sum<<endl;
    }

}
