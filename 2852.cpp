#include <bits/stdc++.h>

using namespace std;

int curr_win;
int n;
map<int, int> score;
queue<pair<int, int>> q;
int curr, goal_time, win_time_1, win_time_2;
string s;
// 무승부일 때 현재 승자를 바꿔주지 않아서 생긴 문제였음
// 반례
// 1 00:00
// 2 00:01
// 1 00:02
int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> curr;
    cin >> s;
    score[curr]++;
    if (score[1] > score[2] && curr_win != 1) {
      curr_win = 1;
      goal_time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
      q.push({curr_win, goal_time});
    }
    else if (score[2] > score[1] && curr_win != 2) {
      curr_win = 2;
      goal_time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
      q.push({curr_win, goal_time});
    } else if (score[1] == score[2]) {
      goal_time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
      q.push({curr_win, goal_time});
      curr_win = 0;
    }
  }
  score.clear();

  while (q.size()) {
    tie(curr, goal_time) = q.front();
    q.pop();
    if (!q.empty()) {
      int next_goal_time;
      next_goal_time = q.front().second;
      score[curr] += (next_goal_time - goal_time);
      q.pop();
    } else {
      score[curr] += (48 * 60 - goal_time);
    }
  }

  printf("%02d:%02d\n", score[1] / 60, score[1] % 60);
  printf("%02d:%02d\n", score[2] / 60, score[2] % 60);
}