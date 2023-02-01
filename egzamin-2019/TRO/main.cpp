#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main(int, char**) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll n, result = 0;
  cin >> n;
  vector<ll> numbers(n, 0);
  vector<vector<ll>> suffix_counts(n);
  vector<vector<ll>> prefix_counts(n);

  vector<ll> prefix_count(11, 0);
  vector<ll> suffix_count(11, 0);


  for (ll i = 0; i < n; i++) {
    prefix_counts.at(i) = prefix_count;
    cin >> numbers.at(i);
    prefix_count.at(numbers.at(i))++;
  }

  for (ll i = n - 1; i >= 0; i--) {
    suffix_counts.at(i) = suffix_count;
    suffix_count.at(numbers.at(i))++;
  }

  for (ll i = 0; i < n; i++) {
    ll num = numbers.at(i);
    auto prefix = prefix_counts[i];
    auto suffix = suffix_counts[i];
    assert(prefix.size() == 11);
    assert(suffix.size() == 11);


    for (ll j = 1; j <= 10; j++) {
      if (j + num > 10)
        break;

      ll pairs = prefix.at(j) * suffix.at(j + num);
      result += pairs;
    }
  }

  cout << result << "\n";

  return 0;
}
