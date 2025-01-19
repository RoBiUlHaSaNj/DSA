pb:https://usaco.org/index.php?page=viewproblem2&cpid=572

input
6 3
2
1
1
3
2
1
1 6
3 3
2 4

output
3 2 1
1 0 0
2 0 1






#include<bits/stdc++.h>
using namespace std;


int main()
{

    int n  ,q; cin>>n>>q;
    vector<int>arr(n),pref1(n+1,0),pref2(n+1,0),pref3(n+1,0);
   // for(int i =0;i<n;i++)cin>>arr[i];

     for(int  i =1;i<=n;i++)
     {
         int t;cin>>t;
         pref1[i]=pref1[i-1];

            pref2[i]=pref2[i-1];
               pref3[i]=pref3[i-1];


               if(t==1)  pref1[i]++;
                else if(t==2)  pref2[i]++;
                else if(t==3)  pref3[i]++;
     }
    while(q--)
    {
       int l,r;
       cin>>l>>r;//0 based  index
       int sum1=pref1[r]-pref1[l-1];
             int sum2=pref2[r]-pref2[l-1];
                   int sum3=pref3[r]-pref3[l-1];
       cout<<sum1<<sum2<<sum3<<endl;
    }

}
