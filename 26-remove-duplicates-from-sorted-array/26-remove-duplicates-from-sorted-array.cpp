class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int arr_len = nums.size();
        int repeated = 0;
        for (int i = 0; i < arr_len - 1; ++i) {
            if (i + 1 + repeated >= arr_len) {
                break;
            }
            if (nums[i] == nums[i + 1 + repeated]) {
                ++repeated;
                --i;
            }
            else {
                nums[i + 1] = nums[i + 1 + repeated];    
            }
        }
        return arr_len - repeated;
    }
};