class Solution {
public:
    
    bool recurCanJump(vector<int>& nums, vector<bool>& reachable, int idx) {
        if (idx == nums.size() - 1) {
            return true;
        }

        bool ret = false;
        for (int i = 1; i <= nums[idx]; ++i) {
            if (reachable[idx + i] == false) {
                continue;
            }
            else {
                ret = recurCanJump(nums, reachable, idx + i);
                if (ret) {
                    return true;
                }
            }
        }
        reachable[idx] = false;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<bool> reachable(nums.size(), true);
        return recurCanJump(nums, reachable, 0);
    }
};