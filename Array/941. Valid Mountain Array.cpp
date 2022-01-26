class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
        int maxElementIndex=-1;
        int maxElement=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(maxElement>arr[i]){
                maxElement=arr[i];
                maxElementIndex=i;
            }
        }
        if(maxElementIndex==0||maxElementIndex==arr.size()-1){
            return false;
        }
        for(int i=maxElementIndex;i<arr.size()-1;i++){
            if(arr[i]-arr[i+1]<=0){
                return false;
            }
        }
        for(int i=maxElementIndex;i>0;i--){
            if(arr[i]-arr[i-1]<=0){
                return false;
            }
        }
        return true;
    }
};