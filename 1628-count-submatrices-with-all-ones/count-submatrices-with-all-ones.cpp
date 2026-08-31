class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {

            // Build histogram
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Count submatrices ending at this row
            vector<int> st;
            vector<int> sum(n, 0);

            for (int j = 0; j < n; j++) {

                while (!st.empty() && height[st.back()] >= height[j])
                    st.pop_back();

                if (!st.empty()) {
                    int k = st.back();
                    sum[j] = sum[k] + height[j] * (j - k);
                }
                else {
                    sum[j] = height[j] * (j + 1);
                }

                ans += sum[j];
                st.push_back(j);
            }
        }

        return ans;
    }
};