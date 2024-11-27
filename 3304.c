char kthCharacter(int k) {
    int exp = 1, times = 0, i = 0;
    while(exp < k) {
        exp <<= 1;
        times++;
    }
    char *s = malloc((exp + 1) * sizeof(char));
    s[0] = 'a';
    while(i < times){
        for(int j = 0; j < (1 << i) ; j++){
            int interval = 1 << i;
            if(s[j] < 122) s[j + interval] = s[j] + 1;
            else s[j + interval] = s[j] - 25;
        }
        i++;
    }
    return s[k - 1];
}