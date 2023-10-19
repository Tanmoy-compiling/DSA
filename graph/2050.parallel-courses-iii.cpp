/*
 * @lc app=leetcode id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

// @lc code=start
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        typedef pair<int,int> p;

        map<int,vector<p>> graph;
        stack<p> st;
        vector<int> visited(n+1,0);
        int res = 0;
        for(int i = 0;i<relations.size();i++){
            int a = relations[i][0];
            int b= relations[i][1];

            graph[a].push_back({b,time[a-1]});
        }

        for(auto &u : graph){
            if(visited[u.first] == 0){
                st.push({u.first,0});
                visited[u.first] = 1;
                while(!st.empty()){
                    auto cur = st.top();
                    st.pop();
                    int node = cur.first;
                    int time = cur.second;
                    res = max(res,time);
                    for(auto &v : graph[node]){
                        if(visited[v.first] == 0){
                            st.push({v.first,time+v.second});
                            visited[v.first] = 1;
                        }
                    }
                }
            }
        }
    
        // not the correct answer is returned check and revise the answer
        



        return res;
    }
};
// @lc code=end

