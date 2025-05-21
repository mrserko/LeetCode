/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    ListNode* globalHead;
    std::unordered_map<TreeNode*, bool> seen;

    bool isSub(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        bool all_path = false;
        if (seen.find(root->left) == seen.end()) {
            seen[root->left] = isSub(globalHead, root->left);
        }
        all_path = seen[root->left];
        if (seen.find(root->right) == seen.end()) {
            seen[root->right] = isSub(globalHead, root->right);
        }
        all_path |= seen[root->right];
        if (all_path) {
            return true;
        }
        if (root->val == head->val) {
            return isSub(head->next, root->left) or isSub(head->next, root->right);
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        globalHead = head;
        return isSub(head, root);
    }
};