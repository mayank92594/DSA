class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, int n, int k, vector<int>& temp) {

        if(temp.size() == k) {
            if(n == 0)
                ans.push_back(temp);
            return;
        }

        if(i > 9 || n < 0)
            return;

        if(i <= n) {
            temp.push_back(i);
            solve(i + 1, n - i, k, temp);
            temp.pop_back();
        }

        solve(i + 1, n, k, temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1, n, k, temp);
        return ans;
    }
};