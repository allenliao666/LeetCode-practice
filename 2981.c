bool isExist(char *s, int m){
    int freq['z' + 1] = {};
    char prev = *s++;
    int sLen = 1;
    while(1){
        char curC = *s++;
        if(curC == prev) ++sLen;
        else{
            if(sLen >= m){
                freq[prev] += sLen - m + 1;
                if(freq[prev] >= 3) return true;
            }
            if(curC == '\0') break;
            sLen = 1;
            prev = curC;
        }
    }
    return false;
}
int maximumLength(char* s) {
    int l = 1, r = strlen(s) - 2;
    while(l <= r){
        int m = (l + r)/ 2;
        isExist(s, m) ? (l = m + 1) : (r = m - 1);
    }
    return r ? r : -1; 
}

// int maximumLength(char* s) {
//     int ans = -1, sLen = 0, strLen = strlen(s);
//     char curC = '\0';
//     int sList[26][51] = {0};
//     for(int i = 0; i < strLen; i++){
//         if(curC != s[i]){
//             if(sLen > 0){
//                 sList[curC - 'a'][sLen]++;
//                 if(sList[curC - 'a'][sLen] >= 3) ans = ans > sLen ? ans : sLen;
//             }
//             if(sLen > 1){
//                 sList[curC - 'a'][sLen - 1] += 2;
//                 if(sList[curC - 'a'][sLen - 1] >= 3) ans = ans > sLen - 1? ans : sLen - 1;
//             }
//             if(sLen > 2) ans = ans > sLen - 2? ans : sLen - 2;
//             sLen = 1;
//             curC = s[i];
//         }else sLen++;
//     }

//     if(sLen > 0){
//         sList[curC - 'a'][sLen]++;
//         if(sList[curC - 'a'][sLen] >= 3) ans = ans > sLen ? ans : sLen;
//     }
//     if(sLen > 1){
//         sList[curC - 'a'][sLen - 1] += 2;
//         if(sList[curC - 'a'][sLen - 1] >= 3) ans = ans > sLen - 1? ans : sLen - 1;
//     }
//     if(sLen > 2) ans = ans > sLen - 2? ans : sLen - 2;
//     return ans;
// }