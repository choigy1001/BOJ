package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem14467 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());

        HashMap<Integer, Integer> map = new HashMap<>();
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int num = parseInt(st.nextToken());
            int location = parseInt(st.nextToken());
            if (map.get(num) == null) {
                map.put(num, location);
            } else if(map.get(num) != location) {
                map.put(num, location);
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
