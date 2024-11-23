int bitwiseComplement(int n) {
    return n ? ((1 << (32 - __builtin_clz(n))) - 1) & ~n : 1;
}

// int bitwiseComplement(int n) {
//     long closest = 1;
//     while(closest <= n) 
//         closest <<= 1;
//     return n ? n ^= (closest - 1) : 1;
// }