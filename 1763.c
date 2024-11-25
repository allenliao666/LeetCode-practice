char* longestNiceSubstring(char* s) {
    int max = 0, idx = -1;
    for(int i = 0; s[i] != '\0'; i++){
        int upper_case = 0, lower_case = 0;
        for(int j = i; s[j] != '\0'; j++){
            if(s[j] <= 'Z') upper_case |= (1 << (s[j] & 31));
            else lower_case |= (1 << (s[j] & 31));
            if((upper_case ^ lower_case) == 0) {
                if(max < j - i + 1){
                    max = j - i + 1;
                    idx = i;
                }
            }
        }
    }
    if(max == 0 || idx == -1) return "";
    s[idx + max] = '\0';
    return &s[idx];
}

// char* longestNiceSubstring(char* s) {
//     int max = 0, idx = -1;
//     for(int i = 0; s[i] != '\0'; i++){
//         int upper_case = 0, lower_case = 0;
//         for(int j = i; s[j] != '\0'; j++){
//             if(s[j] <= 'Z') upper_case |= (1 << (s[j] & 31));
//             else lower_case |= (1 << (s[j] & 31));

//             if((upper_case ^ lower_case) == 0) {
//                 if(max < j - i + 1){
//                     max = j - i + 1;
//                     idx = i;
//                 }
//             }
//         }
//     }
//     if(max == 0 || idx == -1) return "";
//     char *res = (char *) calloc((max + 1) , sizeof(char));
//     memcpy(res, &s[idx], max);
//     return res;
// }