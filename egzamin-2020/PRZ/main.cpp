#include <bits/stdc++.h>

#define ll long long

using namespace std;


bool descending(ll x, ll y) {
  return x > y;
}

int main(int, char **) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll n, m, s, e, count = 0;
  char operation = '!';
  cin >> n >> m;

  set<ll> ends;
  set<ll> begings;
  ll max_end = 0, min_beg = n + 1;

  for (ll i = 0; i < m; i++) {
    cin >> operation >> s >> e;
    assert(s == 1 || e == n);
    if (operation == '+') {
      if (s == 1) {
        ends.insert(e);
        max_end = *ends.rbegin();
      }
      if (e == n) {
        begings.insert(s);
        min_beg = *begings.begin();
      }
    }

    if (operation == '-') {
      if (s == 1) {
        ends.erase(e);
        if (ends.empty())
          max_end = 0;
        else
          max_end = *ends.rbegin();
      }
      if (e == n) {
        begings.erase(s);

        if (begings.empty())
          min_beg = n + 1;
        else
          min_beg = *begings.begin();
      }
    }

    count = max((min_beg - max_end - 1), (ll)0);
    cout << count << "\n"; 
  }


  return 0;
}
