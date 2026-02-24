class Solution {
public:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;
        
        // Build binary number
        curr = (curr << 1) | node->val;
        
        // If leaf node, return the number
        if (!node->left && !node->right)
            return curr;
        
        // Sum from left and right subtree
        return dfs(node->left, curr) + dfs(node->right, curr);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};