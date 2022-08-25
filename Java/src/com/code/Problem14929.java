package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem14929 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] array = new int[N + 1];
        int[] sum = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            array[i] = parseInt(st.nextToken());
            sum[i] = sum[i - 1] + array[i];
        }
        long ans = 0;
        //식은 여러개  (x1)x2 + (x1+x2)x3 + (x1+x2+x3)x4 ~ (x1+ .. .+xn-1)xn도 가능
        for (int i = 1; i < N; i++) {
            ans += (long) array[i] * (sum[N] - sum[i]);
        }
        System.out.println(ans);
    }
}
