import java.util.Scanner;

public class Knights {
    static int count;

    private static void place(int[][] board, int i, int j) {
        board[i][j] = 1;
        attack(board, i, j);
    }

    private static void attack(int[][] board, int i, int j) {
        if (i - 2 >= 0) {
            if (j - 1 >= 0)
                board[i - 2][j - 1] = 2;
            if (j + 1 < board[0].length)
                board[i - 2][j + 1] = 2;
        }
        if (i + 2 < board.length) {
            if (j - 1 >= 0)
                board[i + 2][j - 1] = 2;
            if (j + 1 < board[0].length)
                board[i + 2][j + 1] = 2;
        }
        if (j - 2 >= 0) {
            if (i - 1 >= 0)
                board[i - 1][j - 2] = 2;
            if (i + 1 < board.length)
                board[i + 1][j - 2] = 2;
        }
        if (j + 2 < board[0].length) {
            if (i - 1 >= 0)
                board[i - 1][j + 2] = 2;
            if (i + 1 < board.length)
                board[i + 1][j + 2] = 2;
        }
    }

    private static void display(int[][] board) {
        System.out.println("Solution number " + count);
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 1)
                    System.out.print("K\t");
                else
                    System.out.print("\t");
            }
            System.out.println();
        }
    }

    private static boolean isEmpty(int[][] board, int i, int j) {
        return (board[i][j] == 0);
    }

    private static void kKnights(int[][] board, int k, int iStart, int jStart) {
        if (k == 0) {
            count += 1;
            display(board);
        } else {
            for (int i = iStart; i < board.length; i++) {
                for (int j = jStart; j < board[0].length; j++) {
                    if (isEmpty(board, i, j)) {
                        int[][] newBoard = new int[board.length][board[0].length];
                        for (int p = 0; p < board.length; p++)
                            System.arraycopy(board[p], 0, newBoard[p], 0, board[p].length);
                        place(newBoard, i, j);
                        kKnights(newBoard, k - 1, i, j);
                    }
                }
                jStart = 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the size of board: ");
        int m = read.nextInt();
        int n = read.nextInt();
        int[][] board = new int[m][n];
        System.out.println("Enter the number of knights: ");
        int k = read.nextInt();
        kKnights(board, k, 0, 0);
        System.out.println("Total solutions " + count);
        read.close();
    }
}