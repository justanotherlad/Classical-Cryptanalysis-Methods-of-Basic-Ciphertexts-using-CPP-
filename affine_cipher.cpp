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
  char A[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
              'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  ll vx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (ll i = 0; i < s.size(); i++) {
    vx[s[i] - 'A']++;
  }
  for (ll i = 0; i < 26; i++) {
    cout << A[i] << " : " << vx[i] << endl;
  }

  for (ll i = 0; i < s.size(); i++) {
    s[i] = char((11 * ((int)s[i] - 65) + 8) % 26 + 65 + 32);
  }
  cout << endl << s;
}