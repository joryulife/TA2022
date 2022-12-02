# ここに関数 duplist() の定義を書く
def duplist(list,n=2):
    return list*n

# 以下を変更してはいけません
l = [1, 2, 3]
num = int(input())
print(duplist(list=l))
print(duplist(list=l, n=num))