package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem11725Dfs {
    static ArrayList<Integer>[] list;
    static int[] parent;
    static boolean[] visited;

    static void findParent(int node) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        for (int num : list[node]) {
            if (!visited[num]) {
                parent[num] = node;
                findParent(num);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        list = new ArrayList[N + 1];
        visited = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int firstNode = parseInt(st.nextToken());
            int secondNode = parseInt(st.nextToken());
            list[firstNode].add(secondNode);
            list[secondNode].add(firstNode);
        }
        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                findParent(i);
            }
        }
        for (int i = 2; i <= N; i++) {
            System.out.println(parent[i]);
        }
    }
}
