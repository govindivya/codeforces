#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int aux[n + 1];
        for (int i = 0; i < n; i++)
        {
            aux[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            aux[a[i]]++;
        }
        int q;
        cin >> q;
        vector<pair<int,int>> query;
        for (int i = 0; i < q; i++)
        {
             int num1,num2;
             cin>>num1>>num2;
             query.push_back(make_pair(num2,num1));
        }
        sort(query.begin(),query.end());
        int maximum=query[q-1].first;
        int count=0;
        for(int i=0;i<=maximum;i++){
            if(query[count].first==i){
              while(query[count].first==i){
                    cout<<a[query[count].second-1]<<"\n";
                    count++;
              }
            }
            for(int j=0;j<n;j++){
                a[j]=aux[a[j]];
            }
            for(int j=0;j<n;j++){
                aux[j]=0;
            }
            for(int j=0;j<n;j++){
                aux[a[j]]++;
            }
            bool check=true;
            for(int j=0;j<n;j++){
               if(aux[j]!=0){
                   if(aux[j]!=j) check=false;
               }
            }
            if(check){
                break;
            }
        }
        while(count<q){
           cout<<a[query[count].second-1]<<"\n";
                    count++; 
        }

    }
}