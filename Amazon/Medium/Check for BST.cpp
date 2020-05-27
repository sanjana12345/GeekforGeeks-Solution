    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
   int maxval(Node *root)
   {
       Node *current=root;
       while(current->right!=NULL)
       current=current->right;
       return current->data;
   }
   int minval(Node *root)
   {       Node *current=root;
       while(current->left!=NULL)
       current=current->left;
       return current->data;

       
   }
bool isBST(Node* root) 
{
    if(root==NULL)
    return 1;
    if(root->left!=NULL && maxval(root->left)>root->data)
    return 0;
    if(root->right!=NULL && minval(root->right)<root->data)
    return 0;
    if(!isBST(root->left) || !isBST(root->right))
    return 0;
    
    return 1;
}
