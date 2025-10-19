#include <bits/stdc++.h>
using namespace std;

string s;
bool visited[7][7];
int ans = 0;

// Directions: D, U, L, R
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dirc[4] = {'D','U','L','R'};

void dfs(int r, int c, int step) {
    if (r == 6 && c == 0) {
        if (step == 48) ans++;
        return;
    }
    if (step == 48) return;

    // If the path is boxed in (cannot move forward)
    if ((r == 0     || visited[r - 1][c]) &&
        (r == 6     || visited[r + 1][c]) &&
        (c == 0     || visited[r][c - 1]) &&
        (c == 6     || visited[r][c + 1])) return;

    // If the path forces a turn (split check)
    if ((r == 0     || visited[r - 1][c]) &&
        (r == 6     || visited[r + 1][c]) &&
        (c > 0 && !visited[r][c - 1]) &&
        (c < 6 && !visited[r][c + 1])) return;

    if ((c == 0     || visited[r][c - 1]) &&
        (c == 6     || visited[r][c + 1]) &&
        (r > 0 && !visited[r - 1][c]) &&
        (r < 6 && !visited[r + 1][c])) return;

    char ch = s[step];
    if (ch != '?') {
        for (int k = 0; k < 4; ++k) if (dirc[k] == ch) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= 7 || nc < 0 || nc >= 7 || visited[nr][nc]) return;
            visited[nr][nc] = true;
            dfs(nr, nc, step + 1);
            visited[nr][nc] = false;
            return;
        }
    } else {
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= 7 || nc < 0 || nc >= 7 || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            dfs(nr, nc, step + 1);
            visited[nr][nc] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    visited[0][0] = true;
    dfs(0, 0, 0);
    cout << ans << "\n";
    return 0;
}
