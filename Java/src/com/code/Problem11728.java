package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem11728 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int M = parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        int[] A = new int[N+1];
        int[] B = new int[M+1];
        for (int i = 0; i < N; i++) {
            A[i] = parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < M; i++) {
            B[i] = parseInt(st.nextToken());
        }
        int[] total = new int[N + M];
        int aIndex = 0, bIndex = 0, totalIndex = 0;

        while (aIndex < N && bIndex < M) {
            if (A[aIndex] < B[bIndex]) {
                total[totalIndex++] = A[aIndex++];
            } else {
                total[totalIndex++] = B[bIndex++];
            }
        }
        for (int i = aIndex; i < N; i++) {
            total[totalIndex++] = A[i];
        }
        for (int i = bIndex; i < M; i++) {
            total[totalIndex++] = B[i];
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N + M; i++) {
            sb.append(total[i] + " ");
        }
        System.out.println(sb);

    }
}
