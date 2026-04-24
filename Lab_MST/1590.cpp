class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        int n=nums.size();
        if(sum%p==0){
            return 0;
        }
        unordered_map<int,int>m;
        int rem=sum%p;
        int minlen=n;
        m[0]=-1;
        long long prefix=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int val=prefix%p;
            int mod=(val-rem+p)%p;
            if(m.find(mod)!=m.end()){
                minlen=min(minlen, i-m[mod]);
            }
            m[val]=i;  
        }
        if(minlen==n) return -1;
        return minlen;
        
    }
};
