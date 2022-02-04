class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.begin(),milestones.end(),greater<int>());
        long long largerSum=milestones[0];
        long long smallerSum=0;
        for(int i=1;i<milestones.size();i++){
            smallerSum+=milestones[i];
        }
        if(smallerSum>=largerSum){
            return smallerSum+largerSum;
        }
        long long tSum=smallerSum+largerSum;
        long long x=largerSum-smallerSum-1;
        return tSum-x;
    }
};