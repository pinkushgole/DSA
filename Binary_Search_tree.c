
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *ladd;
    int data;
    struct node *radd;
};

struct node *root = NULL;

struct node *create(struct node *p, int n);
void inorder(struct node *p);
void preorder(struct node *p);
void postorder(struct node *p);

void main()
{
    int n,ch;
    do
    {
        printf("\n----------Binary Search Tree-----------\n");
        printf("Press 1 to create a Binary Search Tree\n");
        printf("Press 2 for Inorder\n");
        printf("Press 3 for Preorder\n");
        printf("Press 4 for Postorder\n");
        printf("Press 5 for Exit\n");
        printf("Enter Yout Choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                printf("\nEnter a value, pass 0 to quit: ");
                scanf("%d",&n);                
                while(n!=0)
                {
                    root = create(root,n);
                    printf("\nEnter next value, pass 0 to quit: ");
                    scanf("%d",&n);                
                }
            break;
            
            case 2: inorder(root);break;
            case 3: preorder(root);break;
            case 4: postorder(root);break;
            case 5: break;
            default:printf("Invalid Choice, please try again\n");
        }
    }        
    while(ch!=5);
}

struct node * create(struct node *p,int n)                                     
{                                                                             
    if(p==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));                          
        p->ladd=NULL;                                                           
        p->radd=NULL;   
        p->data=n;
    }                                                                           
    else                                                                        
    {       
        if(n>p->data)
        {  
            p->radd = create(p->radd,n);                    
        }                     
        else if(n<p->data)
        {
            p->ladd = create(p->ladd,n);                   
        } 
        else
        {
            printf("Duplicate elements are not allowed in a Binary Search Tree");
        }
    }
    return p;
}

void inorder(struct node *p) // LNR
{
    if(p!=NULL)
    {
        inorder(p->ladd);
        printf("%d ",p->data);
        inorder(p->radd);
    }
}
void preorder(struct node *p)  // NLR
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->ladd);
        preorder(p->radd);
    }
}
void postorder(struct node *p)  // LRN
{
    if(p!=NULL)
    {
        postorder(p->ladd);
        postorder(p->radd);
        printf("%d ",p->data);    
    }
}