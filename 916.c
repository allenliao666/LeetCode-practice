char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int maxFeq[26] = {0};
    int tempFeq[26];

    for(int i=0; i<words2Size; i++){
        memset(tempFeq, 0, sizeof(tempFeq));
        for (int j = 0; words2[i][j] != '\0'; j++) {
            tempFeq[words2[i][j] - 'a']++;
        }
        for(int i=0; i<26; i++){
            maxFeq[i] = fmax(maxFeq[i], tempFeq[i]);
        }        
    }

    char **res = malloc(words1Size * sizeof(char *));
    *returnSize = 0;

    for(int i=0; i<words1Size; i++){
        memset(tempFeq, 0, sizeof(tempFeq));
        for (int j = 0; words1[i][j] != '\0'; j++) {
            tempFeq[words1[i][j] - 'a']++;
        }
        bool isUni = 1;
        for(int i=0; i<26; i++){
            if(tempFeq[i]<maxFeq[i]){
                isUni = 0;
                break;
            }
        }
        if(isUni){
            res[*returnSize] = strdup(words1[i]);
        (*returnSize)++;
        }  
    }
    return res;
}