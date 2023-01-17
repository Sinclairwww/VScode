//
// Created by SinclairWww on 2022/12/27.
//
#include "common.h"

void SplitLine () {
    puts ( "-----------------------------------------------------------------------"
           "---------------------------" );
    return;
}

bool Search ( BiTree T, int key, BiTree* parentPtr, BiTree* resultPtr, int* searchTimePtr ) {
    if ( !T ) {    // 查找失败，结果指针指向路径上最后一个结点，返回false
        *resultPtr = *parentPtr;
        return false;
    } else {
        ( *searchTimePtr )++;     // 更新比较次数
        if ( key == T->num ) {    // 查找成功，结果指针指向当前结点，返回true
            *resultPtr = T;
            return true;
        } else if ( key > T->num ) {    // key比当前节点大，向右找
            *parentPtr = T;
            return Search ( T->rchild, key, parentPtr, resultPtr, searchTimePtr );
        } else {    // key比当前结点小,向左找
            *parentPtr = T;
            return Search ( T->lchild, key, parentPtr, resultPtr, searchTimePtr );
        }
    }
}

void Insert ( BiTree* Tptr, int data, int mode ) {
    BiTree newNode = ( BiTree ) malloc ( sizeof ( BiTNode ) );    // 新插入的结点
    newNode->num = data;
    newNode->lchild = newNode->rchild = NULL;
    BiTree result = NULL;    // 存储查找结果的结点
    BiTree parent = NULL;
    int    searchTimes = 0;
    if ( Search ( *Tptr, data, &parent, &result,
                  &searchTimes ) ) {    // 找到了,插在左下角
        printf ( "数据%d已存在，插入失败\n", data );
        SplitLine ();
        return;
    } else {
        if ( !( *Tptr ) ) {    // 若T为空,直接把新值赋上去
            *Tptr = newNode;
        } else {                           // 没找到,返回上一结点,比较后插入对应位置
            if ( data > result->num ) {    // 大于,插在右边
                result->rchild = newNode;
            } else {    // 小于,插在左边
                result->lchild = newNode;
            }
        }
    }
    if ( mode == PRINT ) {
        printf ( "插入%d成功!\n", data );
        SplitLine ();
    }
    return;
}

void showMenu () {    // 向屏幕输出菜单
    //    system("cls");
    puts ( "请输入数字以选择对应功能" );
    puts ( "0.读取文件插入  1.单独插入  2.查找  3.删除  4.销毁  5.清屏  -1.退出" );
}

void insertWithFile ( BiTree* Tptr ) {
    int  num;
    char str[ 20 ];
    puts ( "当前目录下可供插入的.txt文件有:" );
    system ( "dir *.txt /b" );
    puts ( "请输入提供数据的文件名：" );
    scanf ( "%s", str );
    if ( strcmp ( str, "aaa" ) == 0 ) {
        strcpy ( str, "test.txt" );
    }
    FILE* fp = fopen ( str, "r+" );
    while ( fp == NULL ) {
        puts ( "打开文件失败 " );
        puts ( "请重新输入：" );
        scanf ( "%s", str );
        fp = fopen ( str, "r+" );
    }
    while ( EOF != fscanf ( fp, "%d", &num ) ) {
        Insert ( Tptr, num, NO_PRINT );
    }
    puts ( "插入成功!" );
    SplitLine ();
    fclose ( fp );
    return;
}

void Eliminate ( BiTree* Tptr ) {
    if ( *Tptr == NULL ) {
        return;
    }
    Eliminate ( &( ( *Tptr )->lchild ) );
    Eliminate ( &( ( *Tptr )->rchild ) );
    free ( *Tptr );
    *Tptr = NULL;
    return;
}

void replaceBothChildren ( BiTree T ) {
    BiTree parent = T->lchild;
    BiTree curr = parent->rchild;
    if ( curr == NULL ) {    // 只有两个结点的跨度
        T->lchild = parent->lchild;
        T->num = parent->num;
        free ( parent );
    } else {    // 跨度三个结点
        while ( curr->rchild != NULL ) {
            parent = curr;
            curr = curr->rchild;
        }
        T->num = curr->num;
        parent->rchild = curr->lchild;
        free ( curr );
    }
    return;
}

int getMode ( BiTree T ) {
    if ( T->lchild == NULL ) {
        if ( T->rchild == NULL ) {
            return NO_CHILDREN;
        } else {
            return ONLY_RIGHT;
        }
    } else {
        if ( T->rchild == NULL ) {
            return ONLY_LEFT;
        } else {
            return BOTH_CHILDREN;
        }
    }
}

void replaceCommonCase ( BiTree* Tptr, BiTree parent, BiTree res, BiTree replacePtr ) {
    if ( parent == NULL ) {    // 删除根部
        if ( res->rchild != NULL ) {
            *Tptr = res->rchild;
        }    // 直接用不空的一侧指针替换根
        else if ( res->lchild != NULL ) {
            *Tptr = res->lchild;
        } else {
            *Tptr = NULL;
        }
    } else {
        if ( parent->lchild == res ) {
            parent->lchild = replacePtr;
        } else {
            parent->rchild = replacePtr;
        }    // 找到是哪个结点需要被替换
    }
    free ( res );
    return;
}

void Delete ( BiTree* Tptr, int num ) {
    BiTree res = NULL;
    BiTree parent = NULL;
    int    searchTimes = 0;
    if ( !Search ( *Tptr, num, &parent, &res, &searchTimes ) ) {
        puts ( "未找到，删除失败" );
    } else {
        BiTree replacePtr;
        switch ( getMode ( res ) ) {
            case NO_CHILDREN:    // 叶子结点
                replacePtr = NULL;
                replaceCommonCase ( Tptr, parent, res, replacePtr );
                break;
            case ONLY_RIGHT:    // 只有右孩子
                replacePtr = res->rchild;
                replaceCommonCase ( Tptr, parent, res, replacePtr );
                break;
            case ONLY_LEFT:    // 只有左孩子
                replacePtr = res->lchild;
                replaceCommonCase ( Tptr, parent, res, replacePtr );
                break;
            case BOTH_CHILDREN: {    // 两边孩子都有
                replaceBothChildren ( res );
                break;
            }
        }
        puts ( "删除成功" );
    }
    SplitLine ();
}