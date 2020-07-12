// Top-down method: Time Limit Exceeded


int numTrees(int n){
    // boundary condition
    if(n == 0) return 1;
    
    int ret = 0;
    
    for(int i=0; i<n; i++) {
        ret += (numTrees(i) * numTrees(n-1-i));
    }
    
    return ret;
}

// DP method


int numTrees(int n){
    // boundary condition
    unsigned int* dp = (int*)malloc(sizeof(int) * (n+1));
    dp[0] = 1;
    
    for(int i=1; i<=n; i++) {
        unsigned int ret = 0;
        for(int j=0; j<i; j++) {
            ret += dp[j] * dp[i-1-j];
        }
        dp[i] = ret;
    }
    
    return dp[n];
}
