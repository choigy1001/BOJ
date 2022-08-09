package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem1068 {
    static ArrayList<Integer>[] list;
    static int cnt = 0;
    static boolean[] visit;
    static int rootNode;
    static void search(int start) {
        visit[start] = true;
        boolean leafNode = true;
//        if (list[start].size()==0) {
//            cnt++;
//            return;
//        }
        for (Integer num : list[start]) {
            if (!visit[num]) {
                search(num);
                leafNode = false;
            }
        }
        if (leafNode) {
            cnt++;
        }
    }

    static void clearChild(int start) {
        visit[start] = true;
        for (Integer num : list[start]) {
            if (!visit[num]) {
                clearChild(num);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        list = new ArrayList[N];
        visit = new boolean[N];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i <N ; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {

            int num = parseInt(st.nextToken());
            if (num == -1) {
                rootNode = i;
                continue;
            }
            list[num].add(i);
        }
        int deleteNode = parseInt(br.readLine());

        if (deleteNode == rootNode) {
            System.out.println(0);
            return;
        }

        visit[deleteNode] = true;

        for (Integer num : list[deleteNode]) {
            clearChild(num);
        }
        search(rootNode);

        System.out.println(cnt);

    }
}
