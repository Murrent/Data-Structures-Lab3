// Martin Vickgren, Samson Tesfalem

#include "binarytree.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Allocating memory for a tree and setting root to NULL.
 * @return Pointer to the tree.
 */
Tree *createTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}
/**
 * Allocating memory for a Node and setting it's value to key.
 * All pointers in the Node are set to NULL.
 * @param key
 * @return Pointer to the Node.
 */
Node *createNode(int key) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
    return node;
}
/**
 * Searches the branch recursively and returns the node with key value if found.
 * If theres no node with the key we return NULL.
 * @param node
 * @param key
 * @return Pointer to the node with key value.
 */
Node *search(Node *node, int key) {
    if (!node || key == node->key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}
/**
 * Inserts node into the appropriate spot in tree.
 * @param tree
 * @param node
 */
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
/**
 * Replaces root with subtree if subtree != NULL
 * @param tree
 * @param root
 * @param subtree
 */
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
/**
 * Deletes the input node and transplants a child node if necessary.
 * @param tree
 * @param node
 */
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
    free(node);
}
/**
 * The minimum node under input node.
 * @param node
 * @return Pointer to the minimum node.
 */
Node *minimum(Node *node) {
    if (!node) return NULL;
    Node *tmp = node;
    while (tmp->left)
        tmp = tmp->left;
    return tmp;
}
/**
 * The maximum node under input node.
 * @param node
 * @return Pointer to the maximum node.
 */
Node *maximum(Node *node) {
    if (!node) return NULL;
    Node *tmp = node;
    while (tmp->right)
        tmp = tmp->right;
    return tmp;
}
/**
 * The successor of node.
 * @param node
 * @return Pointer to the successor.
 */
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
/**
 * The predecessor of node.
 * @param node
 * @return Pointer to the predecessor.
 */
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
/**
 * Amount of nodes under node (including node).
 * @param node
 * @return int of size.
 */
int branchSize(Node *node) {
    if (!node) return 0;
    int size = 0;
    size += branchSize(node->left);
    size++;
    size += branchSize(node->right);
    return size;
}
/**
 * Amount of nodes in tree.
 * @param tree
 * @return int of size.
 */
int treeSize(Tree* tree) {
    if (!tree) return 0;
    return branchSize(tree->root);
}
/**
 * Finds the deepest branch under node (length from the deepest end node to the tree root).
 * Note that calling this function with anything other than tree->root will not return the deepest length in the entire
 * tree.
 * @param node
 * @return int of depth.
 */
int branchDepth(Node *node) {
    if (!node) return 0;
    int sizeLeft = 0;
    int sizeRight = 0;
    if (node->left)
        sizeLeft = branchDepth(node->left);
    if (node->right)
        sizeRight = branchDepth(node->right);
    if (!node->left && !node->right) { // If this is true, we're at an end node.
        sizeLeft = sizeLeft < sizeRight ? sizeRight : sizeLeft; // Keeping the larger size
        int size = 0;
        for (Node* tmp = node; tmp; tmp = tmp->parent) size++; // Calculating the distance to tree root.
        size = sizeLeft < size ? size : sizeLeft; // Keeping the larger size
        return size;
    }
    return sizeLeft < sizeRight ? sizeRight : sizeLeft; // Returning the larger size
}
/**
 * Finds the deepest branch from tree root and returns it's length
 * @param tree
 * @return int of depth.
 */
int treeDepth(Tree* tree) {
    if (!tree) return 0;
    return branchDepth(tree->root);
}
/**
 * Printing all child nodes of the input node in ascending order
 * @param node
 */
void printInOrder(Node *node) {
    if (!node) return;
    printInOrder(node->left);
    printf("%d\n", node->key);
    printInOrder(node->right);
}
/**
 * Freeing all the memory of tree and it's nodes
 * @param tree
 */
void deleteTree(Tree *tree) {
    if (tree == NULL) return;
    while (tree->root)
        delete(tree, tree->root);
    free(tree);
}