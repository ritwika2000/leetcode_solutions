class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        
        sort(nums.begin(),nums.end());
        
        int i=0;
        while(i<nums.size())
        {
            int j=i+1;
            while(j<nums.size() && nums[j]-nums[i]<=1)
            {
                if(nums[j]-nums[i]==1)
                {
                    ans=max(ans,j-i+1);
                }
                j++;
            }
            
            i++;
        }
        
        return ans;
    }
};