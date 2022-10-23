class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int res=accumulate(nums.begin(),nums.end(),0);
        set<int> s;
        for(auto x:nums)
        {
            s.insert(x);
        }
        
        int sum=accumulate(s.begin(),s.end(),0);
        
        int repe=res-sum;
        int n=nums.size();
        int l=n*(n+1)/2 - sum;
        
        return {repe,l};
    }
};