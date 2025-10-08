// https://cses.fi/problemset/task/1754/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if((a+b)%3==0 && 2*min(a,b)>=max(a,b)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}
