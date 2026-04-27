#include <bits/stdc++.h>

using namespace std;

string subject, s1, s2;
int sub_score;
double sum, avg;

int main() {
  for(int i = 0; i < 20; i++) {
    cin >> subject >> s1 >> s2;
    int temp = stoi(s1);
    if (s2 != "P") sub_score += temp;
    if (s2 == "A+") sum += (temp * 4.5);
    else if (s2 == "A0") sum += (temp * 4.0);
    else if (s2 == "B+") sum += (temp * 3.5);
    else if (s2 == "B0") sum += (temp * 3.0);
    else if (s2 == "C+") sum += (temp * 2.5);
    else if (s2 == "C0") sum += (temp * 2.0);
    else if (s2 == "D+") sum += (temp * 1.5);
    else if (s2 == "D0") sum += (temp * 1.0);
  }

  cout << sum / sub_score;

  return 0;
}