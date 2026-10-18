#include <bits/stdc++.h>

using namespace std;

int r, c;
string board[1505];
bool swan_visited[1505][1505];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<pair<int, int>> waterQ, next_waterQ;
queue<pair<int, int>> swanQ, next_swanQ;
pair<int, int> swan_start, swan_target;

bool move_swan() {
    while (!swanQ.empty()) {
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();

        if (y == swan_target.first && x == swan_target.second) return true;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
                if (!swan_visited[ny][nx]) {
                    swan_visited[ny][nx] = true;
                    if (board[ny][nx] == '.' || board[ny][nx] == 'L') {
                        swanQ.push({ny, nx});
                    } 
                    else if (board[ny][nx] == 'X') {
                        next_swanQ.push({ny, nx});
                    }
                }
            }
        }
    }
    return false;
}

void melt_ice() {
    while (!waterQ.empty()) {
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
                if (board[ny][nx] == 'X') {
                    board[ny][nx] = '.';
                    next_waterQ.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    cin >> r >> c;

    bool found_first_swan = false;

    for (int i = 0; i < r; i++) {
        cin >> board[i];
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '.' || board[i][j] == 'L') {
                waterQ.push({i, j});
            }
            if (board[i][j] == 'L') {
                if (!found_first_swan) {
                    swan_start = {i, j};
                    found_first_swan = true;
                } else {
                    swan_target = {i, j};
                }
            }
        }
    }

    swanQ.push(swan_start);
    swan_visited[swan_start.first][swan_start.second] = true;

    int days = 0;

    while (true) {
        if (move_swan()) {
            cout << days << '\n';
            break;
        }

        melt_ice();

        waterQ = next_waterQ;
        swanQ = next_swanQ;
        
        while(!next_waterQ.empty()) next_waterQ.pop();
        while(!next_swanQ.empty()) next_swanQ.pop();

        days++;
    }

    return 0;
}