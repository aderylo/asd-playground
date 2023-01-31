#include <iostream>
#include <vector>

#define ll long long

using namespace std;


ll number[1'000'000] = {0};

int main(int, char **) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll n, a, counter = 0;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    cin >> a;
    if (number[a] == 0) {
      number[a] = 1;
      counter++;
    } else {
      while (number[a] == 1) {
        number[a] = 0;
        counter--;
        a++;
      }

      number[a] = 1;
      counter++;
    }

    cout << counter << "\n";
  }


  return 0;
}
