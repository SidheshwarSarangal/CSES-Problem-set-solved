#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> distinct_values;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        distinct_values.insert(x);
    }

    cout << distinct_values.size() << "\n";
    return 0;
}
