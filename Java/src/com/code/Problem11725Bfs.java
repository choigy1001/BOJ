package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem11725Bfs {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        ArrayList<Integer>[] list = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int firstNode = parseInt(st.nextToken());
            int secondNode = parseInt(st.nextToken());
            list[firstNode].add(secondNode);
            list[secondNode].add(firstNode);
        }
        boolean[] visit = new boolean[N + 1];
        int[] parent = new int[N + 1];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        visit[1] = true;
        while (!queue.isEmpty()) {
            Integer front = queue.poll();
            for (Integer num : list[front]) {
                if (!visit[num]) {
                    visit[num] = true;
                    parent[num] = front;
                    queue.add(num);
                }
            }
        }
        for (int i = 2; i <= N; i++) {
            System.out.println(parent[i]);
        }

    }
}
