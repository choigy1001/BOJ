package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem12933 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String duck = br.readLine();
        int[] makeQuack = new int[6];
        int result = 0;
        makeQuack[0] = duck.length();
        for (int i = 0; i < duck.length(); i++) {
            int index = 0;
            if (duck.charAt(i) == 'q') {
                index = 1;
            } else if (duck.charAt(i) == 'u') {
                index = 2;
            } else if (duck.charAt(i) == 'a') {
                index = 3;
            } else if (duck.charAt(i) == 'c') {
                index = 4;
            } else if (duck.charAt(i) == 'k') {
                index = 5;
            }
            if (makeQuack[index - 1] == 0) {
                System.out.println(-1);
                return;
            }
            makeQuack[index]++;
            makeQuack[index - 1]--;
            result = Math.max(result, makeQuack[1] + makeQuack[2] + makeQuack[3] + makeQuack[4]);
        }
        if (makeQuack[5] * 5 != duck.length()) {
            System.out.println(-1);
            return;
        }
        System.out.println(result);
    }
}
