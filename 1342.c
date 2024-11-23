int numberOfSteps(int num) {
    int cnt = 0;
    while(num){
        num = (num & 0b1) == 1 ? num-1 : num >> 1;
        cnt++;
    }
    return cnt;
}