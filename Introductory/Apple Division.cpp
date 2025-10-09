// https://cses.fi/problemset/task/1623/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>nums;
ll total=0;
ll ans=1e9;

void f(ll cur, ll i){
    if(i<0) return;
    if(cur==0 && i<=0) return;
    ans=min(ans,abs(total-cur*2));
    f(cur,i-1);
    f(cur+nums[i],i-1);
    return;
}

int main() {
    ll n;
    cin>>n;
    nums.resize(n,0);
    for(ll i=0; i<n; i++){
        cin>>nums[i];
        total+=nums[i];
    }
    ans=total;
    ll cur=0;
    f(cur,n-1);
    cout<<ans;
}
