int binaryGap(int n) {
    int max = 0, lastSet = -1;
    for(int i = 0; n > 0; i++){
        if(n & 0b1){
            if(lastSet != -1) max = fmax(max, i - lastSet);
            lastSet= i;
        }
        n >>= 1;
    }
    return max;
}

// int binaryGap(int n) {
//     int max = 0;
//     while((n & 0b1) == 0){
//         n >>= 1;
//     }
//     int temp = 1;
//     n >>= 1;
//     while(n){
//         if((n & 0b1) == 0) temp++;
//         else {
//             max = max > temp ? max : temp;
//             temp = 1;
//         }
//         n >>= 1;
//     }
//     return max;
// }

// int binaryGap(int n) {
//     int max = 0;
//     int cnt = __builtin_popcount(n);
//     while((n & 0b1) == 0){
//         n >>= 1;
//     }
//     while(cnt - 1){
//         n >>= 1;
//         int temp = 1;
//         while((n & 0b1) == 0) {
//             n >>= 1;
//             temp++;
//         }
//         if(max < temp) max = temp;
//         cnt--;    
//     }
//     return max;
// }