/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

#include <vector>

class Solution
{
public:
    typedef std::vector<int> vi_t;
    typedef std::vector<std::vector<int>> vvi_t;

#if 0
    vvi_t permute(vi_t& nums)
    {
        vvi_t ret;

        if(nums.size() == 1)
        {
            ret.push_back(nums);
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                int n = nums[nums.size()-1];
                nums.pop_back();
                vvi_t ret1 = permute(nums);
                for(std::vector<int>& e: ret1)
                {
                    e.insert(e.begin(), n);
                }
                ret.insert(ret.end(), ret1.begin(), ret1.end());
                nums.insert(nums.begin(), n);
            }
        }

        return ret;
    }
#else
    void calcPerms(vi_t& nums, int k, vvi_t& perms)
    {
        if(k == nums.size())
        {
            perms.push_back(nums);
        }

        for(int i = k; i < nums.size(); i++)
        {
            std::swap(nums[i], nums[k]);
            calcPerms(nums, k+1, perms);
            std::swap(nums[i], nums[k]);
        }
    }

    vvi_t permute(vi_t& nums)
    {
        vvi_t ret;
        calcPerms(nums, 0, ret);
        return ret;
    }
#endif
};
// @lc code=end

