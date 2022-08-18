package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem17829 {
    static int[][] array;

    private static int secondValue(int row, int col) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = row; i < row + 2; i++) {
            for (int j = col; j < col + 2; j++) {
                list.add(array[i][j]);
            }
        }
        Collections.sort(list);
        return list.get(2);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        array = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                array[i][j] = parseInt(st.nextToken());
            }
        }
        while (N > 1) {
            for (int i = 0; i < N; i+=2) {
                for (int j = 0; j < N; j+=2) {
                    array[i/2][j/2] = secondValue(i, j);
                }
            }
            N = N / 2;
        }
        System.out.println(array[0][0]);

    }
}
