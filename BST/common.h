
//
// Created by SinclairWww on 2022/12/27.
//

#ifndef BINARYSORTTREE_COMMON_H
#define BINARYSORTTREE_COMMON_H
#define NO_PRINT 0         // 不打印
#define PRINT 1            // 打印
#define NO_CHILDREN 0      // 没有孩子
#define ONLY_RIGHT 1       // 只有右孩子
#define ONLY_LEFT 2        // 只有左孩子
#define BOTH_CHILDREN 3    // 两个孩子都有
#endif                     // BINARYSORTTREE_COMMON_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct BiTNode {
    int             num;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;