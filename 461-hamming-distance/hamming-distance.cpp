class Solution {
public:
    int hammingDistance(int x, int y) {
        int count =0;
       long long num =x^y;
        while(num!=0){
            if(num%2==1){
                count++;
            }
            num/=2;
        }
        
    return count; }
};