#include <bits/stdc++.h>

using namespace std;

int n, j, k;
string s, num;
char ch;
vector<string> v;
queue<char> qu;


// 비교 동치성을 지켜야 함
bool compare(string& s1, string& s2) {
  if (s1.size() != s2.size()) return s1.size() < s2.size();
  return s1 < s2;
}

// 100자리까지 나올 수 있으므로 문자열로 처리 
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    k = 0;
    while (k < s.size()) {
      ch = s[k];
      num = "";
      j = 0;
      while (ch >= '0' && ch <= '9' && k < s.size()) {
        qu.push(ch);
        ch = s[++k];
      }
      if (qu.empty()) {
        k++;
        continue;
      }
      while (qu.size()) {
        if (qu.front() == '0' && qu.size() > 1) {
          qu.pop();
          continue;
        }
        while (!qu.empty()) {
          num += qu.front();
          qu.pop();
        }
      }
      v.push_back(num);
    }
  }

  sort(v.begin(), v.end(), compare);

  for(auto i : v) {
    cout << i << '\n';
  }
}