#include<stdio.h> 
#include<stdlib.h> 
  
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = NULL;
    temp->right = NULL; 
    return temp; 
} 
  
// insert a new node 
struct node* push(struct node* node, int key) 
{     
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
        node->left  = push(node->left, key); 
    else
        node->right = push(node->right, key); 
    return node; 
} 

//function deletes the key 
struct node* pop(struct node* root, int key) 
{  
    if (root == NULL) return root; 
  
    if (key < root->key) 
        root->left = pop(root->left, key); 
    else if (key > root->key) 
        root->right = pop(root->right, key); 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        // node with two children: 
        struct node* temp;
        while (temp->left != NULL) temp = temp->left;  
        root->key = temp->key; 
    
        root->right = pop(root->right, temp->key); 
    } 
    return root; 
} 

void write_tree(struct node *root) 
{ 
    if (root != NULL) 
    { 
        write_tree(root->left); 
        printf("%d ", root->key); 
        write_tree(root->right); 
    } 
} 
  
int main() 
{ 
    struct node* root=NULL;
    root=push(root, 20);
    root=push(root,12);
    root=push(root,23);
    root=push(root,18);
    root=push(root,35);

    write_tree(root);
    printf("\n");

    root=pop(root, 18);

    write_tree(root);
    printf("\n");
      
    return 0; 
} 