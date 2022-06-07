pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        pair<int, int> ans;
        ans.first=INT_MAX;
        ans.second=INT_MIN;
        return ans;
    }
    
    
    pair<int, int> leftans=getMinAndMax((*root).left);
    pair<int, int> rightans=getMinAndMax((*root).right);
    
    int max_left=leftans.second;
    int min_left=leftans.first;
    int max_right=rightans.second;
    int min_right=rightans.first;
    
    int maximum=max(max_left, max(max_right, (*root).data));
    int minimum=min(min_left, min(min_right, (*root).data));
    
    pair<int, int> ans;
    ans.first=minimum;
    ans.second=maximum;
    
    return ans;
                    

    
}
