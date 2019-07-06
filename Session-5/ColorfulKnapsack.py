for j from 1 to x:
    dp[1][j]=-1
    for weight in vector(1):
        if weight<=j:
            dp[1][j]=max(dp[1][j],weight)


for i from 2 to m:
    for j from 1 to x:
        dp[i][j]=-1
        if i>x:
            break
        for weight in vector(m):
            if j>weight && dp[i-1][j-weight]>0:
                dp[i][j]=max(dp[i][j],dp[i-1][j-weight]+weight)
