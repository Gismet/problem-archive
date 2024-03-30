#include "template.hpp"

/*equivalent proble: count the number of subarrays with at most k distinct elements*/

//Expand the window as long as it meets the codition
//For each window, calcualte r - l + 1, which gives the number of such subarrays ending at r 
//and starting at any index from l to r
//To find only the subarrays with exactly k distinct elements, use the following
// #subarrays with exactly k distinct elements = #subarrays with at most k distinct elements - #subarrays with at most k - 1 distinct subarrays
//This isolates the subarrays with exactly k distinct elements from those with at most k distinct elements


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