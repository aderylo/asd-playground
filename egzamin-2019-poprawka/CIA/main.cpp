#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main(int, char **) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);


  ll n, m, x;
  cin >> n >> m;

  set<ll> elems = {0, n};
  multiset<ll> distances = {n};
  vector<ll> distance_to_next_elem(n + 1, 0);
  distance_to_next_elem[0] = n;

  for (ll i = 0; i < m; i++) {
    cin >> x;
    auto before = *lower_bound(elems.begin(), elems.end(), x);
    auto next = *upper_bound(elems.begin(), elems.end(), x);
    if (before == x)
      continue;


    ll new_distance = x - before;
    auto itr = distances.find(distance_to_next_elem[before]);
    if (itr != distances.end()) {
      distances.erase(itr);
    }
    distance_to_next_elem[before] = new_distance;
    distance_to_next_elem[x] = next - x;
    distances.insert(new_distance);
    distances.insert(next - x);
    elems.insert(x);

    cout << *distances.rbegin() << "\n";
  }


  return 0;
}
