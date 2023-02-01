#include <bits/stdc++.h>

#define ll long long

using namespace std;


bool comp(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second > b.second;
}

int main(int, char **) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll n, count = 0;
  cin >> n;
  unordered_map<ll, vector<pair<ll, ll>>> segments;
  for (ll i = 0; i < n; i++) {
    ll x, s, e;
    cin >> x >> s >> e;
    segments[x].emplace_back(make_pair(s, e));
  }

  for (auto &[x, list] : segments) {
    sort(list.begin(), list.end(), comp);
    auto it = list.begin();
    while (it != list.end()) {
      ll max = it->second;
      ll num = 0;
      while (it != list.end() && max >= it->first) {
        count += num;
        num++;
        it++;
      }
    }
  }


  cout << count << "\n";


  return 0;
}
