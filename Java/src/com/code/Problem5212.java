package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

public class Problem5212 {
    static int dx[] = {0, 0, -1, 1};
    static int dy[] = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int R = parseInt(st.nextToken());
        int C = parseInt(st.nextToken());
        char[][] map = new char[R][C];
        char[][] newMap = new char[R][C];
        for (int i = 0; i < R; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = tmp.charAt(j);
            }
        }
        int minRow = 10, minCol = 10, maxRow = 0, maxCol = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] == 'X') {
                    int row = i;
                    int col = j;
                    int seaCount = 0;
                    for (int k = 0; k < 4; k++) {
                        int dr = row + dx[k];
                        int dc = col + dy[k];
                        if (dr < 0 || dr >=R || dc < 0 || dc >= C) {
                            seaCount++;
                        } else if (map[dr][dc] == '.') {
                            seaCount++;
                        }
                    }
                    if (seaCount >= 3) {
                        newMap[i][j] = '.';
                    } else {
                        newMap[i][j] = 'X';
                        minRow = Math.min(minRow, i);
                        minCol = Math.min(minCol, j);
                        maxRow = Math.max(maxRow, i);
                        maxCol = Math.max(maxCol, j);

                    }
                } else {
                    newMap[i][j] = '.';
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = minRow; i <= maxRow; i++) {
            for (int j = minCol; j <= maxCol; j++) {
                sb.append(newMap[i][j]);
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
