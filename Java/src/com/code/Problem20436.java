package com.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

class Location {
    int row;
    int col;

    public Location(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

public class Problem20436 {
    static HashMap<String, Location> leftKeyBoard;
    static HashMap<String, Location> rightKeyBoard;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        String left = st.nextToken();
        String right = st.nextToken();

        String word = br.readLine();
        leftKeyBoard = new HashMap<>();
        rightKeyBoard = new HashMap<>();
        insertData();

        int minTime = 0;
        Location leftHand = leftKeyBoard.get(left);
        Location rightHand = rightKeyBoard.get(right);

        for (int i = 0; i < word.length(); i++) {
            String now = String.valueOf(word.charAt(i));
            if (leftKeyBoard.containsKey(now)) {
                Location typingLocation = leftKeyBoard.get(now);
                int leftDistance = Math.abs(leftHand.row - typingLocation.row) + Math.abs(leftHand.col - typingLocation.col);
                minTime += leftDistance;
                minTime++;
                leftHand = typingLocation;
            } else {
                Location typingLocation = rightKeyBoard.get(now);
                int rightDistance = Math.abs(rightHand.row - typingLocation.row) + Math.abs(rightHand.col - typingLocation.col);
                minTime += rightDistance;
                minTime++;
                rightHand = typingLocation;
            }
        }
        System.out.println(minTime);
    }

    private static void insertData() {
        leftKeyBoard.put("q", new Location(0, 0));
        leftKeyBoard.put("w", new Location(0, 1));
        leftKeyBoard.put("e", new Location(0, 2));
        leftKeyBoard.put("r", new Location(0, 3));
        leftKeyBoard.put("t", new Location(0, 4));
        rightKeyBoard.put("y", new Location(0, 5));
        rightKeyBoard.put("u", new Location(0, 6));
        rightKeyBoard.put("i", new Location(0, 7));
        rightKeyBoard.put("o", new Location(0, 8));
        rightKeyBoard.put("p", new Location(0, 9));

        leftKeyBoard.put("a", new Location(1, 0));
        leftKeyBoard.put("s", new Location(1, 1));
        leftKeyBoard.put("d", new Location(1, 2));
        leftKeyBoard.put("f", new Location(1, 3));
        leftKeyBoard.put("g", new Location(1, 4));
        rightKeyBoard.put("h", new Location(1, 5));
        rightKeyBoard.put("j", new Location(1, 6));
        rightKeyBoard.put("k", new Location(1, 7));
        rightKeyBoard.put("l", new Location(1, 8));

        leftKeyBoard.put("z", new Location(2, 0));
        leftKeyBoard.put("x", new Location(2, 1));
        leftKeyBoard.put("c", new Location(2, 2));
        leftKeyBoard.put("v", new Location(2, 3));
        rightKeyBoard.put("b", new Location(2, 4));
        rightKeyBoard.put("n", new Location(2, 5));
        rightKeyBoard.put("m", new Location(2, 6));

    }
}
