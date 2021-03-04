//
// Created by Martin on 2021-02-27.
//

#include "binarytree.h"
#include <stdlib.h>
#include <stdio.h>

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
    node->parent = NULL;
    return node;
}

Node *search(Node *node, int key) {
    if (!node || key == node->key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void insert(Tree *tree, Node *node) {
    Node *y = NULL;
    Node *x = tree->root;
    while (x) {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else x = x->right;
    }
    node->parent = y;
    if (!y) tree->root = node;
    else if (node->key < y->key) y->left = node;
    else y->right = node;
}

void transplant(Tree *tree, Node *root, Node *subtree) {
    if (!tree || !root) return;
    if (!root->parent)
        tree->root = subtree;
    else if (root == root->parent->left)
        root->parent->left = subtree;
    else root->parent->right = subtree;
    if (subtree != NULL)
        subtree->parent = root->parent;
}

void delete(Tree *tree, Node *node) {
    if (!tree || !node) return;
    if (!node->left)
        transplant(tree, node, node->right);
    else if (!node->right)
        transplant(tree, node, node->left);
    else {
        Node *nodeMin = minimum(node->right);
        if (nodeMin->parent != node) {
            transplant(tree, nodeMin, nodeMin->right);
            nodeMin->right = node->right;
            nodeMin->right->parent = nodeMin;
        }
        transplant(tree, node, nodeMin);
        nodeMin->left = node->left;
        nodeMin->left->parent = nodeMin;
    }
}

Node *minimum(Node *node) {
    if (!node) return NULL;
    Node *tmp = node;
    while (tmp->left)
        tmp = tmp->left;
    return tmp;
}

Node *maximum(Node *node) {
    if (!node) return NULL;
    Node *tmp = node;
    while (tmp->right)
        tmp = tmp->right;
    return tmp;
}

Node *successor(Node *node) {
    if (!node) return NULL;
    if (node->right) return minimum(node->right);
    Node *y = node->parent;
    while (y && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}

Node *predecessor(Node *node) {
    if (!node) return NULL;
    if (node->left) return maximum(node->left);
    Node *y = node->parent;
    while (y && node == y->left) {
        node = y;
        y = y->parent;
    }
    return y;
}

int treeSize(Node *node) {
    if (!node) return 0;
    int size = 0;
    size += treeSize(node->left);
    size++;
    size += treeSize(node->right);
    return size;
}

int treeDepth(Node *node) {
    if (!node) return 0;
    int sizeLeft = 0;
    int sizeRight = 0;
    if (node->left)
        sizeLeft = treeDepth(node->left);
    if (node->right)
        sizeRight = treeDepth(node->right);
    if (!node->left && !node->right) {
        sizeLeft = sizeLeft < sizeRight ? sizeRight : sizeLeft;
        int size = 0;
        for (Node* tmp = node; tmp; tmp = tmp->parent) size++;
        size = sizeLeft < size ? size : sizeLeft;
        return size;
    }
    return sizeLeft < sizeRight ? sizeRight : sizeLeft;
}

void printInOrder(Node *node) {
    if (!node) return;
    printInOrder(node->left);
    printf("%d\n", node->key);
    printInOrder(node->right);
}

void deleteTree(Tree *tree) {
    if (tree == NULL) return;
    while (tree->root)
        delete(tree, tree->root);
    free(tree);
}