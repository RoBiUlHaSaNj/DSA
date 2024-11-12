#include <bits/stdc++.h>

using namespace std;


void sectionSort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        int idx=i;
        for(int j=i+1;j<n;j++)
          {
             if(arr[j]<arr[idx]) idx =j;

          }
          swap(arr[i],arr[idx]);



    }


}

int main()
{

  int  n;cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  sectionSort(arr);
  for(auto &i :arr){ cout<<i<<" ";} cout<<endl;


}
