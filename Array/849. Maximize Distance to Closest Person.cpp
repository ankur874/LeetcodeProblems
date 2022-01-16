class Solution {
public:
    //this is brute force solution 
    int maxDistToClosest(vector<int>& seats) {
        int ans=INT_MIN;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==0){
                int leftClosest=INT_MAX;
                for(int a=i;a>=0;a--){
                    if(seats[a]==1){
                        leftClosest=a;
                        break;
                    }
                }
                int rightClosest=INT_MAX;
                for(int a=i;a<seats.size();a++){
                    if(seats[a]==1){
                        rightClosest=a;
                        break;
                    }
                }
                int moreClosest=min(abs(i-leftClosest),abs(i-rightClosest));
                ans=max(ans,moreClosest);
            }
        }
        return ans;
        
    }
};
//////////this is a very good solution --> below wala
// class Solution {
//     public int maxDistToClosest(int[] seats) {
//         int N = seats.length;
//         int K = 0; //current longest group of empty seats
//         int ans = 0;

//         for (int i = 0; i < N; ++i) {
//             if (seats[i] == 1) {
//                 K = 0;
//             } else {
//                 K++;
//                 ans = Math.max(ans, (K + 1) / 2);
//             }
//         }

//         for (int i = 0; i < N; ++i)  if (seats[i] == 1) {
//             ans = Math.max(ans, i);
//             break;
//         }

//         for (int i = N-1; i >= 0; --i)  if (seats[i] == 1) {
//             ans = Math.max(ans, N - 1 - i);
//             break;
//         }

//         return ans;
//     }
// }