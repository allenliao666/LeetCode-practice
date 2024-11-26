int similarPairs(char** words, int wordsSize) {
    int res = 0;
    int *hashTable = calloc(wordsSize, sizeof(int));
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; words[i][j] != '\0'; j++)
            hashTable[i] |= (1 << (words[i][j] - 96));
    }
    for(int i = 0; i < wordsSize - 1; i++) 
        for(int j = i + 1; j < wordsSize; j++) 
            if(!(hashTable[i] ^ hashTable[j])) res++;
    return res;
}

// int similarPairs(char** words, int wordsSize) {
//     int res = 0;
//     for(int i = 0; i < wordsSize; i++){
//         int map = 0;
//         for(int j = 0; words[i][j] != '\0'; j++)
//             map |= (1 << (words[i][j] - 96));
//         for(int j = i + 1; j < wordsSize; j++){
//             int map1 = 0;
//             for(int k = 0; words[j][k] != '\0';k++){
//                 map1 |= (1 << (words[j][k] - 96));
//             }
//             if(!(map ^ map1)) res++;
//         }
//     }
//     return res;
// }