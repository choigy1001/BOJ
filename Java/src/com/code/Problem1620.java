package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem1620 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = parseInt(st.nextToken());
        int M = parseInt(st.nextToken());

        HashMap<Integer, String> keyIntegerMap = new HashMap<>();
        HashMap<String, Integer> keyStringMap = new HashMap<>();

        for (int i = 1; i <= N; i++) {
            String name = br.readLine();
            keyIntegerMap.put(i, name);
            keyStringMap.put(name, i);
        }
        for (int i = 0; i < M; i++) {
            String s = br.readLine();
            if (isNumber(s)) {
                int num = parseInt(s);
                System.out.println(keyIntegerMap.get(num));
            } else {
                System.out.println(keyStringMap.get(s));
            }
        }
    }
    static boolean isNumber(String s) {
        try {
            Double.parseDouble(s);
        } catch (NumberFormatException e) {
            return false;
        }
        return true;
    }
}
