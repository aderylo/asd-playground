#include <bits/stdc++.h>


#define ll long long

using namespace std;


class IntervalTree {
  struct Interval {
    ll left, right;
    Interval(ll l, ll r) : left(l), right(r) {}
  };

  struct IntervalComp {
    bool operator()(const Interval& a, const Interval& b) const {
      return a.right < b.right;
    }
  };

  std::map<Interval, std::set<Interval, IntervalComp>, IntervalComp> tree;

 public:
  void insert(ll left, ll right) {
    Interval interval(left, right);
    tree[interval].insert(interval);
  }

  ll search(ll left, ll right) {
    auto it = tree.lower_bound({left, 0});
    ll result = 0;
    while (it != tree.end() && it->first.left <= right) {
      for (const auto& interval : it->second) {
        if (interval.right >= left) {
          result++;
        }
      }
      ++it;
    }
    return result;
  }
};

int main(int, char**) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll n, count = 0;
  cin >> n;
  unordered_map<ll, IntervalTree> segments;
  for (ll i = 0; i < n; i++) {
    ll x, s, e;
    cin >> x >> s >> e;
    auto overlaps = segments[x].search(s, e);
    // cout << overlaps << endl;
    count += overlaps;
    segments[x].insert(s, e);
  }

  cout << count << "\n";


  return 0;
}
