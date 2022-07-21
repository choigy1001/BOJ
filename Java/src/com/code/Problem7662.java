package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Integer.*;

public class Problem7662 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = parseInt(br.readLine());
        while (T-- > 0) {
            PriorityQueue<Integer> minQueue = new PriorityQueue<>();
            PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Collections.reverseOrder());
            Map<Integer, Integer> map = new HashMap<>();
            int k = parseInt(br.readLine());
            for (int i = 0; i < k; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String command = st.nextToken();
                if (command.equals("I")) {
                    int num = parseInt(st.nextToken());
                    map.put(num, map.getOrDefault(num, 0) + 1);
                    minQueue.add(num);
                    maxQueue.add(num);

                } else if (command.equals("D")) {
                    int value = parseInt(st.nextToken());
                    if (map.size() == 0) {
                        continue;
                    }
                    if (value == 1) {
                        delete(maxQueue, map);
                    } else if (value == -1) {
                        delete(minQueue, map);
                    }
                }
            }
            if (map.size() == 0) {
                System.out.println("EMPTY");
            } else{
                int max = delete(maxQueue, map);
                int min;
                if (map.size() != 0) {
                    min = delete(minQueue, map);
                } else{
                    min = max;
                }
                System.out.println(max + " " + min);
            }
        }

    }

    static int delete(Queue<Integer> queue, Map<Integer, Integer> map) {
        Integer front;
        while (true) {
            front = queue.poll();
            Integer cnt = map.getOrDefault(front, 0);
            if (cnt == 0) {
                continue;
            }
            if (cnt == 1) {
                map.remove(front);
            } else if (cnt > 1) {
                map.put(front, cnt - 1);
            }
            break;
        }
        return front;
    }
}
