package com.code;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem1325 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = parseInt(st.nextToken());
        int M = parseInt(st.nextToken());
        ArrayList<Integer>[] list = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int firstNode = parseInt(st.nextToken());
            int secondNode = parseInt(st.nextToken());
            list[secondNode].add(firstNode);
        }
        int max = 0;
        int[] maxArray = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            Queue<Integer> queue = new LinkedList<>();
            boolean[] visited = new boolean[N + 1];
            visited[i] = true;
            queue.add(i);
            int cnt = 0;
            while (!queue.isEmpty()) {
                Integer front = queue.poll();
                for (Integer num : list[front]) {
                    if (!visited[num]) {
                        visited[num] = true;
                        queue.add(num);
                        cnt++;
                    }
                }
            }
            max = Math.max(max, cnt);
            maxArray[i] = cnt;
        }
        //안해주면 시간초과 났음
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 1; i <= N; i++) {
            if (max == maxArray[i]) {
                bw.write(i + " ");
            }
        }
        bw.close();
    }
}
