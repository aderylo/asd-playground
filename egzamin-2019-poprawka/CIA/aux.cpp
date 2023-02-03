#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main(int, char **) {
  set<int> elems = {0, 3, 12};

  int before = *upper_bound(elems.begin(), elems.end(), 3);

  cout << before << "\n";


  return 0;
}
