package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem15961 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int d = parseInt(st.nextToken());
        int k = parseInt(st.nextToken());
        int c = parseInt(st.nextToken());

        int[] belt = new int[N];
        int[] kind = new int[d + 1];

        for (int i = 0; i < N; i++) {
            belt[i] = parseInt(br.readLine());
        }
        int result = 0, total = 0;

        for (int i = 0; i < k; i++) {
            if (kind[belt[i]] == 0) {
                total++;
            }
            kind[belt[i]]++;
        }
        for (int i = 1; i < N; i++) {
            if (result <= total) {
                if (kind[c] == 0) {
                    result = total + 1;
                } else {
                    result = total;
                }
            }

            kind[belt[i - 1]]--;
            if (kind[belt[i - 1]] == 0) {
                total--;
            }

            if (kind[belt[(i + k - 1) % N]] == 0) {
                total++;
            }
            kind[belt[(i + k - 1) % N]]++;
        }
        System.out.println(result);

    }
}
