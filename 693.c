//compare values of last two bits
bool hasAlternatingBits(int n) {
    while(n){
        if((n & 0b1) == ((n>>1) & 0b1)) return false;
        n >>= 1;
    }
    return true;
}

// bool hasAlternatingBits(int n) {
//     long closestPower = 1;
//     while(closestPower <= n)
//         closestPower <<= 1;
//     unsigned int mask = (0xaaaaaaaa & (closestPower - 1));
//     unsigned int mask1 = (0x55555555 & (closestPower - 1));
//     return (n ^ mask) == 0 || (n ^ mask1) == 0 ? true : false;
// }