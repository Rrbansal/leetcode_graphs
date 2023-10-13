class Solution {
public:
vector<Node*>noderegister;
void dfs(Node * actual,Node* clone)
{
    for(auto nei:actual->neighbors)
    {
        if(not noderegister[nei->val])
        {
            Node* newnode=new Node(nei->val);
            noderegister[newnode->val]=newnode;
            clone->neighbors.push_back(newnode);
            dfs(nei,newnode);
        }else
        {
            clone->neighbors.push_back(noderegister[nei->val]);
        }
    }
}
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node * clone=new Node(node->val);
        noderegister.resize(110,NULL);
        noderegister[clone->val]=clone;
        dfs(node,clone);
        return clone;
        
    }
};
