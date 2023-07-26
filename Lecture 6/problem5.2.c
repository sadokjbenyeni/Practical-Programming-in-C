#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode* left;
    struct tnode* right;
};

/*
    @fuction talloc
    @desc    allocates a new node
    @param   data[IN] payload
    @return  pointer to the new node or NULL on failure
*/
struct tnode* talloc(int data)
{
    struct tnode* p=(struct tnode*)malloc(sizeof(struct tnode));
    if(p!=NULL)
    {
        p->data=data;
        p->left=p->right=NULL;
    }
    return p;
}

/*
    @function addnode
    @desc     inserts node into the tree
    @param    data [IN] data to be inserted
    @returns  updated root to the tree
*/
struct tnode* addnode(struct tnode* root, int data)
{
    if(root==NULL)
    {
        struct tnode* node=talloc(data);
        return (root=node);
    }
    else if(data<root->data)
    {
        root->right=addnode(root->right, data);
    }
    return root;
}

/* 
@function       preorder
@desc           prints elements in pre-order
@param          root [IN] pointer to the root of the tree
@returns        nothing
*/
void preorder(struct tnode* root)
{
    if(root==NULL) return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

/*
    @function   inorder
    @desc       prints elements in in-order
    @param      root [IN] pointer to the root of the tree
    @returns    nothing
*/
void inorder(struct tnode* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* 
    @fuction deltree
    @desc    delete nodes of the tree
    @param   root [IN] pointer to the root of the tree 
*/
int deltree(struct tnode* root)
{
    int count=0;
    if(root==NULL) return;
    count+=deltree(root->left);
    count+=deltree(root->right);
    free(root);
    return ++count;
}
