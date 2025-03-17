#include <bits/stdc++.h>

using namespace std;

int parking_time[104];
int a, b, c, from, to, cost;
int main() {
  cin >> a >> b >> c;
  for(int i = 0; i < 3; i++) {
    cin >> from >> to;
    for(int j = from; j < to; j++) {
      parking_time[j]++;
    }
  }
  for(int i = 0; i < 101; i++) {
    if (parking_time[i] == 0) {
      continue;
    } else if (parking_time[i] == 1) {
      cost += a * parking_time[i];
    } else if (parking_time[i] == 2) {
      cost += b * parking_time[i];
    } else if (parking_time[i] == 3) {
      cost += c * parking_time[i];
    }
  }
  cout << cost;

}