#include <bits/stdc++.h>

using namespace std;

int n, l;
int board[105][105];

bool check_path(vector<int>& path) {
    vector<bool> ramp(n, false);

    for (int i = 0; i < n - 1; i++) {
        if (path[i] == path[i + 1]) continue;

        if (abs(path[i] - path[i + 1]) > 1) return false;

        if (path[i] + 1 == path[i + 1]) {
            for (int j = 0; j < l; j++) {
                if (i - j < 0 || path[i - j] != path[i] || ramp[i - j]) return false;
                ramp[i - j] = true;
            }
        } 
        else if (path[i] - 1 == path[i + 1]) {
            for (int j = 1; j <= l; j++) {
                if (i + j >= n || path[i + j] != path[i + 1] || ramp[i + j]) return false;
                ramp[i + j] = true;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int valid_paths = 0;

    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) {
            row[j] = board[i][j];
        }
        if (check_path(row)) valid_paths++;
    }

    for (int j = 0; j < n; j++) {
        vector<int> col(n);
        for (int i = 0; i < n; i++) {
            col[i] = board[i][j];
        }
        if (check_path(col)) valid_paths++;
    }

    cout << valid_paths << '\n';

    return 0;
}