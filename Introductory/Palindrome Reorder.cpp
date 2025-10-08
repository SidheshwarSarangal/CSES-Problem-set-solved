// https://cses.fi/problemset/task/1755/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    for(char c : s) cnt[c-'A']++;

    int oddCount = 0;
    char oddChar;
    for(int i=0;i<26;i++){
        if(cnt[i]%2==1){
            oddCount++;
            oddChar = 'A'+i;
        }
    }

    if(oddCount > 1){
        cout << "NO SOLUTION\n";
        return 0;
    }

    string left = "";
    for(int i=0;i<26;i++){
        left += string(cnt[i]/2, 'A'+i);  // append half of each character
    }

    string right = left;
    reverse(right.begin(), right.end());

    string ans = left;
    if(oddCount == 1) ans += oddChar;  // add the middle character if needed
    ans += right;

    cout << ans << "\n";
}
