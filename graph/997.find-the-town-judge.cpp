/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> trustCount(n + 1, 0);
        for (int i = 0; i < trust.size(); i++)
        {
            trustCount[trust[i][1]]++;
        }
        for(auto i:trustCount)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for (int i = 1; i <= n; i++)
        {
            if (trustCount[i] == n - 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
