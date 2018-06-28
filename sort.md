## 堆排序
在堆排序算法中，我们使用最大堆。最小堆通常在构造优先队列时使用，本质其实一样。

堆可以被看成是一棵树。
叶子结点的高度为0。
二叉堆的高度为树根的高度O(log n)。
二叉堆是一棵完全二叉树（除了最后一层外每层都是满的）。
对于最大堆而言，父节点一定大于等于子节点。最大元素在根结点。

MAX-HEAPIFY,保持堆序 O(log n)

BUILD-MAX-HEAP,线性时间运行，构建最大堆

HEAPSORT O(n * log n)


#### MAX-HEAPIFY
对数组进行调整，输入为数组A和下标i,假定LEFT(i)和RIGHT(i)为根的两棵二叉树都是最大堆，但是A[i]可能小于其子女，所以要调整堆序让A[i]在堆中下降。

```
MAX-HEAPIFY(A,i)
    l <- LEFT(i)
    r <- RIGHT(i)
    if l <= heap-size[A] and A[l]>A[i]
        then largest <- l
        else largest <- i
    if r <= heap-size[A] and A[r] > A[largest]
        then largest <-r
    if largest != i
        then exchange A[i] <-> A[largest]
            MAX-HEAPIFY(A, largest)
```

#### BUILD-MAX-HEAP
```
BUILD-MAX-HEAP(A)
    heap-size[A] <- length(A)
    for i <- [length[A]/2] downto 1
        do MAX-HEAPIFY(A, i)
```

## 快速排序
经典的分治算法

```
QUICKSORT(A, p, r)
if p < r
    then q <- PARTION(A, p, r)
        QUICKSORT(A, p, q-1)
        QUICKSORT(A, q+1, r)

PARTITION(A, p, r)
x <- A[r]
i <- p-1
for j <- p to r-1
    do if A[j] <= x
        then i <- i+1
            exchange A[i] <-> A[j]
exchange A[i+1] <-> A[r]
return i+1
```

# 线性时间排序
计数排序，基数排序，桶排序

## 计数排序
如果数据都差不多大，计数排序贼牛逼。空间换时间

```
COUNTING-SORT(A,B,k)
for i in 0 to k
    C[i] = 0
for j in 1 to length(A)
    C[A[j]] <- C[A[j]] + 1
```


