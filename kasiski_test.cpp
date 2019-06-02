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
  vector<pair<ll, string>> v;
  v.push_back({1, "aaa"});

  for (ll i = 0; i < s.size() - 3; i++) {
    string s1;
    for (ll j = i; j < i + 3; j++) {
      s1 += s[j];
    }
    int flag = 0;
    for (ll k = 0; k < v.size(); k++) {
      if (v[k].second == s1) {
        v[k].first++;
        break;
      } else
        flag = 1;
    }
    if (flag == 1) {
      v.push_back({1, s1});
    }
  }
  sort(v.begin(), v.end());

  vector<ll> d3;
  for (ll k = 1; k <= 2; k++) {
    string s_check =
        v[v.size() - k].second;  // Change the v.size()-k to try out most
                                 // probable gcd for the max occuring trigrams
    vector<ll> d;
    for (ll i = 0; i < s.size() - 3; i++) {
      string s_new;
      for (ll j = i; j < i + 3; j++) {
        s_new += s[j];
      }
      if (s_new == s_check) d.push_back(i + 1);
    }
    vector<ll> d1;
    for (ll i = 1; i < d.size(); i++) {
      d1.push_back(d[i] - d[0]);
    }
    ll gcd = __gcd(d1[0], d1[1]);
    for (ll i = 2; i < d1.size(); i++) {
      gcd = __gcd(gcd, d1[i]);
    }
    d3.push_back(gcd);
  }

  sort(d3.begin(), d3.end());
  vector<pair<ll, ll>> d4;
  ll count = 1;
  for (ll i = 1; i < d3.size(); i++) {
    if (d3[i] == d3[i - 1])
      count++;
    else {
      d4.push_back({count, d3[i - 1]});
      count = 1;
    }
  }
  d4.push_back({count, d3[d3.size() - 1]});
  sort(d4.begin(), d4.end());

  cout << "Most probable length of key =  " << d4[d4.size() - 1].second << endl;

  ll key_size = d4[d4.size() - 1].second;

  // next we will try to predict the KEY of length key_size

  vector<ll> K;
  char A[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
              'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  for (ll i = 0; i < key_size; i++) {
    string sn;
    long double vx[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long double vy[] = {.082, .015, .028, .043, .127, .022, .020, .061, .070,
                        .002, .008, .040, .024, .067, .075, .019, .001, .060,
                        .063, .091, .028, .010, .023, .001, .020, .001};
    for (ll j = i; j < s.size(); j += key_size) {
      sn += s[j];
    }
    // cout << sn << endl;
    for (ll k = 0; k < sn.size(); k++) {
      vx[sn[k] - 'A']++;
    }
    for (ll k = 0; k < 26; k++) {
      vx[k] /= sn.size();
    }

    for (ll k = 0; k < 26; k++) {
      vx[k] = (vx[k] * vy[k] / sn.size());
    }
    long double sum = 0;
    for (ll k = 0; k < 26; k++) {
      sum += vx[k];
      vx[k] = sum;
    }
    /*for (int k = 0; k < 26; k++) {
      cout << vx[k] << " ";
    }
    cout << endl;*/
    long double vz[26];
    for (ll k = 0; k < 26; k++) {
      vz[k] = vx[k];
    }
    sort(vx, vx + 26);
    for (ll k = 0; k < 26; k++) {
      if (vz[k] == vx[25]) {
        K.push_back(k);
        break;
      }
    }
  }
  string KEY;
  for (ll i = 0; i < K.size(); i++) {
    KEY += A[K[i]];
  }
  cout << endl << KEY << endl;
}