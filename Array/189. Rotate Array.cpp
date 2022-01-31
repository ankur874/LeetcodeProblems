class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //n->13
        //k->4
        // i=0 n-k+i->9 nums[9]
        // i=1 n-k+i->10 nums[10]
        // i=2 n-k+i->11 nums[11]
        // i=3 n-k+i->12 nums[12]
        // if k is very larger
        int n=nums.size();
        if(k==0){
            return;
        }
        k=k%n;
        vector<int>temp(k);
        for(int i=0;i<k;i++){
            temp[i]=(nums[n-k+i]);
        }
        // 10 11 12 13
        int t=0;
        for(int i=0;i<n;i++){
            swap(nums[i],temp[t++]);
            if(t==temp.size()){
                t=0;
            }
        }
        return;
    }
};