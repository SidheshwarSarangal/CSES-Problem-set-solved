// https://cses.fi/problemset/task/1622/
#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void f(string &s, string &cur, vector<bool> &check) {
    if (cur.size() == s.size()) {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (check[i]) continue;                 // already used
        if (i > 0 && s[i] == s[i-1] && !check[i-1]) continue; // skip duplicates

        check[i] = true;
        cur.push_back(s[i]);
        f(s, cur, check);
        cur.pop_back();
        check[i] = false;
    }
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());  // sort to handle duplicates

    vector<bool> check(s.size(), false);
    string cur = "";
    f(s, cur, check);

    cout << ans.size() << "\n";
    for (auto &x : ans) cout << x << "\n";
}
