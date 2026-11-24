class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans =0;
        for(auto ite :mp){
            if(ite.second==1){
                 ans=ite.first;
            }

        }
        return ans;
    }
};