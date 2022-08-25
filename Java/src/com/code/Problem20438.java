package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem20438 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int K = parseInt(st.nextToken());
        int Q = parseInt(st.nextToken());
        int M = parseInt(st.nextToken());

        int[] student = new int[N + 3];
        Arrays.fill(student, 1);

        boolean[] sleep = new boolean[N + 3];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < K; i++) {
            sleep[parseInt(st.nextToken())] = true;
        }
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < Q; i++) {
            int num = parseInt(st.nextToken());
            if (sleep[num]) {
                continue;
            }
            int next = 0;
            while ((next += num) <= N + 2) {
                if (sleep[next]) {
                    continue;
                }
                student[next] = 0;
            }
        }
        for (int i = 3; i <= N + 2; i++) {
            student[i] += student[i - 1];
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int S = parseInt(st.nextToken());
            int E = parseInt(st.nextToken());
            sb.append(student[E] - student[S - 1]).append("\n");
        }
        System.out.println(sb);
    }
}
