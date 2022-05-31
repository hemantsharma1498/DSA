//Given a generic tree, print the input tree in level wise order.
//For printing a node with data N, you need to follow the exact format -

#include<queue>
 


void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pending_nodes;
	pending_nodes.push(root);
    while(!pending_nodes.empty()){
        TreeNode<int>* front=pending_nodes.front();
        pending_nodes.pop();
        cout<<(*front).data<<":";
        for(int i=0;i<(*front).children.size();i++){
            pending_nodes.push((*front).children[i]);
            if(i==(*front).children.size()-1){
                cout<<(*(*front).children[i]).data;
            }
            else cout<<(*(*front).children[i]).data<<",";
            
        }
        cout<<endl;

