class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ex=n*(n+1)/2;
        int act=0;
        for(int num:nums){
            act+=num;
        }
        return ex-act;

    }
};