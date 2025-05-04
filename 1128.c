int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int res = 0;
    int map[45] = {0};
    for(int i = 0; i < dominoesSize; i++){
        if(dominoes[i][0] > dominoes[i][1]){
            int temp = dominoes[i][0];
            dominoes[i][0] = dominoes[i][1];
            dominoes[i][1] = temp;
        }
    }
    for(int i = 0; i < dominoesSize; i++){
        int cell = (dominoes[i][0]-1) * 9 + dominoes[i][1] - ((dominoes[i][0] * (dominoes[i][0]-1))/2) - 1;
        map[cell]++;
    }
    for(int i = 0; i < 45; i++){
        if(map[i] >= 2){
            int temp = (map[i] * (map[i]-1))/2;
            res += temp;
        }
    }
    return res;
}