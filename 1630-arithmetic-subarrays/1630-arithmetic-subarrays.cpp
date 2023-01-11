class Solution {
public:
    bool arithmetic(vector<int>& nums,int l,int r)
    {
        vector<int> v(nums.begin()+l,nums.begin()+r+1);
        sort(v.begin(),v.end());
        
        int diff=v[1]-v[0];
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i]-v[i-1]!=diff) return false;
        }
        
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
            bool res=arithmetic(nums,l[i],r[i]);
            ans.push_back(res);
        }
        
        return ans;
    }
};