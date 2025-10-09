// https://cses.fi/problemset/task/2165/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<int,int>>ans;

void f(int n, int start, int end, int mid){
    if(n==0) return;
    f(n-1,start, mid, end);
    ans.push_back({start,end});
    f(n-1,mid,end,start);
}

int main() {
    ll n;
    cin >> n;
    f(n,1,3,2);
    for(auto [k,l]:ans){
        cout<<k<<l<<"\n";
    }
    
    return 0;
}
