#include <bits/stdc++.h>
using namespace std;
string s;
int vowel;
bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  cin >> s;
  while (s != "end") {
    bool second_flag = true;
    bool third_flag = true;
    vowel = 0;
    for(int i = 0; i < s.size(); i++) {
      if (isVowel(s[i]) && !vowel) vowel++;
      if ((isVowel(s[i]) == isVowel(s[i + 1])) && (isVowel(s[i + 1]) == isVowel(s[i + 2])) && i < s.size() - 2) second_flag = false;
      if ((s[i] == s[i + 1]) && i < s.size() - 1) {
        if (s[i] == 'e' || s[i] == 'o') {
          third_flag = true;
        } else third_flag = false;
      }

    }
    if (vowel && second_flag && third_flag) cout << '<' << s << '>' << " is acceptable." << '\n';
    else cout << '<' << s << '>' << " is not acceptable." << '\n';
    cin >> s;
  }
}