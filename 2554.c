int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    bool *ban = calloc(n + 1, sizeof(bool));
    int sum = 0;
    for(int i = 0; i < bannedSize; i++){
        if(banned[i] <= n) ban[banned[i]] = 1;
    }
    for(int i = 1; i < n + 1; i++){
        if(!ban[i] && maxSum - i >= 0) {
            maxSum -= i;
            sum++;
        }
        if(!maxSum) return sum;
    }
    return sum;
}