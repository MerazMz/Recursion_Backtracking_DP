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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        set<int> children;
        unordered_map<int,TreeNode*> map;

        for(auto node:desc){
            int par = node[0];
            int child = node[1];
            bool isLeft = node[2]==1;

            children.insert(child);

            if(!map.count(par)){
                map[par] = new TreeNode(par);
            }
            if(!map.count(child)){
                map[child] = new TreeNode(child);
            }
            if(isLeft){
                map[par]->left = map[child];
            }else{
                map[par]->right = map[child];
            }
        }
        int root=0;
        for(auto e:desc){
            int par = e[0];
            if(!children.count(par)){
                return map[par];
            }
        }
        return NULL;
    }
};