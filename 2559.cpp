#include <bits/stdc++.h>

using namespace std;

vector<int> temp;
int n, k, a, current_sum;
int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a;
    temp.push_back(a);
  }
  int initial_sum = 0;
  for(int j = 0; j < k; j++) {
    initial_sum += temp[j];
  }
  int max_sum = initial_sum;
  current_sum = initial_sum;
  for(int i = 1; i <= temp.size() - k; i++) { 
    current_sum = current_sum - temp[i - 1] + temp[i + k - 1];
    if (max_sum < current_sum) {
      max_sum = current_sum;
    }
  }
  cout << max_sum;
}