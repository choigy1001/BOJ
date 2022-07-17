package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Integer.*;

public class Problem1021 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int M = parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            queue.add(i+1);
        }
        int result = 0;
        for (int i = 0; i < M; i++) {
            int find = parseInt(st.nextToken());
            int cnt = 0;
            while (find != queue.peek()) {
                Integer front = queue.poll();
                queue.add(front);
                cnt++;
            }
            result += Math.min(queue.size() - cnt, cnt);
            queue.poll();
        }
        System.out.println(result);
    }
}
