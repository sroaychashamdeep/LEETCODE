class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n;
        n=nums.size();
        int su=n*(n+1)/2;
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        int r=su-s;
        return r;

    }
    
};