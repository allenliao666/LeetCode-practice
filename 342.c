bool isPowerOfFour(int n) {
    // 4 T 00100
    // 5 F
    // -4 F
    return n > 0 && !(n & (n-1)) && (n & 0x55555555);
}