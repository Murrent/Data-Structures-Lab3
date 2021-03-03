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

Node *search(Node *node, int key) {
    if (node == NULL || key == node->key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void insert(Tree *tree, Node *node) {
    Node *y = NULL;
    Node *x = tree->root;
    while (x != NULL) {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else x = x->right;
        node->parent = y;
        if (y == NULL) tree->root = node;
        else if (node->key < y->key) y->left = node;
        else y->right = node;
    }
}

Node *delete(Tree *tree, Node *node) {
    if (tree == NULL || node == NULL)
        return NULL;
    if (node->left == NULL)
        transplant(tree, node, node->right);
    else if (node->right == NULL)
        transplant(tree, node, node->left);
    else {
        Node *nodeMin = maximum(node->right);
        if (nodeMin->parent != node) {
            transplant(tree, nodeMin, nodeMin->right);
            nodeMin->right = node->right;
            nodeMin->right->parent = nodeMin;//fixa
        }
        transplant(tree, node, nodeMin);
        nodeMin->left = node->left;
        nodeMin->left->parent = nodeMin;//fixa
    }
}

Node *minimum(Node *node) {
    if (node == NULL) return NULL;
    Node *tmp = node;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node *maximum(Node *node) {
    if (node == NULL) return NULL;
    Node *tmp = node;
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
    if (tree == NULL || root == NULL || subtree == NULL)
        return NULL;
    Node *bs = root->parent;//måste fixa
    if (bs == NULL)
        tree->root = subtree;
    else if (root == bs->left)//måste fixa
        bs->left;
    else bs->right = subtree;
    if (subtree != NULL)
        subtree->parent = root->parent;
}

void printInOrder(Tree *tree) {

}
