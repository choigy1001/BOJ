package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

import static java.lang.Integer.*;

public class Problem1758 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            list.add(parseInt(br.readLine()));
        }
        list.sort(Collections.reverseOrder());

        long sum = 0;
        for (int i = 0; i < N; i++) {
            Integer tip = list.get(i);
            if (tip - i > 0) {
                sum += tip - i;
            }
        }
        System.out.println(sum);
    }
}
