package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem1806 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int S = parseInt(st.nextToken());

        int[] sequence = new int[N + 1];

        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= N; i++) {
            sequence[i] = parseInt(st.nextToken()) + sequence[i - 1];
        }
        int start = 0, end = 1;
        if (sequence[N] < S) {
            System.out.println(0);
            return;
        }
        int len = MAX_VALUE;
        while (end < sequence.length) {
            int sum = sequence[end] - sequence[start];
            if (sum >= S) {
                len = Math.min(len, end - start);
                start++;
            } else {
                end++;
            }
        }
        System.out.println(len);

    }
}
