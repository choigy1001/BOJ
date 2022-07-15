package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Integer.*;

class Printer {
    int order;
    int value;

    public Printer(int order, int value) {
        this.order = order;
        this.value = value;
    }
}

public class Problem1966 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = null;

        int T = parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            Queue<Printer> queue = new LinkedList<>();

            stringTokenizer = new StringTokenizer(br.readLine(), " ");
            int N = parseInt(stringTokenizer.nextToken());
            int M = parseInt(stringTokenizer.nextToken());

            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                int num = parseInt(st.nextToken());
                queue.add(new Printer(j, num));
            }
            int cnt=1;
            while (!queue.isEmpty()) {
                Printer poll = queue.poll();
                Iterator<Printer> iterator = queue.iterator();
                boolean flag = true;
                while (iterator.hasNext()) {
                    if (poll.value < iterator.next().value) {
                        flag = false;
                        break;
                    }
                }
                if (flag == false) {
                    queue.add(poll);
                }
                else{
                    if (poll.order == M) {
                        System.out.println(cnt);
                    } else {
                        cnt++;
                    }
                }
            }
        }
    }
}
