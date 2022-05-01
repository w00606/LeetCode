class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].compare("+") == 0 || tokens[i].compare("-") == 0 
                || tokens[i].compare("*") == 0 || tokens[i].compare("/") == 0) {
                int op2 = nums.back();
                nums.pop_back();
                int op1 = nums.back();
                nums.pop_back();
                int res = 0;
                if (tokens[i].compare("+") == 0) {
                    res = op1 + op2;
                }
                else if (tokens[i].compare("-") == 0) {
                    res = op1 - op2;
                }
                else if (tokens[i].compare("*") == 0) {
                    res = op1 * op2;
                }
                else if (tokens[i].compare("/") == 0) {
                    res = op1 / op2;
                }
                nums.push_back(res);
            }
            else {
                nums.push_back(stod(tokens[i]));
            } 
        }
        return nums[0];
    }
};