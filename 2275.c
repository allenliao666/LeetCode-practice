int largestCombination(int* candidates, int candidatesSize) {
    //from bitwise view, count number of elements which has same setted bit
    int max = 1;
    for(int i = 0; i < 32; i++){
        int temp = 0;
        for(int j = 0 ; j < candidatesSize; j++)
            if(candidates[j] >> i & 0b1) temp++;
        if(max < temp) max = temp;
    }
    return max;
}