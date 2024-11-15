//calculate height, using binary search to find the last node
bool exist(struct TreeNode *root, int height, int idx){
    int bit = 1 << height - 1;
    struct TreeNode *node = root;
    while(node && bit > 0){
        if(bit & idx) node = node->right;
        else node = node->left;
        bit >>= 1;
    }
    return node != NULL;
}

int countNodes(struct TreeNode* root) {
    if(root == NULL) return 0;
    int level = 0;
    for(struct TreeNode *curNode = root->left; curNode != NULL; curNode = curNode->left)
        level++;
    int left = 1 << level, right = (1 << level + 1) - 1;
    while(left < right){
        int mid = left + (right - left + 1) / 2;
        if(exist(root, level, mid)) left = mid;
        else right -= 1; 
    }
    return left;
}

//recursive
// int countNodes(struct TreeNode* root) {
//     if(root == NULL) return 0;
//     return countNodes(root->left) + countNodes(root->right) + 1; 
// }
