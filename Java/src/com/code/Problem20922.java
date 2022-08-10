package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem20922 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = parseInt(st.nextToken());
        int K = parseInt(st.nextToken());

        int[] sequence = new int[N];
        int[] count = new int[200000];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            sequence[i] = parseInt(st.nextToken());
        }
        int start = 0, end = 0, result = 0;
        while (end < sequence.length) {
            while (end < sequence.length && count[sequence[end]] < K) {
                count[sequence[end]]++;
                end++;
            }
            result = Math.max(result, end - start);
            count[sequence[start]]--;
            start++;
        }
        System.out.println(result);

    }
}
