// https://cses.fi/problemset/task/1072/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll total = (k * k) * (k * k - 1) / 2;   // total pairs of knights
        ll attack = 4 * (k - 1) * (k - 2);      // attacking pairs
        ll ans = total - attack;                // non-attacking pairs
        cout << ans << "\n";
    }
    return 0;
}
