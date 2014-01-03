#include<stdio.h>
#include<stdlib.h>

struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
};


struct node* NewNode(int data) { 
  struct node* node = mallocsizeof((struct node));    // new(structno) in cpp
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 

static int lookup(struct node* node, int target) { 
  if (node == NULL) { 
    return(false); 
  } 
  else { 
    if (target == node->data) return(true); 
    else { 
      if (target < node->data) return(lookup(node->left, target)); 
      else return(lookup(node->right, target)); 
    } 
  } 
} 


int maxDepth(struct node* node) { 
  if (node==NULL) { 
    return(0); 
  } 
  else { 
    // compute the depth of each subtree 
    int lDepth = maxDepth(node->left); 
    int rDepth = maxDepth(node->right); 
    // use the larger one 
    if (lDepth > rDepth) return(lDepth+1); 
    else return(rDepth+1); 
  } 
} 

struct node* insert(struct node* node, int data) { 
  if (node == NULL) { 
    return(newNode(data)); 
  } 
  else { 
    if (data <= node->data) node->left = insert(node->left, data); 
    else node->right = insert(node->right, data); 
    return(node); 
  } 
} 

int size(struct node* node) { 
  if (node==NULL) { 
    return(0); 
  } else { 
    return(size(node->left) + 1 + size(node->right)); 
  } 
} 

void printTree(struct node* node) { 
  
  
  if (node == NULL) return; 
  
  //inorder (left child and then operate and then right child )
  
  printTree(node->left); 
  printf("%d ", node->data); 
  printTree(node->right); 
  
  /*
  Pre order (operate then left child and right child)
  
  printf("%d ", node->data); 
  printTree(node->left); 
  printTree(node->right); 
  
  */
  
  
  /*
  Post order (left child and right child and then operate)
  
  printTree(node->left); 
  printTree(node->right); 
  printf("%d ", node->data); 
  
  */
  
} 


int main(){
struct node* root = NULL;
root=insert(root,1);
printTree(root);
return 0;
}
