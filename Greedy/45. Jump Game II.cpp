class Solution {
public:
    ////with recursion and memoization
    // int helper(vector<int>&nums,int index,vector<int>dp){
    //     if(index>=nums.size()-1){
    //         return 0;
    //     }
    //     if(dp[index]!=-1)return dp[index];
    //     int ans=100000;
    //     int maxJump=nums[index];
    //     for(int i=1;i<=maxJump;i++){
    //         ans=min(ans,1+helper(nums,index+i));
    //     }
    //     dp[index]=ans;
    //     return ans;
    // }
    /////////////////////////////////////////////////
    ////with tabular
    //must doooo
    //har ek element dp ka ye bolega bhai dekho mein apne saare path mein se
    //jha jha mein ja skta uska min laake de dunga or usko dp mein store kra dunga aage tum dekho
//     int helper2(vector<int>&nums,vector<int>dp){
//         int n=nums.size();
//         dp[n-1]=0;
//         for(int i=n-2;i>=0;i--){
//             int maxJump=nums[i];
//             int ans=1000000;
//             for(int j=1;j<=maxJump;j++){
//                 if((i+j)<=(n-1)){
//                     ans=min(ans,1+dp[j+i]);
//                 }
//             }
//             dp[i]=ans;
//         }
//         return dp[0];
        
//     }
//     int jump(vector<int>& nums) {
//         vector<int>dp(nums.size());
//         return helper2(nums,dp);
//     }
    ///////////////greeady approach
    int jump(vector<int>& nums) {
	int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
	while(lastJumpedPos < n - 1) {  // loop till last jump hasn't taken us till the end
		maxReachable = max(maxReachable, i + nums[i]);  // furthest index reachable on the next level from current level
		if(i == lastJumpedPos) {			  // current level has been iterated & maxReachable position on next level has been finalised
			lastJumpedPos = maxReachable;     // so just move to that maxReachable position
			jumps++;                          // and increment the level
	// NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
	//       This ensures jumps will only store minimum jump required to reach lastJumpedPos
		}            
		i++;
	}
	return jumps;
}
};

