class Solution {
public:
    vector<string> ans;

    void solve(string &temp, int n) {

        int depth = 0;

        for (char ch : temp) {
            if (ch == '(')
                depth++;
            else
                depth--;

            if (depth < 0)
                return;
        }

        if (temp.size() == 2 * n) {
            if (depth == 0)
                ans.push_back(temp);

            return;
        }

        // Take '('
        temp.push_back('(');
        solve(temp, n);
        temp.pop_back();

        // Take ')'
        temp.push_back(')');
        solve(temp, n);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(temp, n);
        return ans;
    }
};