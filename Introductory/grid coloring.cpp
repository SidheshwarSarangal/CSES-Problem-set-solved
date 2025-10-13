#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<string> ans(n, string(m, ' '));
    string letters = "ABCD";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            set<char> bad;
            bad.insert(grid[i][j]); // original letter
            if (i > 0) bad.insert(ans[i-1][j]); // top
            if (j > 0) bad.insert(ans[i][j-1]); // left

            for (char c : letters) {
                if (!bad.count(c)) {
                    ans[i][j] = c;
                    break;
                }
            }
        }
    }

    // print final grid
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
