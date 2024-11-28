int rangeBitwiseAnd(int left, int right) {
    int res = 0;
    for(int i = 30; i >= 0; i--){
        if((left & (0b1 << i)) == (right & (0b1 << i))) res |= (left & (0b1 << i));
        else break;
    }
    return res;
}