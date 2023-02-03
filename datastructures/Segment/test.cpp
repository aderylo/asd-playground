#include <cassert>
#include <iostream>
#include <vector>
#include "SegmentTree.h"

int main() {
  std::vector<int> nums = {1, 3, 2, 4, 5};
  SegmentTree st(nums);

  // Test query
  assert(st.query(0, 2) == 1);
  assert(st.query(1, 3) == 2);
  assert(st.query(2, 4) == 2);

  // Test update
  st.update(2, 0);
  assert(st.query(0, 2) == 0);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
