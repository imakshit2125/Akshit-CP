/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {

        set<int>s;

        for(auto it:nums)
        s.insert(it);

        if(s.size()<3)
        return *s.rbegin();
        else{
        int k=s.size()-2;
    
        for(auto it:s)
        {
            k--;
            if(k==0) 
            return it;
        }
        return 0;
        }

        
    }
};
// @lc code=end

