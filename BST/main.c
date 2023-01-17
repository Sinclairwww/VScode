#include "common.h"
#include "module.h"

int main () {
    int order;
    system("chcp 65001");
    system("cls");
    setbuf(stdout, NULL);
    BiTree T = NULL;
    showMenu();
    scanf("%d", &order);
    while ( order != -1 ) {
        switch ( order ) {          //以文件插入
            case 0:insertWithFile(&T);
                break;
            case 1: {               //单个插入
                int target;
                puts("请输入要插入的数据:");
                scanf("%d", &target);
                Insert(&T, target, PRINT);
                break;
            }
            case 2: {               //查找
                int target = 0, searchTime = 0;
                BiTree result = NULL;
                BiTree parent = NULL;
                puts("请输入要查找的数据:");
                scanf("%d", &target);
                clock_t begin = clock();
                if ( Search(T, target, &parent, &result,&searchTime)) { puts("已找到!"); }
                else { puts("未找到!"); }
                for ( int i = 0; i < 99999; i++ ) {
                    Search(T, target, &parent, &result,&searchTime);
                }
                clock_t end = clock();
                printf("比较次数为:%d\n", searchTime/100000);
                printf("用时为%.9lfs\n", ( double ) (end - begin) / CLOCKS_PER_SEC / 100000);
                SplitLine();
                break;
            }
            case 3: {//删除
                int target;
                puts("请输入要删除的数据:");
                scanf("%d", &target);
                Delete(&T, target);
                break;
            }
            case 4:Eliminate(&T);               //销毁
                puts("销毁成功");
                SplitLine();
                break;
            case 5:system("cls");      //清屏
                break;
            default:puts("未知指令,请重新输入");     //非法指令处理
                SplitLine();
        }
        getchar();
        showMenu();
        scanf("%d", &order);
    }
    return 0;
}
