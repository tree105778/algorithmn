#include <bits/stdc++.h>

using namespace std;

int n, ret = numeric_limits<int>::min();
string s;
vector<int> nums;
vector<char> ops;

int calculate(int num1, int num2, char op) {
  switch (op) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
  }
}

void dfs(int val, int op_idx) {
  if (op_idx >= ops.size()) {
    if (val > ret) ret = val;
    return;
  }

  dfs(calculate(val, nums[op_idx + 1], ops[op_idx]), op_idx + 1);
  if (op_idx + 1 < ops.size()) {
    int next_val = calculate(nums[op_idx + 1], nums[op_idx + 2], ops[op_idx + 1]);
    dfs(calculate(val, next_val, ops[op_idx]), op_idx + 2);
  }
}

int main() {
  cin >> n;
  cin >> s;
  for(auto ch: s) {
    int num = ch - '0';
    if (num >= 0 && num <= 9) nums.push_back(num);
    else ops.push_back(ch);
  }

  dfs(nums[0], 0);
  cout << ret;
}