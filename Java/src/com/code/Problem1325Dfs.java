package com.code;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem1325Dfs {
    static ArrayList<Integer>[] list;
    static boolean[] visit;
    static int[] maxArray;
    static int cnt;
    static int dfs(int node) {
        visit[node] = true;
        for (Integer num : list[node]) {
            if (!visit[num]) {
                visit[num] = true;
                cnt++;
                dfs(num);
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int M = parseInt(st.nextToken());
        list = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int firstNode = parseInt(st.nextToken());
            int secondNode = parseInt(st.nextToken());
            list[secondNode].add(firstNode);
//            list[firstNode].add(secondNode);
        }
        int max = 0;
        maxArray = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            cnt = 0;
            visit = new boolean[N + 1];
            int result = dfs(i);
            maxArray[i] = result;
            max = Math.max(result, max);

        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 1; i <= N; i++) {
            if (max == maxArray[i]) {
                bw.write(i + " ");
            }
        }
        bw.close();
        br.close();
    }
}
