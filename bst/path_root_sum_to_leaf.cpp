//For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.


void helper(BinaryTreeNode<int>* root, int sum, vector<int> ans){
    if(!root) return;
    
	ans.push_back(root->data);
    sum=sum-root->data;
    
    if(!root->left&&!root->right&&sum==0){
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
        ans.pop_back();
        return;
    }
    
    helper(root->left, sum, ans);
    helper(root->right, sum,ans);
}


void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    int sum=k;
    vector<int> ans;
    helper(root, sum, ans);
    return;
}
