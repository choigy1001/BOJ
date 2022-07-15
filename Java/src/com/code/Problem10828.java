package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Problem10828 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Stack<Integer> stack = new Stack<>();
        StringTokenizer stringTokenizer = null;

        Integer n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            stringTokenizer = new StringTokenizer(br.readLine(), " ");
            String command = stringTokenizer.nextToken();
            switch (command) {
                case "push":
                    stack.push(Integer.parseInt(stringTokenizer.nextToken()));
                    break;
                case "pop":
                    if (stack.size() == 0) {
                        System.out.println("-1");
                        continue;
                    }
                    System.out.println(stack.pop());
                    break;
                case "size":
                    System.out.println(stack.size());
                    break;
                case "empty":
                    if (stack.size() == 0) {
                        System.out.println("1");
                    } else {
                        System.out.println("0");
                    }
                    break;
                case "top":
                    int size = stack.size();
                    if (size == 0) {
                        System.out.println("-1");
                    } else {
                        System.out.println(stack.peek());
                    }
                    break;
            }
        }
    }
}
