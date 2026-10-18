#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int board[5][5];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    int max_score = 0;
    int total_cells = n * m;

    for (int s = 0; s < (1 << total_cells); s++) {
        int total_sum = 0;

        for (int r = 0; r < n; r++) {
            int current_num = 0;
            for (int c = 0; c < m; c++) {
                int k = r * m + c;
                
                if ((s & (1 << k)) == 0) {
                    current_num = current_num * 10 + board[r][c];
                } 
                else {
                    total_sum += current_num;
                    current_num = 0;
                }
            }
            total_sum += current_num;
        }

        for (int c = 0; c < m; c++) {
            int current_num = 0;
            for (int r = 0; r < n; r++) {
                int k = r * m + c;
                
                if ((s & (1 << k)) != 0) {
                    current_num = current_num * 10 + board[r][c];
                } 
                else {
                    total_sum += current_num;
                    current_num = 0;
                }
            }
            total_sum += current_num;
        }

        max_score = max(max_score, total_sum);
    }

    cout << max_score << '\n';

    return 0;
}