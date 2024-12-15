struct node{
    double val;
    int idx;
};

#define get_parent(idx) ((idx - 1) >> 1)
#define get_lchild(idx) ((idx << 1) + 1)
#define get_rchild(idx) ((idx << 1) + 2)

void swap(struct node *a, struct node *b){
    struct node temp = *a;
    *a = *b;
    *b = temp;
}

void heap_sort(struct node *stack, int *size, int idx){
    int parent = get_parent(idx);
    while(idx && stack[parent].val < stack[idx].val){
        swap(stack + parent, stack + idx);
        idx = parent;
        parent = get_parent(idx);
    }

    int lc = get_lchild(idx);
    int rc = get_rchild(idx);
    while(lc < *size && (stack[lc].val > stack[idx].val || stack[rc].val > stack[idx].val)){
        if(*size <= rc) rc = lc;
        if(stack[lc].val > stack[rc].val) rc = lc;
        swap(stack + rc, stack + idx);
        idx = rc;
        lc = get_lchild(idx);
        rc = get_rchild(idx);
    }
}

void heap_insert(struct node *stack, int *size, struct node input){
    stack[*size] = input;
    heap_sort(stack, size, *size);
    ++(*size);
}

struct node heap_pop(struct node *stack, int *size){
    struct node res = stack[0];
    stack[0] = stack[*size - 1];
    --(*size);
    heap_sort(stack, size, 0);
    return res;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    struct node heap[classesSize];
    int heap_size = 0;
    for(int i = 0; i < classesSize; i++){
        struct node cur;
        cur.val = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        cur.val -= (double)(classes[i][0]) / (classes[i][1]);
        cur.idx = i;
        heap_insert(heap, &heap_size, cur);
    }

    while(extraStudents){
        struct node cur = heap_pop(heap, &heap_size);
        ++classes[cur.idx][0];
        ++classes[cur.idx][1];
        cur.val = (double)(classes[cur.idx][0] + 1) / (classes[cur.idx][1] + 1);
        cur.val -= (double)(classes[cur.idx][0]) / (classes[cur.idx][1]);
        heap_insert(heap, &heap_size, cur);
        --extraStudents;
    }

    double total = 0;
    for(int i = 0; i < classesSize; i++) total += (double) classes[i][0] / classes[i][1];
    return total /= classesSize;
}