/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* clone, unordered_map<Node*, Node*>& map){
        for(auto n:node->neighbors){
            if(map.count(n)){
                clone->neighbors.push_back(map[n]);
            }else{
                Node* NODE = new Node(n->val);
                map[n]=NODE;
                clone->neighbors.push_back(NODE);
                dfs(n,NODE,map);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone = new Node(node->val);
        unordered_map<Node*, Node*> map;
        map[node]=clone;
        dfs(node,clone,map);
        return clone;
    }
};