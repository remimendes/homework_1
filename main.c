#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(int* a, int size, int i) {
    int l = i*2;
    int r = i*2+1;
    int largest;
    if (l <= size && a[l-1] > a[i-1]){
        largest = l;
    } else {
        largest = i;
    }
    if (r <= size && a[r-1] > a[largest-1]) {
        largest = r;
    }
    if (largest != i){
        swap(&a[i-1],&a[largest-1]);
        maxHeapify(a,size ,largest);
    }
}

void heapDelete(int* a, int size, int i){
    if (size<1){
        fprintf(stderr,"heap underflow");
        return;
    }
    swap(&a[size-1], &a[i-1]);
    size--;
    a = (int *) reallocarray(a, size, sizeof(int));
    if (a == NULL) {
        fprintf(stderr,"error when trying to reduce the memory size of the heap");
    }
    maxHeapify(a,size,i);
}

int main() {
    //example of usage of the function
    int *heap;
    int size = 11;
    heap = (int *)malloc(size * sizeof(int));
    if (heap == NULL) {
        fprintf(stderr,"error when trying to allocate memory for the heap");
        return 1;
    }
    heap[0] = 5;
    heap[1] = 3;
    heap[2] = 2;
    heap[3] = 0;
    heap[4] = 1;
    heap[5] = 1;
    heap[6] = 1;
    heap[7] = -1;
    heap[8] = -2;
    heap[9] = 0;
    heap[10] = -6;
    //index start at 1 in the array (not 0)
    heapDelete(heap,11,4);
    for (int i = 0;i<size-1;i++){
        printf("%d \n",heap[i]);
    }
    free(heap);
    return 0;
}
