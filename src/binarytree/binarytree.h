//
// Created by Martin on 2021-02-27.
//

#ifndef LAB3_BINARYTREE_BINARYTREE_H
#define LAB3_BINARYTREE_BINARYTREE_H

typedef struct node_ {
    int key;
    struct node_ *parent, *left, *right;
} Node;

typedef struct tree_ {
    Node *root;
} Tree;

Node *search(Node *node, int key);

void insert(Tree *tree, Node *node);

Node *delete(Tree *tree, Node *node);

Node *minimum(Node *node);

Node *maximum(Node *node);

Node *successor(Node *node);

Node *predecessor(Node *node);

Node *transplant(Tree *tree, Node *root, Node *subtree);

void printInOrder(Tree *tree);

#endif //LAB3_BINARYTREE_BINARYTREE_H
