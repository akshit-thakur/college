
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AlphaBeta {

    static List<Integer> path;
    static int iterations;

    private static char[][] copyBoard(char[][] board) {
        char[][] position = new char[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                position[i][j] = board[i][j];
        }
        return position;
    }

    private static int minmaxAB(char[][] board, int depth, int player, int useTresh, int passThresh) {
        iterations += 1;
        char[][] position = copyBoard(board);
        if (deepEnough(depth)) {
            return evaluation(position, player);
        } else {
            List<Integer> successors = movegen(position);
            if (successors.isEmpty()) {
                return evaluation(position, player);
            } else {
                int bestScore = Integer.MIN_VALUE;

                for (Integer succ : successors) {
                    char[][] tempBoard = copyBoard(position);
                    tempBoard = makeMove(tempBoard, succ, player);
                    int result = minmaxAB(tempBoard, depth + 1, (player + 1) % 2,-passThresh,-useTresh);
                    int newval = -result;
                    if (newval > passThresh) {
                        passThresh = newval;
                        path.add(succ);
                    }
                    if(passThresh>=useTresh){
                        bestScore = passThresh;
                        break;
                    }
                }
                return bestScore;
            }
        }
    }

    private static List<Integer> movegen(char[][] position) {
        List<Integer> moves = new ArrayList<>();
        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                count += 1;
                if (position[i][j] == ' ')
                    moves.add(count);
            }
        }
        return moves;
    }

    private static int evaluation(char[][] board, int player) {
        int result = 0;
        char play = (player % 2 == 0) ? 'x' : 'o';
        char opp = (player % 2 == 1) ? 'o' : 'x';
        if (board[1][1] == play)
            result += 5;
        else if (board[1][1] == opp)
            result -= 5;

        if (board[0][1] == play)
            result += 2;
        else if (board[0][1] == opp)
            result -= 2;

        if (board[1][0] == play)
            result += 2;
        else if (board[1][0] == opp)
            result -= 2;

        if (board[1][2] == play)
            result += 2;
        else if (board[1][2] == opp)
            result -= 2;

        if (board[2][1] == play)
            result += 2;
        else if (board[2][1] == opp)
            result -= 2;

        if (board[0][0] == play)
            result += 1;
        else if (board[0][0] == opp)
            result -= 1;

        if (board[0][2] == play)
            result += 1;
        else if (board[0][2] == opp)
            result -= 1;

        if (board[2][0] == play)
            result += 1;
        else if (board[2][0] == opp)
            result -= 1;

        if (board[2][2] == play)
            result += 1;
        else if (board[2][2] == opp)
            result -= 1;

        for (int row = 0; row < 3; row++) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == play){
                    result = Integer.MAX_VALUE;
                    return result;
                }
                else if (board[row][0] == opp){
                    result = Integer.MIN_VALUE;
                    return result;
                }
            }
        }
        for (int col = 0; col < 3; col++) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == play){
                    result = Integer.MAX_VALUE;
                    return result;
                }
                else if (board[0][col] == opp){
                    result = Integer.MIN_VALUE;
                    return result;
                }
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == play){
                result = Integer.MAX_VALUE;
                return result;
            }
            else if (board[0][0] == opp){
                result = Integer.MIN_VALUE;
                return result;
            }
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            if (board[2][0] == play){
                result = Integer.MAX_VALUE;
                return result;
            }
            else if (board[2][0] == opp){
                result = Integer.MIN_VALUE;
                return result;
            }
        }

        for (int i = 0; i < 3; i++) {
            int countP = 0, countO = 0;
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == play)
                    countP += 1;
                else if (board[i][j] == opp)
                    countO += 1;
            }
            if (countP == 2 && countO == 0)
                result+=25;
            else if (countO == 2 && countP == 0)
                result-=25;
        }

        for (int i = 0; i < 3; i++) {
            int countP = 0, countO = 0;
            for (int j = 0; j < 3; j++) {
                if (board[j][i] == play)
                    countP += 1;
                else if (board[j][i] == opp)
                    countO += 1;
            }
            if (countP == 2 && countO == 0)
                result+=25;
            else if (countO == 2 && countP == 0)
                result-=25;
        }
        int countP = 0, countO = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == play)
                countP += 1;
            else if (board[i][i] == opp)
                countO += 1;
        }
        if (countP == 2 && countO == 0)
            result+=25;
        else if (countO == 2 && countP == 0)
            result-=25;
        countP = 0;
        countO = 0;

        for (int i = 0; i < 3; i++) {
            if (board[2 - i][i] == play)
                countP += 1;
            else if (board[2 - i][i] == opp)
                countO += 1;
        }
        if (countP == 2 && countO == 0)
            result+=25;
        else if (countO == 2 && countP == 0)
            result-=25;
        return result;
        /*
         * for (int row = 0; row < 3; row++) { if (board[row][0] == board[row][1] &&
         * board[row][1] == board[row][2]) { if (board[row][0] == play) return 100; else
         * if (board[row][0] == opp) return -100; } } for (int col = 0; col < 3; col++)
         * { if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) { if
         * (board[0][col] == play) return 100; else if (board[0][col] == opp) return
         * -100; } } if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) { if
         * (board[0][0] == play) return 100; else if (board[0][0] == opp) return -100; }
         * if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) { if
         * (board[2][0] == play) return 100; else if (board[2][0] == opp) return -100; }
         * 
         * for (int i = 0; i < 3; i++) { int countP = 0, countO = 0; for (int j = 0; j <
         * 3; j++) { if (board[i][j] == play) countP += 1; else if (board[i][j] == opp)
         * countO += 1; } if (countP == 2 && countO == 0) return 10; else if (countO ==
         * 2 && countP == 0) return -10; }
         * 
         * for (int i = 0; i < 3; i++) { int countP = 0, countO = 0; for (int j = 0; j <
         * 3; j++) { if (board[j][i] == play) countP += 1; else if (board[j][i] == opp)
         * countO += 1; } if (countP == 2 && countO == 0) return 10; else if (countO ==
         * 2 && countP == 0) return -10; } int countP = 0, countO = 0; for (int i = 0; i
         * < 3; i++) { if (board[i][i] == play) countP += 1; else if (board[i][i] ==
         * opp) countO += 1; } if (countP == 2 && countO == 0) return 10; else if
         * (countO == 2 && countP == 0) return -10; countP = 0; countO = 0;
         * 
         * for (int i = 0; i < 3; i++) { if (board[2 - i][i] == play) countP += 1; else
         * if (board[2 - i][i] == opp) countO += 1; } if (countP == 2 && countO == 0)
         * return 10; else if (countO == 2 && countP == 0) return -10; return 0;
         */
    }

    private static boolean deepEnough(int depth) {
        return depth == 9;
    }

    public static void main(String[] args) {
        char[][] board = new char[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
        }
        Scanner read = new Scanner(System.in);
        System.out.println("Player 1?");
        char choice = read.nextLine().toLowerCase().charAt(0);
        int player = 0;
        int depth = 0;
        int index = 0;
        if (choice == 'y') {
            while (true) {
                showBoard(board);
                System.out.println("Enter your move: (1-9)");
                do {
                    index = read.nextInt();
                } while (index < 1 || index > 9 || isInvalid(board, index));
                path = new ArrayList<>();
                board = makeMove(board, index, player % 2); // 0 = player1
                depth += 1;
                if (isWon(board, player)) {
                    showBoard(board);
                    System.out.println("You won");
                    break;
                }
                player += 1;
                if (movegen(board).isEmpty()) {
                    showBoard(board);
                    System.out.println("Game drawn");
                    break;
                }
                showBoard(board);

                minmaxAB(board, depth, player % 2,Integer.MAX_VALUE,Integer.MIN_VALUE);

                board = makeMove(board, path.get(0), player % 2); // first ply moved
                depth += 1;
                if (isWon(board, player)) {
                    showBoard(board);
                    System.out.println("Computer won");
                    break;
                }
                player += 1;
            }
        } else {
            while (true) {
                path = new ArrayList<>();
                minmaxAB(board, depth, player % 2,Integer.MAX_VALUE,Integer.MIN_VALUE);
                board = makeMove(board, path.get(path.size() - 1), player % 2); // first ply moved
                depth += 1;
                if (isWon(board, player)) {
                    showBoard(board);
                    System.out.println("Computer won");
                    break;
                }
                showBoard(board);
                player += 1;
                if (player == 9) {
                    if (movegen(board).isEmpty()) {
                        showBoard(board);
                        System.out.println("Game drawn");
                        break;
                    }
                }
                System.out.println("Enter your move: (1-9)");
                do {
                    index = read.nextInt();
                } while (index < 1 || index > 9 || isInvalid(board, index));
                board = makeMove(board, index, player % 2); // 0 = player1
                depth += 1;
                if (isWon(board, player)) {
                    showBoard(board);
                    System.out.println("You won");
                    break;
                }
                player += 1;
                showBoard(board);
            }
        }
        System.out.println(iterations);
        read.close();
    }

    private static boolean isInvalid(char[][] board, int index) {
        switch (index) {
        case 1:
            return (board[0][0] != ' ');
        case 2:
            return (board[0][1] != ' ');
        case 3:
            return (board[0][2] != ' ');
        case 4:
            return (board[1][0] != ' ');
        case 5:
            return (board[1][1] != ' ');
        case 6:
            return (board[1][2] != ' ');
        case 7:
            return (board[2][0] != ' ');
        case 8:
            return (board[2][1] != ' ');
        case 9:
            return (board[2][2] != ' ');
        default:
            return false;
        }
    }

    private static void showBoard(char[][] board) {
        for (int i = 0; i < 3; i++) {
            if (i != 2) {
                System.out.println("\t\t\t" + board[i][0] + " | " + board[i][1] + " | " + board[i][2]);
                System.out.println("\t\t\t----------");
            } else
                System.out.println("\t\t\t" + board[i][0] + " | " + board[i][1] + " | " + board[i][2]);
        }
    }

    private static boolean isWon(char[][] board, int player) {
        return evaluation(board, player) == Integer.MAX_VALUE;
    }

    private static char[][] makeMove(char[][] board, int index, int player) {
        char ch = (player % 2 == 0) ? 'x' : 'o';
        switch (index) {
        case 1:
            board[0][0] = ch;
            break;
        case 2:
            board[0][1] = ch;
            break;
        case 3:
            board[0][2] = ch;
            break;
        case 4:
            board[1][0] = ch;
            break;
        case 5:
            board[1][1] = ch;
            break;
        case 6:
            board[1][2] = ch;
            break;
        case 7:
            board[2][0] = ch;
            break;
        case 8:
            board[2][1] = ch;
            break;
        case 9:
            board[2][2] = ch;
            break;
        default:
            ;
        }
        return board;
    }
}
