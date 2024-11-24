void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
} 

int partition(int *arr, int l, int r){
    int p = arr[l];
    int pbit = __builtin_popcount(p);
    int lp = l, lbit = __builtin_popcount(arr[lp]);
    int rp = r, rbit = __builtin_popcount(arr[rp]);
    while(lp < rp){
        while(lbit <= pbit && lp <= r - 1){
            if(lbit == pbit && arr[lp] > p) break;
            lp++;
          
        }
        while(rbit >= pbit && rp >= l + 1){
            if(rbit == pbit && arr[rp] < p) break;
            rp--;
        }
        if(lp < rp) swap(&arr[lp], &arr[rp]);
    }
    swap(&arr[l], &arr[rp]);
    return rp;
}

void quickSort(int *arr, int l, int r){
    if(l < r){
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    quickSort(arr, 0, arrSize - 1);
    *returnSize = arrSize;
    return arr;
}