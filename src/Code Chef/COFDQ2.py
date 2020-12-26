# Problem Statement: https://www.codechef.com/COFDEC20/problems/COFDQ2

R,C=map(int,input().split())
A=[]
for i in range(R):
    p=list(map(int,input().split()))
    A.append(p)
m, n = len(A), len(A[0])
for i in range(m):
    if A[i][0] == 0: 
        for j in range(n): A[i][j] ^= 1 
        
for j in range(n): 
    cnt = sum(A[i][j] for i in range(m))
    if cnt < m - cnt: 
        for i in range(m): A[i][j] ^= 1

print(sum(int("".join(map(str, A[i])), 2) for i in range(m)))



# Author: Ravi Kanth Gojur
# Github: ravireddy07
