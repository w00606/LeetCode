class Solution {
public:
    bool search_duplicate(vector<vector<int>>& sums, vector<int>& curr_sum) {
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] == curr_sum) {
                return true;
            }
        }
        return false;
    }
    // void recur_sum (vector<int>& nums, vector<vector<int>>& sums, vector<int>& curr_sum, vector<int>& sorted_sum, int start_idx, int count) {
    //     if (count == 2) {
    //         for (int i = start_idx; i < nums.size(); ++i) {
    //             curr_sum[count] = nums[i];
    //             if (curr_sum[0] + curr_sum[1] + curr_sum[2] == 0) {
    //                 sorted_sum = curr_sum;
    //                 sort(sorted_sum.begin(), sorted_sum.end());
    //                 if (!search_duplicate(sums, sorted_sum)) {
    //                     sums.emplace_back(sorted_sum);   
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    //     else {
    //         for (int i = start_idx; i < nums.size(); ++i) {
    //             curr_sum[count] = nums[i];
    //             recur_sum(nums, sums, curr_sum, sorted_sum, i + 1, count + 1);
    //         }
    //     }
    // }
    
//     int binary_search(vector<int>& nums, int begin, int end, int k, int sumij) {
//         if (sumij + nums[k] == 0) {
//             return k;
//         }
//         else if (k == begin || k == end) {
//             return -1;
//         }
//         else if (sumij + nums[k] > 0) {
//             return binary_search(nums, begin, k, (begin + k) / 2, sumij);
//         }
//         else {
//             return binary_search(nums, k, end, (k + end) / 2, sumij);
//         }
//     }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;
        vector<int> curr_sum(3);
        //vector<int> sorted_sum(3);
        if (nums.size() < 3) {
            return sums;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            else if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] > 0) {
                    break;
                }
                else if (nums[k] < 0) {
                    break;
                }
                else if (nums[i] + nums[j] + nums[k] == 0) {
                    curr_sum = {nums[i] , nums[j], nums[k]};
                    if (!search_duplicate(sums, curr_sum)) {
                        sums.emplace_back(curr_sum);   
                    }
                    ++j;
                    --k;
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                }
                else {
                    ++j;
                }
            }
        }
        
        //recur_sum(nums, sums, curr_sum, sorted_sum, 0 /*start_idx*/, 0 /*idx in curr_sum*/);
        return sums;
    }
};