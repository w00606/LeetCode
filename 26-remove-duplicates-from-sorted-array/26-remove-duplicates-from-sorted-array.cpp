class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int arr_len = nums.size();
        for (int i = 0; i < arr_len - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                for (int j = i + 1; j < arr_len - 1; ++j) {
                    nums[j] = nums[j+1];
                }
                --i;
                --arr_len;
            }
        }
        return arr_len;
    }
};