// https://leetcode.com/problems/backspace-string-compare/

// Backspace String Compare

// time complexity O(n+m) and space complexity O(n+m)
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int hashcount = 0;
        string p, q;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '#')
            {
                hashcount++;
                continue;
            }
            if (hashcount > 0)
                hashcount--;
            else
                p.push_back(s[i]);
        }
        hashcount = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            if (t[i] == '#')
            {
                hashcount++;
                continue;
            }
            if (hashcount > 0)
                hashcount--;
            else
                q.push_back(t[i]);
        }
        cout << "p:" << p << " q:" << q;

        if (p == q)
            return true;
        return false;
    }
};