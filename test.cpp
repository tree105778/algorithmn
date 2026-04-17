#include <bits/stdc++.h>

using namespace std;

const int n = 4;
string a[4] = {"사과", "딸기", "포도", "배"};

string go(int num) {
    string ret = "";
    for(int i = 0; i < n; i++) {
        if (num & (1 << i)) ret += (a[i] + " ");
    }

    return ret;
}

int main() {
    for(int i = 0; i < (1 << n); i++) {
        cout << go(1 | i) << '\n';
    }

    return 0;
}