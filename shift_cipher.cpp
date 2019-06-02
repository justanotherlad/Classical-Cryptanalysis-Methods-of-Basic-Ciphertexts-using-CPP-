#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// author:Swastik Banerjee

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifndef ONLINE_JUDGE
  FILE *f1 = freopen("input.txt", "r", stdin);
  FILE *f2 = freopen("output.txt", "w", stdout);
#endif

  string s;
  cin >> s;
  string s1 = s;
  for (int k = 0; k <= 25; k++) {
    for (ll i = 0; i < s.size(); i++) {
      s1[i] = (char)((int)s[i] - k);
      if ((int)s1[i] < 65) s1[i] = (char)((int)s1[i] + 26);
    }
    for (ll i = 0; i < s1.size(); i++) {
      cout << (char)((int)s1[i] + 32);
    }
    cout << endl;
  }
}