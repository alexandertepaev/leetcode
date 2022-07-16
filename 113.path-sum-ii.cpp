/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <iostream>

class Solution
{
public:
    typedef std::vector<int> vi_t;
    typedef std::vector<vi_t> vvi_t;

    vvi_t pathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr)
        {
            return vvi_t();
        }

        vvi_t vvi;
        if (root->left == nullptr && root->right == nullptr &&
            root->val == targetSum)
        {
            vi_t vi;
            vi.push_back(root->val);
            vvi.push_back(vi);
        }
        else
        {
            vvi_t vvi_l;
            if(root->left != nullptr)
                vvi_l = pathSum(root->left, targetSum - root->val);

            vvi_t vvi_r;
            if(root->right != nullptr)
                vvi_r = pathSum(root->right, targetSum - root->val);

            vvi = vvi_l;
            vvi.insert(vvi.end(), vvi_r.begin(), vvi_r.end());

            vvi_t::iterator it = vvi.begin();
            for(; it != vvi.end(); ++it)
            {
                it->insert(it->begin(), root->val);
            }
        }
        
        return vvi;
    }
};
// @lc code=end

