#include "util.h"
// ```
// MAX-HEAPIFY(A,i)
//     l <- LEFT(i)
//     r <- RIGHT(i)
//     if l <= heap-size[A] and A[l]>A[i]
//         then largest <- l
//         else largest <- i
//     if r <= heap-size[A] and A[r] > A[largest]
//         then largest <-r
//     if largest != i
//         then exchange A[i] <-> A[largest]
//             MAX-HEAPIFY(A, largest)
// ```

void max_heapify(int * arr, int i, int size) {
    int l, r, largest;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l <= size) {
        
    }
}