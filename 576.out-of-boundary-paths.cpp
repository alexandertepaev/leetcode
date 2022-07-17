/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start

#include <vector>
#include <iostream>

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        std::vector<std::vector<int>> b;
        b.assign(m, std::vector<int>(n, 0));

        int d[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        b[startRow][startColumn] = 1;

        int res = 0;

        for(int i = 0; i < maxMove; i++)
        {
            std::vector<std::vector<int>> b_;
            b_.assign(m, std::vector<int>(n, 0));
            for(int k = 0; k < m; k++)
            {
                for(int j = 0; j < n; j++)
                {
                    for(int l = 0; l < 4; l++)
                    {
                        int nm = k + d[l][0];
                        int nn = j + d[l][1];

                        if (0 <= nm && nm < m && 0 <= nn && nn < n)
                        {
                            b_[nm][nn] += b[k][j];
                            b_[nm][nn] %= (static_cast<int>(1e9) + 7);
                        }
                        else
                        {
                            res += b[k][j];
                            res %= (static_cast<int>(1e9) + 7);
                        }
                    }
                }
            }
            b = b_;
        }
        return res % (static_cast<int>(1e9) + 7);
    }
};
// @lc code=end

