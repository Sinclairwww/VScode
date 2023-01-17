#include <iostream>
using namespace std;

struct heapStruct {
    int* arr;
    int  size, capacity;
};

typedef heapStruct* Heap;


bool isFull ( Heap H ) { return ( H->size >= H->capacity ); }
bool isEmpty ( Heap H ) { return ( H->size == 0 ); }

void Insert ( Heap H, int item ) {
    int i;
    for ( i = 1 + H->size; i > 1 && H->arr[ i / 2 ] < item; i /= 2 ) {
        H->arr[ i ] = H->arr[ i / 2 ];
    }
    H->arr[ i ] = item;
    H->size++;
}

Heap Init ( int maxSize ) {
    Heap H = ( Heap ) malloc ( sizeof ( heapStruct ) );
    H->arr = ( int* ) malloc ( sizeof ( int ) * ( maxSize + 1 ) );
    H->size = 0;
    H->capacity = maxSize;
    return H;
}


int adjustDown ( int* arr, int root, int size ) {
    int curr, child, tmp, rootItem;
    if ( root == 0 ) {    // root为0时是删除根值
        tmp = arr[ size-- ];
        root = 1;
        rootItem = arr[ 1 ];
    } else
        tmp = arr[ root ];    // root不为0时进行调整

    for ( curr = root; curr * 2 <= size; curr = child ) {
        child = curr * 2;
        if ( child != size && arr[ child ] < arr[ child + 1 ] )
            child++;
        if ( tmp >= arr[ child ] )
            break;
        else
            arr[ curr ] = arr[ child ];
    }
    arr[ curr ] = tmp;
    return rootItem;
}

int Delete ( Heap H ) {
    H->size--;
    return adjustDown ( H->arr, 0, H->capacity );
}

// Heap Create ( int maxSize ) {
//     int   item;
//     Heap  H = Init ( maxSize );
//     FILE* fp = fopen ( "./test.txt", "r" );
//     // system ( "dir" );
//     if ( fp == NULL ) {
//         cout << "ERROR" << endl;
//     }
//     while ( EOF != fscanf ( fp, "%d", &item ) ) {
//         Insert ( H, item );
//     }
//     return H;
// }

bool getData ( int* arr, int maxSize ) {
    int item;

    FILE* fp = fopen ( "./test.txt", "r" );
    if ( fp == NULL ) {
        cout << "指针为空" << endl;
        return false;
    } else {
        for ( int i = 1; i <= maxSize; i++ ) {
            fscanf ( fp, "%d", &arr[ i ] );
        }
        return true;
    }
}

Heap Create ( int maxSize ) {
    Heap H = Init ( maxSize );
    if ( !H || !getData ( H->arr, maxSize ) ) {
        return NULL;
    } else {
        H->size = maxSize;
        for ( int i = maxSize / 2; i >= 1; i-- ) {
            adjustDown ( H->arr, i, maxSize );
        }
        return H;
    }
}


int main () {
    enum type { INSERT = 1, DELETE, FREE };    // 1,2,3
    Heap H = Create ( 6 );
    int  order;
    cin >> order;
    while ( order != -1 ) {
        switch ( order ) {
            case INSERT: {
                if ( isFull ( H ) ) {
                    cout << "最大堆已满";
                    break;
                } else {
                    int item;
                    cin >> item;
                    Insert ( H, item );
                    break;
                }
            }
            case DELETE:
                if ( isEmpty ( H ) ) {
                    cout << "最大堆已空" << endl;
                } else {
                    int num = Delete ( H );
                    cout << "删除的数据为" << num << endl;
                }
                break;
            case FREE:
                free ( H->arr );
                free ( H );
                break;
            default:
                break;
        }
        cin >> order;
    }
    return 0;
}