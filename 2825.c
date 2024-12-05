bool canMakeSubsequence(char* str1, char* str2) {
    int idx1 = 0, idx2 = 0;
    while(str2[idx2] != '\0'){
        char temp = str2[idx2] == 'a' ? 'z' : str2[idx2] - 1;
        if(str1[idx1] == temp || str1[idx1] == str2[idx2]) idx2++;
        if(str1[idx1] == '\0') return false;
        idx1++;
    }
    return true;
}  