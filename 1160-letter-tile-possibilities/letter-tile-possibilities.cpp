class Solution {
public:
    int n;

    void solve(string& tiles, vector<bool>& used,
               string& temp, unordered_set<string>& ans) {

        ans.insert(temp);

        for(int i = 0; i < n; i++) {

            if(used[i])
                continue;

            used[i] = true;
            temp.push_back(tiles[i]);

            solve(tiles, used, temp, ans);

            used[i] = false;
            temp.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.length();

        vector<bool> used(n, false);
        string temp = "";
        unordered_set<string> ans;

        solve(tiles, used, temp, ans);

        return ans.size() - 1;
    }
};