class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxFlowers=0;
        int size=flowerbed.size();
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==1){
                continue;
            }else{
                if(i==0&&i==size-1){
                    if(flowerbed[i]!=1){
                        flowerbed[i]=1;
                        maxFlowers++;
                    }
                }
                else if(i==0){
                    if(flowerbed[i+1]!=1){
                        flowerbed[i]=1;
                        maxFlowers++;
                    }
                }
                else if(i==size-1){
                    if(flowerbed[i-1]!=1){
                        flowerbed[i]=1;
                        maxFlowers++;
                    }
                }
                else{
                    if(flowerbed[i-1]!=1&&flowerbed[i+1]!=1){
                        flowerbed[i]=1;
                        maxFlowers++;
                    }
                }
            }
        }
        return maxFlowers>=n;
    }
};