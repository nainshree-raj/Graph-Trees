QUESTION : Given the root of a binary tree, return the sum of all left leaves.
           A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
EXAMPLE : Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
  
SOLUTION : /**
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==NULL)
        {
            return 0;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            vector<int>vect;
            while(size--)
            {
                TreeNode* curr=q.front();
                q.pop();
                vect.push_back(curr->val);

                if(curr->left)
                {
                    if(curr->left->left==NULL && curr->left->right==NULL)
                    {
                        sum+=(curr->left->val);
                    }
                    else
                    {
                        q.push(curr->left);
                    }
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return sum; 
    }
};
