#include "template.hpp"

/**
 * Source: https://leetcode.com/problems/product-of-array-except-self/
 * Brief: We find the prefix product and the suffix product
 * /1, 2, 3, 4, 5, 6, 7, 8/ i = 3
 * /prefixProduct(1, 2, 3), (4), suffixProduct(5, 6, 7, 8)/
 * Time: O(N)
 * Space: O(N)
 */

/**
 * Brief: we can do better in terms of memory
 * We calculate prefix product and assign them in the result array
 * Then we calculate suffix product from right and assign them in the result array
 * Time: O(N)
 * Space: O(1)
 */
vv<int> productExceptSelf(vv<int> &nums)
{
    int n = nums.size();
    vv<int> ans(n, 1);
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] *= prod;
        prod *= nums[i];
    }

    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= prod;
        prod *= nums[i];
    }

    return ans;
}

int main()
{
    vv<int> nums = {1, 2, 3, 4};
    vv<int> ans = productExceptSelf(nums);
    FOR2(i, ans)
    std::cout << i << " ";

    return 0;
}