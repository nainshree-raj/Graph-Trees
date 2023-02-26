QUESTION: Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
  
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

SOLUTION :
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int>vect;

            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                vect.push_back(curr->val);

                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            
            ans.push_back(vect);
        }
        reverse(ans.begin(),ans.end());
        return ans;

        }
};
