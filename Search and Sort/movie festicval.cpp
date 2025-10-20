#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, int>> events;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        events.push_back({a, +1}); // arrival
        events.push_back({b, -1}); // leaving
    }

    sort(events.begin(), events.end());

    ll cur = 0, ans = 0;
    for (auto [time, change] : events) {
        cur += change;
        ans = max(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}
