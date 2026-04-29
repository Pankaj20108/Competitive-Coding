class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>A(n,0);
        vector<int>B(n,0);
        int left_max=0;
        int right_max=0;
        for(int i=0;i<n;i++){
            left_max=max(left_max, height[i]);
            right_max=max(right_max, height[n-i-1]);
            A[i]=left_max;
            B[n-i-1]=right_max;
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(A[i], B[i])-height[i];
        }
        return water;
    }
};