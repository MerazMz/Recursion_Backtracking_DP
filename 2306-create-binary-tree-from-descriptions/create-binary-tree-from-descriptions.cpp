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
    int returnRoot(vector<vector<int>>& desc){
        set<int> parent;
        set<int> children;
        for(auto node:desc){
            int par = node[0];
            int child = node[1];
            parent.insert(par);
            children.insert(child);
        }
        while(parent.size()!=1){
            for(int n:children){
                if(parent.count(n)){
                    parent.erase(n);
                }
            }
        }
        int root = 0;
        for(int n:parent){
            root=n;
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int root = returnRoot(desc);
        unordered_map<int,TreeNode*> map;

        for(auto node:desc){
            int par = node[0];
            int child = node[1];
            bool isLeft = node[2]==1;
            if(!map.count(par)){ //agar nhi h bana hua to new parent banao
                TreeNode* newNode = new TreeNode(par); 

                if(!map.count(child)){ //agar uska child bhi bhi hai to wo bhi banao
                    TreeNode* childNode = new TreeNode(child);
                    if(isLeft){
                        newNode->left = childNode;
                    }else{
                        newNode->right = childNode;
                    }
                    map[child]=childNode;
                }else{
                    if(isLeft){
                        newNode->left = map[child];
                    }else{
                        newNode->right = map[child];
                    }
                }
                map[par]=newNode;
            }else{
                if(!map.count(child)){ //agar uska child bhi bhi hai to wo bhi banao
                    TreeNode* childNode = new TreeNode(child);
                    if(isLeft){
                        map[par]->left = childNode;
                    }else{
                        map[par]->right = childNode;
                    }
                    map[child]=childNode;
                }else{
                    if(isLeft){
                        map[par]->left = map[child];
                    }else{
                        map[par]->right = map[child];
                    }
                }
            }
        }


        return map[root];



    }
};