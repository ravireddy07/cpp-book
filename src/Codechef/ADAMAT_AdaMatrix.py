# cook your dish here
t = int(input())
while(t>0):
    t-=1
    pp =int(input())
    count=0; blist=[]
    for i in range(pp):
        blist.append([int(x) for x in input().split()])
    for d in range(pp-1, 0, -1):
        done = blist[d][d-1]+1
        if done!=blist[d][d]:
            count+=1
            don = d+1
            for i in range(don):
                for j in range(i, don):
                    trav = blist[i][j]
                    blist[i][j] = blist[j][i]
                    blist[j][i] = trav
    print(count)