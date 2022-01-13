class Solution {

public:
    // comparator function for sorting 2D vector in decending order
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }   
    int findMinArrowShots(vector<vector<int>>& points) {
        // if there is no balloons then, our answer will be zero
        if(points.size()==0) return 0;
        // if only one baloons is present, then only one arrow is required
        if(points.size()==1) return 1;
        
        // sort the 2D vector
        sort(points.begin(), points.end(), comp);
        
        
        int arrows = 1;
        int prev = points[0][1];
        
        
        for(int i = 1; i < points.size(); i++){
            
            if(points[i][0] <= prev)
                continue;
            
            // Otherwise extra arrow is required
            arrows++;
            prev = points[i][1];
        }
        // at the end return answer
        return arrows;
    }
};