//   https://cses.fi/problemset/task/1071/

#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(x>y){
            ll val;
            if(x%2==0){
                val=x*x;
                for(int i=1; i<y; i++){
                    val=val-1;
                }
                cout<<val<<"\n";
            }
            else{
                val=(x-1)*(x-1);
                val=val+1;
                for(int i=1; i<y; i++){
                    val=val+1;
                }
                cout<<val<<"\n";
            }
        }
        else if(y>x){
            ll val;
            if(y%2==1){
                val=y*y;
                for(int i=1; i<x; i++){
                    val=val-1;
                }
                cout<<val<<"\n";
            }
            else{
                val=(y-1)*(y-1);
                val=val+1;
                for(int i=1; i<x; i++){
                    val=val+1;
                }
                cout<<val<<"\n";
            }

        }
        else{
            ll val=x*x;
            val=val-(x-1);
            cout<<val<<"\n";
        }
    }

}
