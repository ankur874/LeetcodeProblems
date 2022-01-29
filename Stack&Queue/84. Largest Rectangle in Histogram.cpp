class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        // stack<int>s;
        vector<int>smallerPrefix(n);
        smallerPrefix[0]=-1;
        // s.push(0);
        for(int i=1;i<heights.size();i++){
              int p=i-1;
              while(p>=0&&heights[p]>=heights[i]){
                  p=smallerPrefix[p];
              }
              smallerPrefix[i]=p;
        }
        for(int val:smallerPrefix){
            cout<<val<<" ";
        }
        // stack<int>s1;
        vector<int>smallerSuffix(n);
        // s1.push(n-1);
        smallerSuffix[n-1]=n;
        for(int i=n-2;i>=0;i--){
              int p=i+1;
              while(p<n&&heights[p]>=heights[i]){
                  p=smallerSuffix[p];
              } 
              smallerSuffix[i]=p;
        }
        for(int val:smallerSuffix){
            cout<<val<<" ";
        }
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int currentArea=heights[i]*((smallerSuffix[i]-1)-(smallerPrefix[i]+1)+1);
            maxArea=max(maxArea,currentArea);
        }
        return maxArea;
    }
};