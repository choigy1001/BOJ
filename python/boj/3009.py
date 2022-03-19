import sys

input = sys.stdin.readline

if __name__ == '__main__':
    raw = 3
    data = [list(map(int, input().split())) for _ in range(raw)]

    if data[0][0] == data[1][0]:
        x = data[2][0]
    elif data[0][0] == data[2][0]:
        x = data[1][0]
    else:
        x = data[0][0]

    if data[0][1] == data[1][1]:
        y = data[2][1]
    elif data[0][1] == data[2][1]:
        y = data[1][1]
    else:
        y = data[0][1]
    print(x, y)