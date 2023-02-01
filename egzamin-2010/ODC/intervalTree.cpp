#include <map>
#include <set>
#include <iostream>

class IntervalTree
{
    struct Interval
    {
        int left, right;
        Interval(int l, int r) : left(l), right(r) {}
    };

    struct IntervalComp
    {
        bool operator()(const Interval& a, const Interval& b) const
        {
            return a.right < b.right;
        }
    };

    std::map<Interval, std::set<Interval, IntervalComp>, IntervalComp> tree;

public:
    void insert(int left, int right)
    {
        Interval interval(left, right);
        tree[interval].insert(interval);
    }

    std::set<Interval, IntervalComp> search(int left, int right)
    {
        auto it = tree.lower_bound({left, 0});
        std::set<Interval, IntervalComp> result;
        while (it != tree.end() && it->first.left <= right)
        {
            for (const auto& interval : it->second)
            {
                if (interval.right >= left)
                {
                    result.insert(interval);
                }
            }
            ++it;
        }
        return result;
    }
};

int main()
{
    IntervalTree tree;
    tree.insert(1, 5);
    tree.insert(3, 8);
    tree.insert(2, 6);
    tree.insert(10, 15);
    tree.insert(11, 13);
    tree.insert(12, 14);

    auto result = tree.search(4, 7);
    for (const auto& interval : result)
    {
        std::cout << "[" << interval.left << ", " << interval.right << "]" << std::endl;
    }

    return 0;
}