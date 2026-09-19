class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        long long minimumSum = 0;

        for (int i = 0; i < n; i++) {

            long long l = i - left[i];
            long long r = right[i] - i;

            minimumSum += (long long)nums[i] * l * r;
        }



        vector<int> lef(n), righ(n);

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty())
                lef[i] = -1;
            else
                lef[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty())
                righ[i] = n;
            else
                righ[i] = st.top();

            st.push(i);
        }

        long long maximumSum = 0;

        for (int i = 0; i < n; i++) {

            long long l = i - lef[i];
            long long r = righ[i] - i;

            maximumSum += (long long)nums[i] * l * r;
        }

        return maximumSum - minimumSum;
    }
};