char* addSpaces(char* s, int* spaces, int spacesSize) {
    char *res = calloc(strlen(s) + spacesSize + 1 , sizeof(char));
    int idx = 0, str_len = 0;
    for(int i = 0; i < strlen(s) + spacesSize + 1; i++){
        if(idx < spacesSize && i == spaces[idx]){
            res[str_len++] = ' ';
            idx++;
        }
        if(i < strlen(s)) res[str_len++] = s[i];
    }
    return res;
}

// calloc() set every memory space to 0
// char* addSpaces(char* s, int* spaces, int spacesSize) {
//     char *res = calloc((strlen(s) + spacesSize + 1) , sizeof(char));
//     int lst_idx = 0, str_len = 0;
//     for(int i = 0; i < spacesSize; i++){
//         int s_idx = 0;
//         if(i) s_idx = spaces[i - 1];
//         int len = spaces[i] - s_idx;
//         memcpy(&res[str_len], &s[s_idx], len);
//         str_len += len;
//         res[str_len] = ' ';
//         str_len++;
//     }
//     if(spaces[spacesSize - 1] < strlen(s))
//         memcpy(&res[str_len], &s[spaces[spacesSize - 1]], strlen(s) - spaces[spacesSize - 1]);    
//     return res;
// }

// char* addSpaces(char* s, int* spaces, int spacesSize) {
//     for(int i = 0; i < spacesSize; i++){
//         spaces[i] += i;
//     }
//     char *res = malloc((strlen(s) + spacesSize + 1) * sizeof(char));
//     int idx = 0, t = 0;
//     for(int i = 0; i < strlen(s) + spacesSize; i++){
//         if(i != spaces[idx]){
//             res[i] = s[t++];
//         }else {
//             res[i] = ' ';
//             if(idx < spacesSize - 1) idx++;
//         }
//     }
//     res[strlen(s) + spacesSize] = '\0';
//     return res;
// }