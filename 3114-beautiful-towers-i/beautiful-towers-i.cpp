class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();

        vector<long long> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();

            if (st.empty()) {
                left[i] = 1LL * maxHeights[i] * (i + 1);
            } else {
                int j = st.top();
                left[i] = left[j] + 1LL * maxHeights[i] * (i - j);
            }

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();

            if (st.empty()) {
                right[i] = 1LL * maxHeights[i] * (n - i);
            } else {
                int j = st.top();
                right[i] = right[j] + 1LL * maxHeights[i] * (j - i);
            }

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
           
            ans = max(ans, left[i] + right[i] - maxHeights[i]);
        }

        return ans;
    }
};