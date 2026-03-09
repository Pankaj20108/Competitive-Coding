class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0||k==1) return 0;
        int count=0;
        long long prod=1;
        int first=0;
        int second=0;
        while(second<nums.size()){
            prod*=nums[second];
            while(prod>=k){
                prod/=nums[first];
                first++;
            }
            count+=(second-first+1);
            second++;
        }
        return count;
        
    }
};