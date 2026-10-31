class Solution {
public:
    void merge(int l, int r, int mid, vector<int>& nums) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> left(n1);
        vector<int> right(n2);

        int k = l;

        for (int i = 0; i < n1; i++) {
            left[i] = nums[k];
            k++;
        }

        for (int i = 0; i < n2; i++) {
            right[i] = nums[k];
            k++;
        }

        int i = 0, j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            }
            else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            nums[k] = left[i];
            i++;
            k++;
        }

        while (j < n2) {
            nums[k] = right[j];
            j++;
            k++;
        }
    }

    void sort(int l, int r, vector<int>& nums) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        sort(l, mid, nums);
        sort(mid + 1, r, nums);

        merge(l, r, mid, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        sort(0, nums.size() - 1, nums);
        return nums;
    }
};