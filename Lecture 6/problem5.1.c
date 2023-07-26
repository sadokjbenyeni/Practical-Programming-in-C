#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

/*
    @function   nalloc
    @desc       allocates a new node elements
    @returns    pointer to the new element on succes, NULL on failure
    @param data [IN] payload of the new element   
*/
struct node* nalloc(int data)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    if(p!=NULL)
    {
        p->next=NULL;
        p->data=data;
    }
    return p;
}

/* @function addfront
   @desc     adds node to the front of the list
   @param    head [IN] current head of the list 
   @param    data [IN] data to be insterted 
   @return   updated head of the list
*/
struct node* addfront(struct node* head, int data)
{
    struct node* p=nalloc(data);
    if(p==NULL) return head; /*no change*/
    p->next=head;
    return p;
}

/* @function    display
   @desc        displays the nodes in the list
   @param       head [IN] pointer to the head of the list 
*/
void display(struct node* head)
{
    struct node* p=NULL;
    printf("list:");
    for(p=head;p!=NULL;p=p->next)
        printf("%d ", p->data);
    printf("\n");
}

/* @function    addback
   @desc        adds node to the back of the list
   @param       head [IN] current head of the list
   @param       data [IN] data to be inserted
   @return      update head node
*/
struct node* addback(struct node* head, int data)
{
    struct node* p=nalloc(data);
    struct node* curr=NULL;
    if(p=NULL) return head;
    if(head==NULL)
    {
        head=p;
        return p;
    }
    else
    {
        /*find last elelment*/
        for(curr=head; curr->next!=NULL;curr=curr->next)
            ;
        curr->next=p;
        return head;
    }
}

/* 
    @function freelist
    @desc frees the element of the list
    @param head [IN] pointer to the head node 
*/
void freelist(struct node* head)
{
    struct node* p=NULL;
    while(head)
    {
        p=head;
        head=head->next;
        free(p);
    }
}

/* 
    @function   find
    @desc       finds the elements that contains the given data
    @param      head [IN] pointer to the head node
    @param      data [IN] payload to match
    @return     NULL if not found, pointer to the element if found
*/
struct node* find(struct node* head, int data)
{
    struct node* curr=NULL;
    for(curr=head; curr->next!=NULL; curr=curr->next)
        if(curr->data == data) return curr;
    return NULL;
}

/*
    @function  delnode
    @desc      deletes a node
    @param     head [IN] pointer to the head node
    @param     pnode [IN] pointer to the element to be removed
    @return    updated head node
*/
struct node* delnode(struct node* head, struct node* pnode)
{
    struct node* p=NULL;
    struct node* q=NULL;
    for(p=head;p!=NULL && p!=pnode; p=p->next)
        q=p;
    if( p==NULL)
    {
        head= head->next;
        free(p);
    }
    else
    {
        q->next=p->next;
        free(p);
    }
    return head;
}
