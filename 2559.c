bool isVol(char s){
    return s =='a' || s =='e' || s =='i' || s =='o' || s =='u';
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *map = malloc(wordsSize * sizeof(int));
    int *res = malloc(queriesSize * sizeof(int));
    int sum = 0;
    for(int i=0; i<wordsSize; i++){
        if(isVol(words[i][0]) && isVol(words[i][strlen(words[i])-1])) sum++;
        map[i] = sum;
    }
    for(int i=0; i<queriesSize; i++){
    res[i] = map[queries[i][1]] - (queries[i][0] == 0 ? 0 : map[queries[i][0]-1]);
    }
    *returnSize = queriesSize;
    return res;
}