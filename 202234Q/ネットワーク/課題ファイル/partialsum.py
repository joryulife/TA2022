def partialSum(n, m):
    if n > m:
        n,m = m,n
    return ((n+m)*(m-n+1))//2


# 以下を変更してはいけません
n = int(input())
m = int(input())
print(partialSum(n, m))
