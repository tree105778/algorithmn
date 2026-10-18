#include <bits/stdc++.h>

using namespace std;

// 1차 풀이 -> 런타임 에러
// int n;
// string pattern, s;
// int main() {
//   cin >> n >> pattern;
//   string first_slice = pattern.substr(0, pattern.find("*", 0));
//   string last_slice = pattern.substr(pattern.find("*", 0) + 1);
//   for(int i = 0; i < n; i++) {
//     cin >> s;
//     if (s.size() - last_slice.size() < 0) {
//       cout << "NE" << '\n';
//       continue;
//     }
//     string first_str = s.substr(0, first_slice.size());
//     string last_str = s.substr(s.size() - last_slice.size());
//     if (first_str == first_slice && last_str == last_slice) {
//       cout << "DA" << '\n';
//     } else cout << "NE" << '\n';
//   }
// }

// 2차 시도 -> 런타임 에러
// int n;
// string pattern, s;
// int main() {
//   cin >> n >> pattern;
//   string first_slice = pattern.substr(0, pattern.find("*", 0));
//   string last_slice = pattern.substr(pattern.find("*", 0) + 1);
//   for(int i = 0; i < n; i++) {
//     cin >> s;
//     if (s.size() - last_slice.size() < 0) {
//       cout << "NE" << '\n';
//       continue;
//     }
//     if (first_slice.size() > s.size()) {
//       cout << "NE" << '\n';
//       continue;
//     }
//     string first_str = s.substr(0, first_slice.size());
//     string last_str = s.substr(s.size() - last_slice.size());
//     if (first_str == first_slice && last_str == last_slice) {
//       cout << "DA" << '\n';
//     } else cout << "NE" << '\n';
//   }
// }

int n;
string pattern, s;
int main() {
  cin >> n >> pattern;
  int pos = pattern.find("*", 0);
  string first_slice = pattern.substr(0, pos);
  string last_slice = pattern.substr(pos + 1);
  for(int i = 0; i < n; i++) {
    cin >> s;
    if (s.size() < first_slice.size() + last_slice.size()) {
      cout << "NE" << '\n';
      continue;
    }
    string first_str = s.substr(0, first_slice.size());
    string last_str = s.substr(s.size() - last_slice.size());
    if (first_str == first_slice && last_str == last_slice) {
      cout << "DA" << '\n';
    } else cout << "NE" << '\n';
  }
}