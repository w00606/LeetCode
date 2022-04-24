class Solution {
public:
    
    void merge(vector<int>& nums, int left_start, int left_end, int right_start, int right_end) {
        while (1) {
            if (left_start > left_end || right_start > right_end) {
                break;
            }
            if (nums[left_start] > nums[right_start]) {
                for (int i = 0; i < right_start - left_start; ++i) {
                    int temp = nums[right_start - i];
                    nums[right_start - i] = nums[right_start - i - 1];
                    nums[right_start - i - 1] = temp;
                }
                ++right_start;
                ++left_start;
                ++left_end;
            }
            else {
                ++left_start;
            }
        }
    }
    
    void mergesort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        
        mergesort(nums, start, (start + end) / 2);
        mergesort(nums, (start + end) / 2 + 1, end);
        
        merge(nums, start, (start + end) / 2, (start + end) / 2 + 1, end);
        
    }
    
    void sortColors(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
    }
};