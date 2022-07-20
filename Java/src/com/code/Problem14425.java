package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem14425 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = parseInt(st.nextToken());
        int M = parseInt(st.nextToken());

        HashMap<String, Boolean> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            map.put(br.readLine(), true);
        }
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            if (map.get(br.readLine()) == null) {
                continue;
            }else{
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
