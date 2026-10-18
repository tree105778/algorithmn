#include <bits/stdc++.h>

using namespace std;

int N, MIN = 2e9, MAX = -2e9;
int arr[15];
int op[4];

vector<int> v;

void search() {
  if (v.size() == N - 1) {
    int result = arr[0];
    for(int i = 0; i < N - 1; i++) {
      switch (v[i]) {
        case 0:
          result += arr[i + 1];
          break;
        case 1:
          result -= arr[i + 1];
          break;
        case 2:
          result *= arr[i + 1];
          break;
        case 3:
          result /= arr[i + 1];
          break;
      }
    }
    if (result > MAX) MAX = result;
    if (result < MIN) MIN = result;
  }
  for(int i = 0; i < 4; i++) {
    if (op[i] > 0) {
      op[i]--;
      v.push_back(i);
      search();
      v.pop_back();
      op[i]++;
    }
  }
}
int main() {
  cin >> N;

  for(int i = 0; i < N; i++) cin >> arr[i];
  for(int i = 0; i < 4; i++) cin >> op[i];

  search();

  cout << MAX << '\n' << MIN;
}