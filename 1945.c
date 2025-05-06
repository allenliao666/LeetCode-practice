int getLucky(char* s, int k) {
    int sum = 0, temp = 0;
    for(int i = 0; s[i] != '\0'; i++){
        int temp = s[i] - 'a' + 1;
        while(temp){
            sum += temp % 10;
            temp /= 10;
        }
    }
    if(k==1) return sum;
    while(k-1){
        int temp = 0;
        while(sum){
            temp += sum % 10; 
            sum /= 10; 
        }
        sum = temp;
        k--;
    }
    return sum;
}