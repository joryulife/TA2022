def minmax(li):
    min = max = li[0]
    for i in li:
        if min > i:
            min = i
        if max < i:
            max = i
    return min,max


# 以下は変更してはいけません
l = [int(x) for x in input().split()]
print(minmax(l))