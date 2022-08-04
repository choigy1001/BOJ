package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem13305 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        int[] dist = new int[N];
        int[] cost = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N - 1; i++) {
            dist[i] = parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            cost[i] = parseInt(st.nextToken());
        }
        long totalCost = 0;
        int minOilCost = MAX_VALUE;
        for (int i = 0; i < N - 1; i++) {
            minOilCost = Math.min(minOilCost, cost[i]);
            totalCost += (long) dist[i] * minOilCost; //타입캐스트 해주자
        }
        System.out.println(totalCost);
        
    }
}
