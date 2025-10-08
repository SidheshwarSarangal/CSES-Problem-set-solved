// https://cses.fi/problemset/task/1617/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll ans=1;
    ll t=n;
    ll mod=1e9+7;
    while(t--){
        ans=(ans<<1)%mod;
    }
    cout<<ans;
}


