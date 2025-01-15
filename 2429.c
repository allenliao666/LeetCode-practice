int minimizeXor(int num1, int num2) {
    int bit, move = 0, temp = 0;
    int set1 = __builtin_popcount(num1),set2 = __builtin_popcount(num2);
    while(set1 > set2){
        bit = 1 << move;
        if(num1 & bit){
            num1 ^= bit;
            set1--;
        }
        move++;               
    }
    while(set1 < set2){
        bit = 1 << move;
        if(!(num1 & bit)){
            num1 |= bit;
            set1++;
        }
        move++;    
    }
    return num1;
}