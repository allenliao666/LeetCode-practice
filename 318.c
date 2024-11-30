int maxProduct(char** words, int wordsSize) {
    int max = 0;
    int mask[1000] = {0};
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; words[i][j] != '\0'; j++){
            mask[i] |= (0b1 << (words[i][j] - 97));
        }
    }
    for(int i = 0; i < wordsSize; i++){
        for(int j = i + 1; j < wordsSize; j++){
            if(!(mask[i] & mask[j])){
                int temp = strlen(words[i]) * strlen(words[j]);
                if(max < temp) max = temp;
            }
        }
    }
    return max;
}

// int maxProduct(char** words, int wordsSize) {
//     int max = 0;
//     for(int i = 0; i < wordsSize; i++){
//         int mask = 0, alength = 0;
//         for(int j = 0; words[i][j] != '\0'; j++){
//             mask |= (0b1 << words[i][j] - 97);
//             alength++;
//         }
//         for(int j = i + 1; j < wordsSize; j++){
//             int blength = 0;
//             for(int k = 0; words[j][k] != '\0'; k++){
//                 if(mask & (0b1 << words[j][k] - 97)) {
//                     blength = 0;
//                     break;
//                 }
//                 else blength++;
//             }
//             if(max < alength * blength) max = alength * blength;
//         }

//     }
//     return max;
// }