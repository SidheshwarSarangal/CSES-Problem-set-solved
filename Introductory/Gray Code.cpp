// https://cses.fi/problemset/task/2205/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n;
    cin >> n;

    ll total = 1 << n; // 2^n

    for (ll i = 0; i < total; i++) {
        ll gray = i ^ (i >> 1); // convert i to Gray code
        // print as n-bit binary
        for (int j = n - 1; j >= 0; j--) {
            cout << ((gray >> j) & 1);
        }
        cout << "\n";
    }

    return 0;
}
