
class Solution {
public:
vector<vector<int>> ans;

void solve(int i, int target, vector<int>& temp, vector<int>& candidates) {
    if(i == candidates.size()) {
        if(target == 0) {
            ans.push_back(temp);
        }
        return;
    }

    if(candidates[i] <= target) {
        temp.push_back(candidates[i]);
        solve(i, target - candidates[i], temp, candidates);
        temp.pop_back();
    }

    solve(i + 1, target, temp, candidates);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    solve(0, target, temp, candidates);
    return ans;
}
};
