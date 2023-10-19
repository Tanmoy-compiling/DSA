/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        vector<int> temp(edges.size() + 1, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            temp[edges[i][0]]++;
            temp[edges[i][1]]++;
        }
        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] == edges.size())
                return i;
        }
        return 1;
    }
};
// @lc code=end
