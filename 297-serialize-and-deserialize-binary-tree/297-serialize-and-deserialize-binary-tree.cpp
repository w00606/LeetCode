/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void RecurSerial(TreeNode* node, string& output) {
        if (node) {
            output += to_string(node->val);
            output += ",";
            RecurSerial(node->left, output);
            RecurSerial(node->right, output);
        }
        else {
            output += "null";
            output += ",";
        }
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output;
        if (root == NULL) {
            return "";
        }
        RecurSerial(root, output);
        output.erase(output.end() - 1, output.end());
        while(output.compare(output.size() - 4, 4, "null") == 0) {
            output.erase(output.end() - 5, output.end());
            if (output.size() < 4) {
                break;
            }
        }
        return output;
    }

    TreeNode* RecurDeserial(string& data) {
        if (data.length() == 0) {
            return NULL;
        }
        if (data.compare(0, 4, "null") == 0) {
            data.erase(data.begin(), data.begin() + 5);
            return NULL;
        }
        size_t pos = data.find(",");
        bool last_element = false;
        if (pos == -1) {
            pos = data.length();
            last_element = true;
        }
        string single_num = data.substr(0, pos);
        int value = stoi(single_num);
        TreeNode* node = new TreeNode(value);
        if (last_element) {
            data.erase(data.begin(), data.begin() + pos);
        }
        else{
            data.erase(data.begin(), data.begin() + pos + 1);
        }
        node->left = RecurDeserial(data);
        node->right = RecurDeserial(data);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }
        TreeNode* root = RecurDeserial(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));