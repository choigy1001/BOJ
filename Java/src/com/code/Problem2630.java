package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem2630 {
    static int[][] paper;
    static int white=0, blue = 0;
    static void divide(int row, int col, int size) {
        int temp = paper[row][col];
        boolean flag = true;

        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (temp != paper[i][j]) {
                    flag = false;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (!flag) {
            divide(row, col, size / 2);
            divide(row, col + size / 2, size / 2);
            divide(row + size / 2, col, size / 2);
            divide(row + size / 2, col + size / 2, size / 2);
            return;
        }
        if (temp == 0) {
            white++;
        } else {
            blue++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        paper = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                paper[i][j] = parseInt(st.nextToken());
            }
        }
        divide(0, 0, N);
        System.out.println(white);
        System.out.println(blue);

    }
}
