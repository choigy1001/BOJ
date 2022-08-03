package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1343 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int count = 0;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i)=='X') {
                count++;
            } else if (s.charAt(i) == '.') {
                if (count % 2 == 1) {
                    System.out.print(-1);
                    return;
                }
                while (count != 0) {
                    if (count >= 4) {
                        sb.append("AAAA");
                        count -= 4;
                    } else if (count >= 2) {
                        sb.append("BB");
                        count -= 2;
                    }
                }
                sb.append(".");
            }
        }
        if (count > 0) {
            if (count % 2 == 1) {
                System.out.print(-1);
                return;
            }
            while (count != 0) {
                if (count >= 4) {
                    sb.append("AAAA");
                    count -= 4;
                } else if (count >= 2) {
                    sb.append("BB");
                    count -= 2;
                }
            }
        }
        System.out.print(sb.toString());

    }
}
