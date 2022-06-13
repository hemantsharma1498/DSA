
#include <climits>
class Answer{
    public: 
    int maxnum; 
    int minnum;
    int height;
    bool isBST; 
};
Answer helper(int maxnum,int minnum,int height,BinaryTreeNode<int> *root) { 
    if(root==NULL){
        Answer output; 
        output.minnum=INT_MAX;
        output.maxnum=INT_MIN;
        output.height=0;
        output.isBST=true;
        return output;
    }
    Answer left=helper(maxnum,minnum,height,root->left); 
    Answer right=helper(maxnum,minnum,height,root->right);
    if(left.maxnum<root->data && right.minnum>root->data && left.isBST && right.isBST)
    { 
        Answer output; output.height=1+max(left.height,right.height); 
        output.minnum=min(left.minnum,min(root->data,right.minnum)); 
        output.maxnum=max(left.maxnum,max(root->data,right.maxnum));
        output.isBST=true;
        return output;
    }else{ 
        Answer output;
        output.minnum=min(left.minnum,min(root->data,right.minnum));
        output.maxnum=max(left.maxnum,max(root->data,right.maxnum));
        output.height=max(left.height,right.height);
        output.isBST=false; return output;
    }
} 
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    Answer p=helper(INT_MIN,INT_MAX,0,root);
    return p.height;
}

