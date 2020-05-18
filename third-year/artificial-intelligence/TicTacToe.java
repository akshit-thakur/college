import java.util.Scanner;

class TicTacToe {
    private static int[] board = new int[9]; // gameboard
    private static int turn = 1; // stores the turn number in the game
    // 2 is for empty slot,3 for X,5 for O
    private static Scanner read = new Scanner(System.in);

    static void display() { // displays the board
        for (int i = 0; i < 9; i++) {
            if (board[i] == 2) {
                System.out.print("   ");
            } else if (board[i] == 3) {
                System.out.print(" X ");
            } else {
                System.out.print(" O ");
            }
            if (i % 3 == 2 && i != 8) {
                System.out.println();
                System.out.println("------------");
            } else if (i != 8) {
                System.out.print("|");
            } else {
                System.out.println();
            }
        }
    }

    private static void go(int slot) { // input to board
        if (turn % 2 == 1) // if player 1
            board[slot - 1] = 3;
        else // if player 2
            board[slot - 1] = 5;
    }

    private static void playerInput() {
        char symbol; // for printing purpose
        if (turn % 2 == 1)
            symbol = 'X';
        else
            symbol = 'O';
        System.out.println("Enter where you want to enter the " + symbol);
        int choice = read.nextInt();
        while (choice < 1 || choice > 9 || board[choice - 1] != 2) { // if move invalid
            System.out.println("Invalid move! Enter any number from 1 to 9");
            choice = read.nextInt();
        }
        go(choice);
    }

    private static void computerInput() {
        System.out.println("Computer plays!");
        switch (turn) {
        case 1:
            go(1);
            break;
        case 2:
            if (board[4] == 2) // if center empty
                go(5);
            else
                go(1);
            break;
        case 3:
            if (board[8] == 2)
                go(9);
            else
                go(3);
            break;
        case 4:
            if (board[4] == 3 && board[8] == 3) // special case as counter for 5,9,3,6/7
                go(3);
            else if (board[0] == 3 && board[7] == 3)
                go(7);
            else if (board[2] == 3 && board[7] == 3)
                go(9);
            else if (possWin('X') != 0) // if X can win,block move
                go(possWin('X'));
            else if (make2() != -1)// go to non-corner square
                go(make2());
            else { // go to some corner,empty square
                for (int i = 8; i >= 0; i--) {
                    if (board[i] == 2) {
                        go(i + 1);
                        break;
                    }
                }
            }
            break;
        case 5:
            if (possWin('X') != 0) // check own win
                go(possWin('X'));
            else if (possWin('O') != 0)
                go(possWin('O')); // block opponeent's win
            else if (board[6] == 2)
                go(7);
            else
                go(3);
            break;
        case 6:
            if (possWin('O') != 0) // check own win
                go(possWin('O'));
            else if (possWin('X') != 0) // block opponeent's win
                go(possWin('X'));
            else if (make2() != -1)// go to non-corner square
                go(make2());
            else { // go to some corner,empty square
                for (int i = 8; i >= 0; i--) {
                    if (board[i] == 2) {
                        go(i + 1);
                        break;
                    }
                }
            }
            break;
        case 7: // 7th and 9th turn are similar
        case 9:
            if (possWin('X') != 0)
                go(possWin('X'));
            else if (possWin('O') != 0)
                go(possWin('O')); // block opponeent's win
            else {
                for (int i = 0; i < 9; i++) {
                    if (board[i] == 2) {
                        go(i + 1);
                        break;
                    }
                }
            }
            break;
        case 8:
            if (possWin('O') != 0)
                go(possWin('O'));
            else if (possWin('X') != 0)
                go(possWin('X'));
            else {

                for (int i = 8; i >= 0; i--) {
                    if (board[i] == 2) {
                        go(i + 1);
                        break;
                    }
                }
            }
            break;
        default:
            ;
        }
    }

    private static int possWin(char x) {

        // returns 0 if player p can't win on next move
        // otherwise returns the number of square that constitutes the winning move
        int check;
        // check for possible wins by examining the corner
        if (x == 'X')
            check = 3;
        else
            check = 5;
        // improvement to pre-empt moves like 2,4,1,3/7
        if (board[1] == board[3] && board[1] == check && board[0] == 2) {
            return 1;
        } else if (board[1] == board[5] && board[1] == check && board[2] == 2) {
            return 3;
        } else if (board[5] == board[7] && board[7] == check && board[8] == 2) {
            return 9;
        } else if (board[3] == board[7] && board[7] == check && board[6] == 2) {
            return 7;
        }
        int target = 50; // 5*5*2
        if (x == 'X')
            target = 18; // 3*3*2
        int mark;
        int product;
        // check the rows
        for (int i = 0; i < 9; i += 3) {
            mark = 0;
            product = 1;
            for (int j = i; j < i + 3; j++) {
                product *= board[j];
                if (board[j] == 2)
                    mark = j;
            }
            if (product == target)
                return mark + 1;
        }
        // check the columns
        for (int i = 0; i < 3; i++) {
            mark = 0;
            product = 1;
            for (int j = i; j < 9; j += 3) {
                product *= board[j];
                if (board[j] == 2)
                    mark = j;
            }
            if (product == target)
                return mark + 1;
        }
        mark = 0;
        product = 1;
        int product1 = 1, mark1 = 0;
        // check the diagonals
        for (int i = 0, j = 2; i < 9 && j < 9; i += 4, j += 2) {
            product *= board[i];
            product1 *= board[j];
            if (board[i] == 2)
                mark = i;
            if (board[j] == 2)
                mark1 = j;
        }
        if (product == target)
            return mark + 1;
        else if (product1 == target)
            return mark1 + 1;
        return 0;
        
    }

    private static int make2() {

        if (board[4] == 2)
            return 5;
        else if (board[1] == 2)
            return 2;
        else if (board[3] == 2)
            return 4;
        else if (board[5] == 2)
            return 6;
        else if (board[7] == 2)
            return 8;
        else
            return -1;
    }

    private static boolean isWon() {
        int target = 125;
        if (turn % 2 == 1)
            target = 27;
        int product;
        // check the rows
        for (int i = 0; i < 9; i += 3) {
            product = 1;
            for (int j = i; j < i + 3; j++)
                product *= board[j];
            if (product == target)
                return true;
        }
        // check the columns
        for (int i = 0; i < 3; i++) {
            product = 1;
            for (int j = i; j < 9; j += 3)
                product *= board[j];
            if (product == target)
                return true;
        }
        product = 1;
        int product1 = 1;
        // check the diagonals
        for (int i = 0, j = 2; i < 9 && j < 9; i += 4, j += 2) {
            product *= board[i];
            product1 *= board[j];
        }
        if (product == target)
            return true;
        else if (product1 == target)
            return true;
        return false;
    }

    public static void main(String args[]) {
        char choice; // choice of whether player 1 'y' or player 2 'n'
        for (int i = 0; i < 9; i++) // initialize an empty board
            board[i] = 2;

        do {
            System.out.println("Do you want to play first? (y/n)");
            choice = read.nextLine().charAt(0);
        } while ((choice != 'y') && (choice != 'n')); // take input of choice until valid
        display();
        if (choice == 'y') {// computer is player 2
            while (turn <= 9) {
                if (turn % 2 == 1) // odd numbered turns are for player
                    playerInput();
                else
                    computerInput(); // even numbered turns
                display();
                if (turn > 3) { // winning can only take place 4th turn onwards
                    if (isWon()) {
                        if (turn % 2 == 1)
                            System.out.println("You Won!");
                        else
                            System.out.println("Computer Won!");
                        break;
                    }
                }
                turn += 1;
            }
        } else { // computer is player 1
            while (turn <= 9) {
                if (turn % 2 == 1)
                    computerInput();
                else
                    playerInput();
                display();
                if (turn > 3) {
                    if (isWon()) {
                        if (turn % 2 == 1)
                            System.out.println("Computer Won!");
                        else
                            System.out.println("Player Won!");
                        break;
                    }
                }
                turn += 1;
            }
        }
        if (turn == 10) // if all turns are played,turn stores 10
            System.out.println("Game drawn");
        read.close();
    }
}