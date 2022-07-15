package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Problem3986 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            Stack<Character> stack = new Stack<>();
            stack.push(str.charAt(0));
            for (int j = 1; j < str.length(); j++) {
                char currentCh = str.charAt(j);
                if (!stack.isEmpty()) {
                    Character prevCh = stack.peek();
                    if (prevCh == currentCh) {
                        stack.pop();
                        continue;
                    }
                }
                stack.push(currentCh);
            }
            if (stack.isEmpty()) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
