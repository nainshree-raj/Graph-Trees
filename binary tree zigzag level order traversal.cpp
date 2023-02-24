QUESTION : Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
  
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

SOLUTION : class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int cnt=1;
        vector<vector<int>>ans;
        if(root == NULL)
        {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);
        //cnt=cnt+1;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>vect;
            cnt=cnt+1;
            
            //cout<<cnt;
            while(n--)
            {
               // cout<<cnt;
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
            if((cnt%2)!=0)
            {
                reverse(vect.begin(),vect.end());
            }
            ans.push_back(vect);
        }
        return ans;
    }
};
