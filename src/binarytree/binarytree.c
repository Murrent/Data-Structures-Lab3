//
// Created by Martin on 2021-02-27.
//

#include "binarytree.h"
#include <stdlib.h>

Tree *createTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node *createNode(int key) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->right = NULL;
    node->left = NULL;
    return node;
}

Node *search(Tree *tree, int key) {
    Node *tmp = tree->root;
    if (tree == NULL || key == tmp->key)
        return tmp;
    if (key < tmp->key)
        return search(tmp->left, key);
    return search(tmp->right, key);
}

void insert(Tree *tree, Node *node) {
    Node *y = NULL;
    Node *x = tree->root;
    while (x != NULL) {
        y = x;
        if (node->key < x->key)
            x = x->left;
        x = x->right;
        node->parent = y;
        if (y == NULL) tree->root = node;
        if (node->key < y->key) y->left = node;
        else y->right = node;
    }
}

Node *delete(Tree *tree, Node *node) {
    return NULL;
}

Node *minimum(Tree *tree) {
    if (tree == NULL) return NULL;
    Node *tmp = tree->root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node *maximum(Tree *tree) {
    if (tree == NULL) return NULL;
    Node *tmp = tree->root;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

Node *successor(Node *node) {
    if (node == NULL)
        return NULL;
    Node *y = node->parent;
    if (node->right) return minimum(node->right);
    while (y != NULL && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}

Node *predecessor(Node *node) {
    if (node == NULL)
        return NULL;
    Node *y = node->parent;
    if (node->left) return maximum(node->left);
    while (y != NULL && node == y->left) {
        node = y;
        y = y->parent;
    }
    return y;
}

Node *transplant(Tree *tree, Node *root, Node *subtree) {
    return NULL;
}

void printInOrder(Tree *tree) {

}
