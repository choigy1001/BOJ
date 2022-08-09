package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem21921 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int X = parseInt(st.nextToken());
        int[] daily = new int[N + 1];

        st = new StringTokenizer(br.readLine(), " ");

        for (int i = 1; i <= N; i++) {
            daily[i] = parseInt(st.nextToken()) + daily[i - 1];
        }

        int periodMax = 0, cnt = 0;
        for (int i = X; i <= N; i++) {
            int periodSum = daily[i] - daily[i - X];
            if (periodMax < periodSum) {
                periodMax = periodSum;
                cnt = 1;
            } else if (periodMax == periodSum) {
                cnt++;
            }
        }
        if (periodMax == 0) {
            System.out.println("SAD");
            return;
        }
        System.out.println(periodMax);
        System.out.println(cnt);

    }
}
