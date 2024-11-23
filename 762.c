bool isp(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}
int countPrimeSetBits(int left, int right) {
    int ans = 0;
    while(left <= right){
        ans += isp(__builtin_popcount(left));
        left++;
    }
    return ans;
}

// int countPrimeSetBits(int left, int right) {
//     int ans = 0;
//     while(left <= right){
//         int setted = __builtin_popcount(left);
//         ans += (setted == 2 || setted == 3 || setted == 5 || setted == 7 || setted == 11 || setted == 13 || setted == 17 || setted == 19);
//         left++;
//     }
//     return ans;
// }