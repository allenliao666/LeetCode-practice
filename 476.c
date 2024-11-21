//find closest power
int findComplement(int num) {
    long closestPower = 1;
    while(closestPower <= num){
        closestPower <<= 1;
    }
    return (closestPower - 1) ^ num ;
}

//find first set bit
// int findComplement(int num) {
//     unsigned int x = num;
//     int i = 31; 
//     while(i >= 0){
//         if((x >> i) & 0b1 == 1) break;
//         i--;
//     }
//     return ((0xffffffff - x) << (31 - i)) >> (31 - i);
// }