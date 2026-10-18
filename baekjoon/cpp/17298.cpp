#include <bits/stdc++.h>

using namespace std;

int N;
stack<int> st;
int arr[1000005];
int ret[1000005];
int main() {
  cin >> N;
  cin >> arr[0];
  for(int i = 1; i < N; i++) {
    cin >> arr[i];
  }

  ret[N - 1] = -1;
  st.push(arr[N - 1]);
  for(int i = N - 2; i >= 0; i--) {
    while (st.size()) {
      if (arr[i] < st.top()) {
        ret[i] = st.top();
        break;
      }
      st.pop();
    }
    if (st.empty()) ret[i] = -1;
    st.push(arr[i]);
  }  

  for(int i = 0; i < N; i++) {
    cout << ret[i] << ' ';
  }

}