struct node {
    int val;  // 數值
    int idx;  // 原始索引
};

#define get_parent(idx) (((idx) - 1) >> 1)
#define get_lchild(idx) (((idx) << 1) + 1)
#define get_rchild(idx) (((idx) << 1) + 2)

void swap(struct node* a, struct node* b) {
    struct node temp = *a;
    *a = *b;
    *b = temp;
}

// 調整堆的性質
void heap_sort(struct node* heap, int size, int idx) {
    // 上浮
    int parent = get_parent(idx);
    while (idx && (heap[parent].val > heap[idx].val || 
                      (heap[parent].val == heap[idx].val && heap[parent].idx > heap[idx].idx))) {
        swap(&heap[parent], &heap[idx]);
        idx = parent;
        parent = get_parent(idx);
    }

    // 下沉
    int lc = get_lchild(idx);
    int rc = get_rchild(idx);
    while (lc < size) {
        int smallest = idx;
        if (heap[lc].val < heap[smallest].val || 
            (heap[lc].val == heap[smallest].val && heap[lc].idx < heap[smallest].idx)) {
            smallest = lc;
        }
        if (rc < size && (heap[rc].val < heap[smallest].val || 
                          (heap[rc].val == heap[smallest].val && heap[rc].idx < heap[smallest].idx))) {
            smallest = rc;
        }
        if (smallest == idx) break;
        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
        lc = get_lchild(idx);
        rc = get_rchild(idx);
    }
}

// 插入堆
void heap_insert(struct node* heap, int* size, struct node input) {
    heap[*size] = input;
    heap_sort(heap, *size + 1, *size);
    ++(*size);
}

// 從堆中彈出最小值
struct node heap_pop(struct node* heap, int* size) {
    struct node res = heap[0];
    heap[0] = heap[*size - 1];
    --(*size);
    heap_sort(heap, *size, 0);
    return res;
}

// 主邏輯
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    // 建立堆
    struct node* heap = malloc(numsSize * sizeof(struct node));
    int heapSize = 0;
    for (int i = 0; i < numsSize; i++) {
        struct node temp;
        temp.val = nums[i];
        temp.idx = i;
        heap_insert(heap, &heapSize, temp);
    }

    // 進行 k 次操作
    for (int i = 0; i < k; i++) {
        struct node minNode = heap_pop(heap, &heapSize);  // 彈出最小值
        minNode.val *= multiplier;  // 更新最小值
        heap_insert(heap, &heapSize, minNode);  // 插回堆
    }

    // 構建結果數組
    int* result = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        struct node temp = heap_pop(heap, &heapSize);  // 逐一彈出堆元素
        result[temp.idx] = temp.val;  // 按索引填入結果數組
    }

    *returnSize = numsSize;
    free(heap);
    return result;
}

// // int finMin(int *nums, int numsSize){
// //     int min = INT_MAX, minIdx = 0;
// //     for(int i = 0; i < numsSize; i++){
// //         if(min > nums[i]){
// //             min = nums[i];
// //             minIdx = i;
// //         }
// //     }
// //     return minIdx;
// // }

// // int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
// //     while(k){
// //         int min = finMin(nums, numsSize);
// //         nums[min] *= multiplier;
// //         k--;
// //     }
// //     *returnSize = numsSize;
// //     return nums;
// // }