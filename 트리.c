#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct TreeNode
{
    element key;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode* insertNode(TreeNode* root, element key)
{
    if(root == NULL)
    {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if(key < root ->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

void preOrder(TreeNode* root)
{
    if(root != NULL)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);

    }
}

void inOrder(TreeNode* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);
    }
}

int main(void)
{

    TreeNode* root = NULL;

    root = insertNode(root, 35);
    root = insertNode(root, 68);
    root = insertNode(root, 99);
    root = insertNode(root, 18);

    preOrder(root);
    inOrder(root);

    return 0;
}
