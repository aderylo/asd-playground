#include <bits/stdc++.h>

#define ll long long

using namespace std;


bool descending(ll x, ll y) {
  return x > y;
}

int main(int, char **) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll n, k, s, e;
  cin >> n >> k;

  vector<char> word(n);
  vector<ll> rotation_end(n + 1, 0);

  for (ll i = 0; i < n; i++) {
    cin >> word[n];
  }

  for (ll i = 0; i < k; i++) {
    cin >> s >> e;
    if (rotation_end[s] == 0)
      rotation_end[s] = e;
    else
      rotation_end[s] = 0;
  }

  ll rotation_count = 0;
  ll current_middle = 1;
  bool between = false;

  for (ll i = 1; i <= n; i++) {
    if (rotation_end[i] == 0) {}

    if (rotation_count % 2 == 1) {
      ll swap_with = 2 * (current_middle - i) + i + (ll)between;
      char tmp = word[i - 1];
      word[i - 1] =
    }
  }
  return 0;
}
