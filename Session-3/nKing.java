import java.util.*;
import java.util.Scanner;

public class Solution {
    boolean arr[][];
    Set<Integer> grid = new HashSet<Integer>();

    Solution(int n) {
        arr = new boolean[n][n];
    }

    boolean IsItSafe(int row, int col) {
        if (grid.contains(col)) {
            return true;
        }
        if ((col > 0 && row > 0 && arr[row - 1][col - 1]) || (col < arr.length - 1 && row > 0 && arr[row - 1][col + 1])) {
            return true;
        }
    return false;
    }

    void arrange(boolean[][] arr) {
        this.arr = arr;
        for (int i=0;i<arr.length;i++) {
            for (int j=0;j<arr.length;j++) {
                if (arr[i][j]) {
                    grid.add(j);
                }
            }
        }
    }

    int possibleWay(int k) {
        if (k == arr.length - 1) {
            return 1;
        }
        int result = 0;
        for (int pos = 0; pos < arr.length; ++pos) {
            int ways = 1;
            if (!IsItSafe(k + 1, pos)) {
                arr[k + 1][pos] = true;
                grid.add(pos);
                ways *= possibleWay(k + 1);
                arr[k + 1][pos] = false;
                grid.remove(pos);
            }
            else {
                ways = 0;
            }

            result += ways;
        }
    return result;
    }
}

class mainClass {
    public static void main(String[] args) {
        Scanner inputS = new Scanner(System.in);
        //int input = inputS.nextInt();
        int input = Scanner.nextInt();
        Solution s1 = new Solution(input);
        System.out.println(s1.possibleWay(-1));
    }
}
