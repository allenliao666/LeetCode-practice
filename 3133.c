long long minEnd(int n, int x) {
    // n = 2 x = 4  [4, 5]
    // n = 3 x = 5  [5, 6, 13]
    long long target = n - 1;
    long long ans = 0;
    long long digit = 0;
    long long bit;
    while(target || x){
        //if SLB is 1
        if(x & 0b1 == 1) bit = 1;
        else{
            bit = target & 0b1;
            target >>= 1; 
        }
        x >>= 1;
        ans |= (bit << digit++);
    }
    return ans;
}

// long long minEnd(int n, int x) {
//     // n = 2 x = 4  [4, 5]
//     // n = 3 x = 5  [5, 6, 13]
//     long long ans = (long long)x;
    
//     for (; n > 1; n--) {
//         ans++;
//         ans |= (long long)x;
//     }    

//     return ans;
// }
