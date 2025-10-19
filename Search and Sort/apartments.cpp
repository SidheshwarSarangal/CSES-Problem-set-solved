#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int matches = 0;

    while (i < n && j < m) {
        if (b[j] < a[i] - k) {
            j++; // Apartment too small
        } else if (b[j] > a[i] + k) {
            i++; // Apartment too big
        } else {
            matches++; // Match found
            i++;
            j++;
        }
    }

    cout << matches << "\n";
    return 0;
}