#include <bits/stdc++.h>

using namespace std;

vector<int> temp;
int p_sum[100004];
int n, k, a, current_sum, max_sum = -10000004;
int main() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a;
    p_sum[i] = p_sum[i - 1] + a;
  }
  
  for(int i = k; i <= n; i++) { 
    current_sum = p_sum[i] - p_sum[i - k];
    if (current_sum > max_sum) max_sum = current_sum;
  }
  cout << max_sum;
}