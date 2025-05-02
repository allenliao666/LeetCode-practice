void fill(char* domi, int left, int right, char mark){
    for(int i = left; i <= right; i++){
        domi[i]=mark;
    }
}
char* pushDominoes(char* dominoes) {

    int left = 0, right = 1;
    while(dominoes[right]!=NULL){
        if(dominoes[right]!='.'){
            if(dominoes[left]==dominoes[right]){
                fill(dominoes, left+1, right-1, dominoes[right]);
            }else if(dominoes[left]=='.' && dominoes[right]=='L'){
                fill(dominoes, 0, right-1, 'L');
            }else if(dominoes[left]=='R'){
                int i = left+1, j = right-1;
                while(i < j){
                    dominoes[i++] = 'R';
                    dominoes[j--] = 'L';
                }
            }
            left = right;
            right++;
        }else{
            right++;
        }
    }
    if(dominoes[left]=='R'){
        fill(dominoes, left + 1, right -1, 'R');
    }
    return dominoes;
}