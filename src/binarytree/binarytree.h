//
// Created by Martin on 2021-02-27.
//

#ifndef LAB3_BINARYTREE_BINARYTREE_H
#define LAB3_BINARYTREE_BINARYTREE_H

typedef struct node_ {
    int key;
    struct _node *parent, *left, *right;
} Node;

typedef struct tree_ {
    Node *root;
} Tree;

Node *search(Tree *tree, int key);

void insert(Tree *tree, Node *node);

Node *delete(Tree *tree, Node *node);

Node *minimum(Tree *tree);

Node *maximum(Tree *tree);

Node *successor(Tree *tree, Node *node);

Node *predecessor(Tree *tree, Node *node);

Node *transplant(Tree *tree, Node *root, Node *subtree);

void printInOrder(Tree *tree);

#endif //LAB3_BINARYTREE_BINARYTREE_H
