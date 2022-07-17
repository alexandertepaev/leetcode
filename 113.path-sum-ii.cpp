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

#define BACKTRACKING 1

class Solution
{
public:
    typedef std::vector<int> vi_t;
    typedef std::vector<vi_t> vvi_t;

#if !BACKTRACKING
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
#else
    vvi_t pathSum(TreeNode* root, int targetSum, vi_t currentPath = vi_t())
    {
        if(root == nullptr)
            return vvi_t();

        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val != targetSum)
                return vvi_t();

            vi_t vi = currentPath;
            vi.push_back(root->val);
            vvi_t vvi;
            vvi.push_back(vi);
            return vvi;
        }

        currentPath.push_back(root->val);
        vvi_t vvi_l  = pathSum(root->left, targetSum - root->val, currentPath);
        currentPath.pop_back();

        currentPath.push_back(root->val);
        vvi_t vvi_r = pathSum(root->right, targetSum - root->val, currentPath);
        currentPath.pop_back();

        vvi_t vvi = vvi_l;
        vvi.insert(vvi.end(), vvi_r.begin(), vvi_r.end());
        return vvi;
    }
#endif
};
// @lc code=end

