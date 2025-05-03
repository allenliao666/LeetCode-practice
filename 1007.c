int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    int vcnt = 0, val = 0;
    int sum = 0, msum = 0;
    for(int i = 0; i < topsSize; i++){
        if(tops[i] == tops[0]) vcnt++;
        if(bottoms[i] == tops[0]) vcnt++;
        if(bottoms[i] == tops[i]) {
            val = bottoms[i];
            break;
        }
    }
    if(val==0) val = (vcnt >= topsSize) ? tops[0] : bottoms[0];
    for(int i = 0; i < topsSize; i++){
        if(tops[i]==val && bottoms[i]!=val) sum++;
        else if(tops[i]!=val && bottoms[i]==val) msum++;
        else if(tops[i]!=val && bottoms[i]!=val) return -1;
    } 
    return sum >= msum ? msum : sum;
} 