package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.*;

public class Problem1913 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        int findNum = parseInt(br.readLine());

        int[][] snail = new int[N][N];

        int limit = 1;
        int cnt = 1;
        int x = N / 2;
        int y = N / 2;

        StringBuilder sb = new StringBuilder();
        while (true) {
            for (int i = 0; i < limit; i++) {
                snail[y--][x] = cnt++;
            }
            if (cnt-1 == N * N) {
                break;
            }
            for (int i = 0; i < limit; i++) {
                snail[y][x++] = cnt++;
            }

            limit++;
            for (int i = 0; i < limit; i++) {
                snail[y++][x] = cnt++;
            }
            for (int i = 0; i < limit; i++) {
                snail[y][x--] = cnt++;
            }
            limit++;
        }
        int findx = 0;
        int findy = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (findNum == snail[i][j]) {
                    findy = i + 1;
                    findx = j + 1;
                }
                sb.append(snail[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
        System.out.print(findy + " " + findx);
    }
}
