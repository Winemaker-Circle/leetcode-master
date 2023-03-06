//
// Created by skyzc on 2022/8/4.
//
typedef char ElemType;

// Chain storage of Binary Tree Node
typedef struct BiTNode{
    ElemType data;                  // data domains
    struct BiTNode *lchild,*rchild; // left child pointer, right child pointer
}BiTNode,*BiTree;

// chain storage of binary tree
typedef struct BiTree{
    struct BiTNode *root;   // root node.
    int size;               // number of tree node.
}Tree;

void PreOrder(Tree T){
    if(T == NULL){
        
    }
}


int main(){

    return 0;
}