package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem2470 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] liquid = new int[N];
        for (int i = 0; i < N; i++) {
            liquid[i] = parseInt(st.nextToken());
        }
        Arrays.sort(liquid);

        int start = 0, end = N - 1;
        int sum = liquid[start] + liquid[end];
        int minNum = 0, maxNum = 0;
        while (end > start) {
            int temp = liquid[start] + liquid[end];
            if (Math.abs(temp) <= Math.abs(sum)) {
                sum = temp;
                minNum = liquid[start];
                maxNum = liquid[end];
            }
            if (temp < 0) {
                start++;
            } else {
                end--;
            }
        }
        System.out.println(minNum + " " + maxNum);

    }
}