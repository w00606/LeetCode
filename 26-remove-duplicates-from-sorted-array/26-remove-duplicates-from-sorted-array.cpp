class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int repeated = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i + 1 + repeated >= nums.size()) {
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
        return nums.size() - repeated;
    }
};