#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin>>n;
    vector<vector<ll>>grid(n, vector<ll>(n,-1));
    
    vector<int>dx={1,1,-1,-1,2,2,-2,-2};
    vector<int>dy={2,-2,2,-2,1,-1,1,-1};

    queue<pair<int,pair<int,int>>>q;

    q.push({0,{0,0}});
    grid[0][0]=0;

    while(q.empty()==false){
        auto [dist,coordinates]=q.front();
        auto [x,y]=coordinates;
        q.pop();

        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==-1){
                grid[nx][ny]=dist+1;
                q.push({dist+1,{nx,ny}});
            }
        }
        
    }

    for(auto k:grid){
        for(auto l:k){
            cout<<l<<" ";
        }
        cout<<"\n";
    }
}