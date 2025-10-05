// https://cses.fi/problemset/task/1092/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll s=(n*(n+1))/2;
    if(s%2==1){
        cout<<"NO";
        return 0;
    }
    ll target=s/2;
    set<ll>A;
    set<ll>B;
    ll sumA=0;
    ll sumB=0;
    for(int k=n; k>=1; k--){
        if(sumA+k>target){
            A.insert(k);
            sumB+=k;
        }
        else{
            B.insert(k);
            sumA+=k;
        }
    }
    if(sumA!=sumB){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<"\n";
    cout<<A.size()<<"\n";
    for(auto k:A) cout<<k<<" ";
    cout<<"\n";
    cout<<B.size()<<"\n";
    for(auto k:B) cout<<k<<" ";
    return 0;
}
