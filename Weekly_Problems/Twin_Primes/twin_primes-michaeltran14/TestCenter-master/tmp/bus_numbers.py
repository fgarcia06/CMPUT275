# put your solution here
n = int(input())
lst = list(map(int, input().split()))

lst = sorted(lst)


nlst = ""

i = 1

lst.append(-1)
tmp = [lst[0]]

while i < len(lst):
    if lst[i] == lst[i-1]+1:
        tmp.append(lst[i])
    else:
        if len(tmp)>2:
            nlst += str(tmp[0]) + "-" + str(tmp[-1]) + " "
        elif len(tmp) == 2:
            nlst +=  str(tmp[0]) +  " " + str(tmp[-1]) + " "
        else:
            nlst += str(tmp[0]) + " "

        tmp = [lst[i]]
    i += 1
    


print(nlst)
