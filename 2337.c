bool canChange(char* start, char* target) {
    int i = 0, j = 0, n = strlen(start);
    for(; i < n || j < n; ++i, ++j){
        while(i < n && start[i] == '_') ++i;
        while(j < n && target[j] == '_') ++j;
        if(i == n || j == n || start[i] != target[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) break;
    }
    return i == n && j == n;
}