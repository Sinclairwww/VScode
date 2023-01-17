#include <stdio.h>

void swap ( int* a, int* b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void down ( int* arr, int size, int root ) {
    int parent = root;
    int child = parent * 2 + 1;
    while ( child < size ) {
        if ( child + 1 < size && arr[ child ] < arr[ child + 1 ] )
            child++;
        if ( arr[ child ] <= arr[ parent ] ) {
            break;
        } else {
            swap ( &arr[ child ], &arr[ parent ] );
            parent = child;
            child = parent * 2 + 1;
        }
    }
}