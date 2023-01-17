//
// Created by SinclairWww on 2022/12/27.
//

#ifndef BINARYSORTTREE_MODULE_H
#define BINARYSORTTREE_MODULE_H

#endif //BINARYSORTTREE_MODULE_H


bool Search ( BiTree T, int key, BiTree* dad, BiTree* resultPtr ,int* searchTimePtr);   //查找
void Insert ( BiTree* Tptr, int data, int mode );   //插入单个数
void showMenu ();      //向屏幕输出菜单
void SplitLine ();      //输出分割线
void insertWithFile ( BiTree* Tptr );       //从文件插入
void Eliminate ( BiTree* Tptr );            //销毁树
void Delete ( BiTree* Tptr, int num ) ;        //删除