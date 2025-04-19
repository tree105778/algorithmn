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
  // for(int i = 0; i < str.size(); i++) {
  //   if (s[i] >= 65 && s[i] < 97) {
  //     if (s[i] + 13 > 90) s[i] = s[i] + 13 - 26;
  //     else s[i] += 13;
  //   } else if (s[i] >= 97 && s[i] <= 122) {
  //     if (s[i] + 13 > 122) s[i] = s[i] + 13 - 26;
  //     else s[i] += 13;
  //   }
  // }
  cout << str;
}