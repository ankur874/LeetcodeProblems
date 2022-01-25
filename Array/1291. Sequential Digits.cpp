class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
         int totalDigits=0;
         int temp=low;
         while(temp>0){
             totalDigits++;
             temp/=10;
         }   
         cout<<totalDigits<<"totaldigits ";
         vector<int>res;
         int number=0;
         for(int i=1;i<=totalDigits;i++){
             number+=(i*(pow(10,(totalDigits-i))));
         }
         cout<<number<<"number ";
         // res.push_back(number);
         int nextDigit=0;
         for(int i=1;i<=totalDigits;i++){
             nextDigit+=(1*(pow(10,(totalDigits-i))));
         }
         while(number>=low&&number<=high){
             res.push_back(number);
                int lastDigit=number%10;
                if(lastDigit!=9){
                      number+=nextDigit;
                }else{
                     totalDigits++;
                      number=0;
                        for(int i=1;i<=totalDigits;i++){
                         number+=(i*(pow(10,(totalDigits-i))));
                        }
                           nextDigit=0;
                            for(int i=1;i<=totalDigits;i++){
                              nextDigit+=(1*(pow(10,(totalDigits-i))));
                        }
                }
                
         }
         return res;
    }
};