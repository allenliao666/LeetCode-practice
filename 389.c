//bit operation
char findTheDifference(char* s, char* t) {
    int i = strlen(s);
    char t_sum = t[i--];
    for(; i >= 0; i--)
        t_sum ^= (t[i] ^ s[i]);
    return t_sum;
}
// count number of char
// char findTheDifference(char* s, char* t) {
//     int *cnt = calloc(26, sizeof(int));
//     for(int i = 0; t[i] != '\0';i++)
//         cnt[t[i] - 97]++; 
//     for(int i = 0; s[i] != '\0';i++)
//         cnt[s[i] - 97]--;
//     for(int i =0; i < 26;i++){
//         printf("%d", cnt[i]);
//         if(cnt[i] > 0) return i + 97;
//     }
//     return NULL;
// }