#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return b<a;
}

int main(){

   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   sort(arr,arr+n,comp);
   cout<<arr[2];

}