package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem2075 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());

        Queue<Integer> queue = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int num = parseInt(st.nextToken());
                queue.add(num);
                if (queue.size() > N) {
                    queue.poll();
                }
            }
        }
        System.out.println(queue.peek());

    }
}
