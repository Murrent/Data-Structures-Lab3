//
// Created by Martin on 2021-03-04.
//

#include <stdio.h>
#include "binarytree/binarytree.h"
#include "load_files/load_file.h"

int main(int argc, char* argv[]) {
    const char* fName = argv[1];

    int* a = load_file(fName);

    int size = a[0];
    Tree *tree = createTree();
    printf("Input:\n");
    for ( int i = 1 ; i <= size ; i++ )
    {
        insert(tree, createNode(a[i]));
        printf("%d\n", a[i]);
    }

    printf("\n");
    printf("Minimum to tree root %d\n", minimum(tree->root) ? minimum(tree->root)->key : 0);
    printf("Maximum to tree root %d\n", maximum(tree->root) ? maximum(tree->root)->key : 0);
    printf("Predecessor to tree root %d\n", predecessor(tree->root) ? predecessor(tree->root)->key : 0);
    printf("Successor to tree root %d\n", successor(tree->root) ? successor(tree->root)->key : 0);

    printf("\nBefore deleting root: \n");
    printInOrder(tree->root);
    printf("Depth: %d\n", treeDepth(tree->root));
    printf("Size: %d\n", treeSize(tree->root));

    printf("\nAfter deleteing root\n");
    delete(tree, tree->root);
    printInOrder(tree->root);
    printf("Depth: %d\n", treeDepth(tree->root));
    printf("Size: %d\n", treeSize(tree->root));

    printf("\n");
    deleteTree(tree);
    return 0;
}
