// https://cses.fi/problemset/task/1624/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<char>>grid(8, vector<char>(8));
int ans=0;
vector<bool>col(8,false);
vector<bool>dig1(15,false);
vector<bool>dig2(15,false);

void solve(int row){
    if(row>=8){
        ans++;
        return;
    }
    for(int i=0; i<8; i++){
        if(col[i]==false && dig1[row-i+7]==false && dig2[row+i]==false && grid[row][i]=='.'){
            col[i]=true;
            dig1[row-i+7]=true;
            dig2[row+i]=true;
            solve(row+1);
            col[i]=false;
            dig1[row-i+7]=false;
            dig2[row+i]=false;
        }
    }
    return;
}

int main() {
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>grid[i][j];
        }
    }
    solve(0);
    cout<<ans;

}
