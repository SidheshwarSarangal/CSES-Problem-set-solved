#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();
    
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;
    
    // quick impossibility check
    int maxF = *max_element(freq.begin(), freq.end());
    if (maxF > (n + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }
    
    string res;
    res.reserve(n);
    int prev = -1; // index of previous char, -1 none
    
    for (int pos = 0; pos < n; ++pos) {
        bool placed = false;
        int remaining = n - pos - 1;
        
        for (int c = 0; c < 26; ++c) {
            if (freq[c] == 0) continue;
            if (c == prev) continue;
            
            // try placing c
            freq[c]--;
            
            // compute max frequency among remaining characters
            int mx = 0;
            for (int j = 0; j < 26; ++j) if (freq[j] > mx) mx = freq[j];
            
            if (mx <= (remaining + 1) / 2) {
                // safe to place c
                res.push_back(char('A' + c));
                prev = c;
                placed = true;
                break;
            } else {
                // not safe, revert and try next char
                freq[c]++;
            }
        }
        
        if (!placed) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
    cout << res << '\n';
    return 0;
}
