char* restoreString(char* s, int* indices, int indicesSize) {
    char *res = (char *) malloc((indicesSize + 1) * sizeof(char));
    for(int i = 0; i < indicesSize; i++){
        res[indices[i]] = s[i];
    }
    res[indicesSize] = '\0';
    return res;
}