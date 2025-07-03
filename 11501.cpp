#include <bits/stdc++.h>

using namespace std;

// 반례
// 1
// 9
// 8 5 3 8 10 7 5 5 2

int t, n, arr[1000004];
queue<int> qu;
int main() {
  cin >> t;
  
  for(int i = 0; i < t; i++) {
    long ret = 0;
    int max_num = 0;
    memset(arr, 0, sizeof(arr));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = n - 1; i > 0; i--) {
      if (arr[i] > max_num) max_num = arr[i];
      if (max_num > arr[i - 1]) ret += (max_num - arr[i - 1]);
    }
    cout << ret << '\n';
  }
}