package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

import static java.lang.Integer.*;

class position {
    int x;
    int y;

    public position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
public class Problem2667Bfs {
    static int[][] map;
    static boolean[][] visit;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int N;
    static int count;
    static Queue<position> queue = new LinkedList<>();

    static void bfs() {
        while (!queue.isEmpty()) {
            position poll = queue.poll();
            for (int i = 0; i < 4; i++) {
                int mx = poll.x + dx[i];
                int my = poll.y + dy[i];
                if (mx >= 0 && my >= 0 && mx < N && my < N) {
                    if (map[mx][my] == 1 && !visit[mx][my]) {
                        queue.add(new position(mx, my));
                        visit[mx][my] = true;
                        count++;
                    }
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = parseInt(br.readLine());
        visit = new boolean[N + 1][N + 1];
        map = new int[N + 1][N + 1];
        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visit[i][j] && map[i][j] == 1) {
                    queue.add(new position(i, j));
                    visit[i][j] = true;
                    count = 1;
                    bfs();
                    list.add(count);
                }
            }
        }
        System.out.println(list.size());
        Collections.sort(list);
        for (Integer num : list) {
            System.out.println(num);
        }
    }
}
