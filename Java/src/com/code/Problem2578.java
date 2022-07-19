package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.*;

class Game {
    int value;
    int check;

    public Game(int value) {
        this.value = value;
        this.check = 0;
    }
}
public class Problem2578 {

    static Game[][] map = new Game[5][5];
    static int bingo = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int time = 0;
        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < 5; j++) {
                int value = parseInt(st.nextToken());
                map[i][j] = new Game(value);
            }
        }

        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < 5; j++) {
                bingo = 0;
                time++;
                int value = parseInt(st.nextToken());
                checkValue(value);

                rowCheck();
                columnCheck();
                diagonalCheck();

                if (bingo >= 3) {
                    System.out.println(time);
                    break;
                }
            }
            if (bingo >= 3) {
                break;
            }
        }
    }

    static void checkValue(int value) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <5; j++) {
                if (map[i][j].value == value) {
                    map[i][j].check = 1;
                }
            }
        }
    }

    static void rowCheck() {
        for (int i = 0; i < 5; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (map[i][j].check == 1) {
                    cnt++;
                }
                if (cnt == 5) {
                    bingo++;
                }
            }
        }
    }

    static void columnCheck() {
        for (int i = 0; i < 5; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (map[j][i].check == 1) {
                    cnt++;
                }
                if (cnt == 5) {
                    bingo++;
                }
            }
        }
    }

    static void diagonalCheck() {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (map[i][i].check == 1) {
                cnt++;
            }
        }
        if (cnt == 5) {
            bingo++;
        }
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (map[i][4 - i].check == 1) {
                cnt++;
            }
        }
        if (cnt == 5) {
            bingo++;
        }
    }
}
