// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Two Sum II - Input array is sorted

// time complexity O(n) and space complexity O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        
        map<int,int> m;
        for(int i =0;i<numbers.size();i++){
            int a = target-numbers[i];
            auto it=m.find(a);
            if(it!=m.end()){
                return {it->second,i+1};
            }
            m[numbers[i]]=i+1;
        }

        return {};
    }
};