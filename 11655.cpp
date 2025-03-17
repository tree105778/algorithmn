#include <bits/stdc++.h>

using namespace std;

string str;
int main() {
  getline(cin, str);
  for(int i = 0; i < str.size(); i++) {
    if (isupper(str[i])) {
      int idx = str[i] - 'A';
      if (idx < 13) str[i] = idx + 13 + 'A';
      else str[i] = idx - 13 + 'A';
    } else if (islower(str[i])) {
      int idx = str[i] - 'a';
      if (idx < 13) str[i] = idx + 13 + 'a';
      else str[i] = idx - 13 + 'a';
    }
  }
  cout << str;
}