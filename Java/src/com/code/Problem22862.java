package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem22862 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int K = parseInt(st.nextToken());

        int[] S = new int[N];
        boolean[] check = new boolean[N];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            S[i] = parseInt(st.nextToken());
            if (S[i] % 2 == 1) {
                check[i] = true;
            }
        }
        int start = 0, end = 0, result = 0, count = 0;
        while (end < N) {
            if (count < K) {
                if (check[end]) {
                    count++;
                }
                end++;
                result = Math.max(result, end - start - count);
            } else if (count == K && check[end]) {
                if (check[start]) {
                    count--;
                }
                start++;
            } else if (count == K && !check[end]) {
                end++;
                result = Math.max(result, end - start - count);
            }
        }
        System.out.println(result);

    }
}
