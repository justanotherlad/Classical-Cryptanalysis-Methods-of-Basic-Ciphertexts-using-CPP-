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
  for (int k = 0; k < 26; k++) {
    string s1 = s;
    int tmp = k;
    for (ll i = 0; i < s1.size(); i++) {
      int z = (int)s[i] - tmp - 65;
      if (z < 0) z += 26;
      tmp = z;
      // cout << tmp << " ";
      s1[i] = char(z + 65 + 32);
    }
    cout << s1 << endl;
  }
}