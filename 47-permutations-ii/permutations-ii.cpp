class Solution {
public:
vector<vector<int>> ans;
void solve(vector<int>& nums,vector<int>& temp,vector<int>& used){
   
    if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
            continue;
            if(used[i] == 0) {
                temp.push_back(nums[i]);
                used[i] = 1;

                solve(nums, temp, used);
                temp.pop_back();
                used[i] = 0;
            }
        }

}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int> temp;
    vector<int> used(nums.size(), 0);

      solve(nums, temp, used);

        return ans;

    }
};