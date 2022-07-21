package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Problem4358 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<String, Integer> map = new HashMap<>();
        int total = 0;
        while (true) {
            String name = br.readLine();
            if (name == null || name.length() == 0) {
                break;
            }
            map.put(name, map.getOrDefault(name, 0) + 1);
            total++;
        }
        Set<String> nameSet = map.keySet();

        List<String> list = new ArrayList<>(nameSet);
        Collections.sort(list);

        StringBuilder sb = new StringBuilder();
        for (String name : list) {
            Integer count = map.get(name);
            double percent = (double) (count * 100) / total;
            sb.append(name.concat(" ").concat(String.format("%.4f", percent)).concat("\n"));
        }
        System.out.println(sb);

    }
}
