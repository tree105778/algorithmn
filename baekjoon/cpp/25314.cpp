#include <bits/stdc++.h>

using namespace std;

int n;
string result;
int main() {
  cin >> n;
  for(int i = 0; i < n / 4; i++) result += "long ";
  cout << result << "int";

  return 0;
}