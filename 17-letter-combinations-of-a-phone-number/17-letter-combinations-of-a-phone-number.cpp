class Solution {
public:
    vector<vector<string>> letters = {{"a","b","c"}, {"d","e","f"}, {"g","h","i"},
                                      {"j","k","l"}, {"m","n","o"}, {"p","q","r","s"},
                                      {"t","u","v"}, {"w","x","y","z"}};
    
    vector<string> letterCombinations(string digits) {
        vector<int> digits_int;
        int total_com = 1;
        int i = 0;
        while (digits[i]) {
            digits_int.push_back(digits[i] - 48);
            ++i;
        }
        
        if (!digits_int.size()) {
            vector<string> empty;
            return empty;
        }
        
        for (int j = 0; j < digits_int.size(); ++j) {
            total_com *= letters[digits_int[j] - 2].size();   
        }
        
        vector<string> ret(total_com);
        int idx_den = total_com;
        int idx_num = 0;
        for (int k = 0; k < total_com; ++k) {
            idx_num = k;
            idx_den = total_com;
            for (int l = 0; l < digits_int.size(); ++l) {
                idx_den /= letters[digits_int[l] - 2].size();
                ret[k] += letters[digits_int[l] - 2][idx_num / idx_den];
                idx_num %= idx_den;
            }
        }
        return ret;
    }
};