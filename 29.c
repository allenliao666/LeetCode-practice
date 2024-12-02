int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    bool sameSign = (dividend < 0 == divisor < 0);
    unsigned int a = dividend != INT_MIN ? abs(dividend) : INT_MAX + 1;
    unsigned int b = divisor != INT_MIN ? abs(divisor) : INT_MAX + 1;
    unsigned int res = 0;
    while(a >= b){
        short bit = 0;
        while(a > b << (bit + 1)) bit++;
        res += (1 << bit);
        a -= (b << bit);
    }
    if(res == INT_MAX + 1 && sameSign) return INT_MAX;
    return sameSign ? res : -res;
}