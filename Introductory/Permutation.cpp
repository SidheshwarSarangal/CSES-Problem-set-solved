//   https://cses.fi/problemset/task/1070/

#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    if(n==2 || n==3){
        cout<<"NO SOLUTION";
        return 0;
    }
    if(n==4){
        cout<<"2 4 1 3";
        return 0;
    }

    vector<ll>ans;
    ll x=1;
    while(x<=n){
        ans.push_back(x);
        x=x+2;
    }
    x=2;
    while(x<=n){
        ans.push_back(x);
        x=x+2;
    }
    reverse(ans.begin(), ans.end());
    for(auto k:ans)cout<<k<<" ";
}
