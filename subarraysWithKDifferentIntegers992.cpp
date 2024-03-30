#include "template.hpp"

int withAtMostK(vv<int> &nums, int k)
{
    int res = 0, l = 0, n = int(nums.size()), x = 0;
    hashMap<int, int> cnt;

    for(int r = 0; r < n; r++)
    {
        if(cnt[nums[r]]++ == 0) x++;
        for(; x > k; l++)
        {
            if(--cnt[nums[l]] == 0) x--;
        }
        res += r - l + 1;
    }

    return res;
}

int subarraysWithKDistinct(vv<int> &nums, int k)
{
    return withAtMostK(nums, k) - withAtMostK(nums, k - 1);
}

int main()
{
    vv<int> nums = {1,2,1,2,3};
    int k = 2;
    std::cout << subarraysWithKDistinct(nums, k);

    return 0;
}