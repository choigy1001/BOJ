import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    data = list(map(int, input().split()))
    data.sort()
    print(data[7])
