int min(int a, int b){
    return a <= b ? a : b;
}
int minCostClimbingStairs(int* cost, int costSize) {
    if(costSize == 2) return min(cost[0], cost[1]); 
    if(costSize == 3) return min(cost[1], cost[0] + cost[2]); 
    int costNow = 0, prev2 = cost[0], prev1 = cost[1], temp;
    for(int i = 2 ; i < costSize; i++){
        costNow = min(prev2, prev1) + cost[i];
        prev2 = prev1;
        prev1 = costNow;
    }
    return min(prev2, prev1);
}