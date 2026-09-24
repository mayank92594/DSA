class Solution {
    public int smallestIndex(int[] nums) {
    int sum=0;
        // int ans=-1;
      
        for(int i=0;i<nums.length;i++){
       
            int digits=0;
            int n=nums[i];
            while(n>0){
            digits=n%10;
             sum+=digits;
            n=n/10;              
            }
           if(i==sum) {
            return i;
           }
            sum=0;

        }
        return -1;
     }  
 }
