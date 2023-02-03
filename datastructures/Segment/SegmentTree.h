#include <algorithm>
#include <vector>

class SegmentTree {
 public:
  SegmentTree(const std::vector<int>& nums) {
    n = nums.size();
    data.resize(n * 4);
    build(nums, 0, 0, n - 1);
  }

  void update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
  }

  int query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }

 private:
  int n;
  std::vector<int> data;

  void build(const std::vector<int>& nums, int u, int l, int r) {
    if (l == r) {
      data[u] = nums[l];
      return;
    }
    int mid = l + r >> 1;
    build(nums, u * 2 + 1, l, mid);
    build(nums, u * 2 + 2, mid + 1, r);
    data[u] = std::min(data[u * 2 + 1], data[u * 2 + 2]);
  }

  void update(int u, int l, int r, int idx, int val) {
    if (l == r) {
      data[u] = val;
      return;
    }
    int mid = l + r >> 1;
    if (idx <= mid)
      update(u * 2 + 1, l, mid, idx, val);
    else
      update(u * 2 + 2, mid + 1, r, idx, val);
    data[u] = std::min(data[u * 2 + 1], data[u * 2 + 2]);
  }

  int query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return data[u];
    int mid = l + r >> 1, res = 2147483647;
    if (ql <= mid)
      res = std::min(res, query(u * 2 + 1, l, mid, ql, qr));
    if (qr > mid)
      res = std::min(res, query(u * 2 + 2, mid + 1, r, ql, qr));
    return res;
  }
};
