
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums;

        for(int i=0; i<=n; i++){
            int count = 0;//reset at eevry iteration
            int num = i;

            while(num != 0){
                if(num % 2 == 1){
                    count++;
                }
                num = num / 2;
            }

            nums.push_back(count);
        }

        return nums;
    }
};