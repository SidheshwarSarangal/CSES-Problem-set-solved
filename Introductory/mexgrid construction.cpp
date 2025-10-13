#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin>>n;
    vector<vector<ll>>grid(n, vector<ll>(n));
    vector<unordered_set<ll>>row(n),col(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ll val=0;
            while(col[j].count(val) || row[i].count(val)){
                val++;
            }
            col[j].insert(val);
            row[i].insert(val);
            grid[i][j]=val;
        }
    }

    for(auto k:grid){
        for(auto l:k){
            cout<<l<<" ";
        }
        cout<<"\n";
    }
}