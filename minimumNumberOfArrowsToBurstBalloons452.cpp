#include "template.hpp"

/**
 * Note: A set of intervals in which each pair of intervals share a common point (overlap) can be 
 * burst with a single arrow
 *    [3     8]
 * [1     6]
 * [    4   7]
 * The above three intervals have an overlapping interval [4 6]. Shoot an arrow at any point in this interval
 * to burst all of the three balloons
 */


int findMinArrowShots(vv<vv<int>> &p)
{
    int cnt = 0;
    SORT(p);
    vv<int> curr = p[0];
    for (int i = 1; i < (int)p.size(); i++)
    {
        if (std::max(p[i][0], curr[0]) <= std::min(p[i][1], curr[1]))
        {
            curr = {std::max(p[i][0], curr[0]), std::min(p[i][1], curr[1])};
        }
        else
        {
            cnt++;
            curr = p[i];
        }
    }
    cnt++;

    return cnt;
}

int main()
{
    vv<vv<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    std::cout << findMinArrowShots(points);

    return 0;
}