class Solution {
public:
    int recursion(vector<int>& nums, int l, int r, int k) {
        int mid = (l + r) >> 1;
        int pivot = nums[mid];
        int i = l, j = r;
        while (i <= j) {
            while (nums[i] > pivot) ++ i;
            while (nums[j] < pivot) -- j;
            if (i <= j) {
                swap(nums[i], nums[j]);
                if (i == mid) {
                    mid = j; 
                } else if (j == mid) {
                    mid = i; 
                }
                ++ i;
                -- j;
            }
        }
        if (k <= j) {
            return recursion(nums, l, j, k);
        } else if (k >= i) {
            return recursion(nums, i, r, k);
        }
        return nums[k];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return recursion(nums, 0, nums.size() - 1, k - 1);
    }
};
