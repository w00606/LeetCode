class Solution {
public:
    vector<int> nums;
  
    bool isHappy(int n) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == n) {
                return false;
            }
        }
        nums.push_back(n);
        while (n >= 10) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        sum += n * n;
        if (sum == 1) {
            return true;
        }
        else {
            return isHappy(sum);   
        }
    }
};