// Martin Vickgren, Samson Tesfalem

#ifndef LAB3_BINARYTREE_BINARYTREE_H
#define LAB3_BINARYTREE_BINARYTREE_H

typedef struct node_ {
    int key;
    struct node_ *parent, *left, *right;
} Node;

typedef struct tree_ {
    Node *root;
} Tree;

Tree *createTree();

Node *createNode(int key);

Node *search(Node *node, int key);

void insert(Tree *tree, Node *node);

void transplant(Tree *tree, Node *root, Node *subtree);

void delete(Tree *tree, Node *node);

Node *minimum(Node *node);

Node *maximum(Node *node);

Node *successor(Node *node);

Node *predecessor(Node *node);

int branchSize(Node *node);

int treeSize(Tree *tree);

int branchDepth(Node *node);

int treeDepth(Tree *tree);

void printInOrder(Node *node);

void deleteTree(Tree *tree);

#endif //LAB3_BINARYTREE_BINARYTREE_H
