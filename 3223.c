int minimumLength(char* s) {
    int n = strlen(s), res = 0;
    int map[26] = {0};
    for(int i = 0; i < n; i++){
        map[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if (map[i]) {
        res += 2 - (map[i] & 1);
        }
    }
    return res;
}