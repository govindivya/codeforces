#include <bits/stdc++.h>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long int> arr;
    for(int i=0;i<=n;i++) arr.push_back(0);
    long  maxValue = 0;
    for (int i = 0; i < queries.size(); i++)
    {
        int a ,b , k;
        a = queries[i][0];
        b = queries[i][1];
        k = queries[i][2];
        arr[a]+=k;
        if(b<n){
            arr[b+1]+=-k;
        } 
    }
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i]+arr[i-1];
    }
    for(int i=1;i<=n;i++){
        if(arr[i]>maxValue){
            maxValue = arr[i];
        }
    }
    return maxValue;
}
int main()
{

}