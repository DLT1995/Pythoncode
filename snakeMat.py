import numpy as np

while 1:
    n = input("请输入n: ")
    n = int(n)
    matrix = np.zeros((n, n))
    num = 0
    # 遍历连接上三角的斜线，包括对角线
    for i in range(0,n):
        if  i%2 == 0:  #则最小值在下面
            for j in range(i,-1,-1):  #上三角第i条斜线有i个点
                num = num + 1
                matrix[j][i-j] = num   # 有i个点所有行递增i次，每个点的行列相加等于i所以列=i-行
        else:   # 否则最小值在上面
            for j in range(0,i+1):     # 和最小值在下面类似
                num = num + 1
                matrix[j][i-j] = num

    # 遍历连接下三角的斜线，比上三角复杂
    for i in range(n-2,-1,-1):   # 为了通过每条斜线的点数i控制行列关系所以递减i
        if i%2==0:  #则最小值在下面
            tem = n  # 最小值在下面用tem控制行递减
            for j in range(n-1-i,n):  # 列等于总列数减去该斜线的总点数i，减1是为了对应0
                tem = tem - 1
                num = num + 1
                matrix[tem][j] = num
        else :     #否则最小值在上面
            tem = n   # 同上
            for j in range(n-1-i,n):
                tem = tem - 1
                num = num + 1
                matrix[j][tem] = num
    print(matrix)