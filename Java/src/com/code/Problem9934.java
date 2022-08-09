package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem9934 {
    static int K;
    static StringBuilder[] list;
    static int[] visit;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        K = parseInt(br.readLine());
        int size = (int) Math.pow(2, K) - 1;
        visit = new int[size];

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < size; i++) {
            visit[i] = parseInt(st.nextToken());
        }
        list = new StringBuilder[K];
        for (int i = 0; i < K; i++) {
            list[i] = new StringBuilder();
        }
        move(0, 0, size);

        for (int i = 0; i < K; i++) {
            System.out.println(list[i].toString());
        }
    }

    static void move(int depth, int left, int right) {
        if (depth == K) {
            return;
        }
        int mid = (left + right) / 2;
        list[depth].append(visit[mid] + " ");
        move(depth + 1, left, mid - 1);
        move(depth + 1, mid + 1, right);
    }

}
