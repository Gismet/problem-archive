#include "template.hpp"

/**
 * Insert the interval in the right place.
 * Then merge the intervals
 * Time: O(n)
 * Note: This is a little silly problem.
 */

vv<vv<int>> insert(vv<vv<int>> &intervals, vv<int> &newInterval)
{
    intervals.ins(lb(all(intervals), newInterval), newInterval);

    auto curr = intervals[0];

    vv<vv<int>> ans;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= curr[1])
        {
            curr = {std::min(intervals[i][0], curr[0]), std::max(intervals[i][1], curr[1])};
        }
        else
        {
            ans.push_back(curr);
            curr = intervals[i];
        }
    }
    ans.push_back(curr);

    return ans;
}

int main()
{
    vv<vv<int>> ints = {{1, 3}, {6, 9}};
    vv<int> interval = {2, 5};

    vv<vv<int>> ans = insert(ints, interval);

    for (auto &x : ans)
        std::cout << x[0] << " " << x[1] << '\n';

    return 0;
}