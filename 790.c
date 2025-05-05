int numTilings(int n) {
    const int mod = 1e9 + 7;
    int dp[4];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i = 4; i <= n; i++){
        dp[i%4] = ((long long)dp[(i-1)%4] * 2 + (long long)dp[(i-3)%4]) % mod;
    }
    return dp[n%4];
}