#include <bits/stdc++.h>

using namespace std;

int n, b;
stack<int> st;
int main() {
  cin >> n >> b;

  st.push(n % b);
  while (n = (n / b)) {
    st.push(n % b);
  }

  while (!st.empty()) {
    int temp = st.top();
    if (temp < 10) cout << temp;
    else {
      char ch = temp - 10 + 'A';
      cout << ch;
    }
    st.pop();
  }

  return 0;
}