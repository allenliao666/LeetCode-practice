bool canConstruct(char* s, int k) {
    int cnt = 0;
    int map[26] = {0};
    if(strlen(s) < k) return false;
    for(int i=0; s[i] != '\0'; i++){
        map[s[i]-'a']++;
    }
    for(int i=0; i < 26; i++){
        if(map[i]%2) cnt++;
    }
    if(cnt <= k) return true;
    return false;
}