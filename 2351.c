char repeatedCharacter(char* s) {
    int cnt[26] = {0};
    for(int i = 0; s[i] != '\0';i++){
        cnt[s[i] - 97]++;
        if(cnt[s[i] - 97] == 2) return s[i];
    }
    return s[0];
}