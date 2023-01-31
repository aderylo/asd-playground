#include <iostream>
#include <unordered_map>

#define ll long long

using namespace std;

int main(int, char**) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  bool found_it = false;
  ll n, d, tmp;
  unordered_map<ll, ll> numbers;
  cin >> n;
  cin >> d;

  for (size_t i = 0; i < n; i++) {
    cin >> tmp;
    numbers[tmp]++;
  }

  for (auto& elem : numbers) {
    if (numbers.find(elem.first - d) != numbers.end()) {
      if (d != 0 || elem.second > 1) {
        found_it = true;
        cout << elem.first << " " << elem.first - d << "\n";
        break;
      }
    }
  }


  if (!found_it)
    cout << "NIE\n";


  return 0;
}
