package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

import static java.lang.Integer.*;

public class Problem2217 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = parseInt(br.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int lope = parseInt(br.readLine());
            list.add(lope);
        }
        list.sort(Collections.reverseOrder());
        int maxWeight = 0;

        for (int i = 0; i < N; i++) {
            maxWeight = Math.max(list.get(i) * (i + 1), maxWeight);
        }
        System.out.println(maxWeight);

    }
}
