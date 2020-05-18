import java.util.Scanner;

public class CheckSum {
    static String addBinary(String a, String b) {
        String result = "";
        int s = 0, i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || s == 1) {
            s += ((i >= 0) ? a.charAt(i) - '0' : 0);
            s += ((j >= 0) ? b.charAt(j) - '0' : 0);
            result += (char) (s % 2 + '0');
            s /= 2;
            i--;
            j--;
        }
        return result;
    }

    static String complementOf(String binary) {
        String answer = "";
        for (int i = 0; i < binary.length(); i++)
            answer += (binary.charAt(i) == '1' ? '0' : '1');
        return answer;
    }

    static int wrapSum(int sum) {
        String binary = Integer.toBinaryString(sum);
        if (binary.length() > 4) { // wrapping sum
            String lastFourBits = binary.substring(binary.length() - 4);
            String overflow = binary.substring(0, binary.length() - 4);
            String binarySum = addBinary(lastFourBits, overflow);
            String checkSum = complementOf(binarySum);
            return Integer.parseInt(checkSum, 2);
        }
        String checkSum = complementOf(binary);
        return Integer.parseInt(checkSum, 2);
    }

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the length of message:");
        int length = read.nextInt();
        int[] message = new int[length + 1]; // 1 for storing checksum in transmitted message
        System.out.println("Enter " + length + " numbers: ");
        for (int i = 0; i < length; i++)
            message[i] = read.nextInt();
        int sum = 0;
        for (int i = 0; i < length + 1; i++)
            sum += message[i];
        int checkSum = wrapSum(sum);
        message[length] = checkSum; // adding checksum to last.
        System.out.println("Transmitted message is: ");
        for (int i = 0; i < length + 1; i++)
            System.out.print(message[i] + " ");
        System.out.println("\nOn receiving side: ");
        sum = 0;
        for (int i = 0; i < length + 1; i++)
            sum += message[i];
        checkSum = wrapSum(sum);
        if (checkSum == 0)
            System.out.println("No error in transmission");
        else
            System.out.println("Error: Instead of zero, " + checkSum + " is generated on checking");
        read.close();
    }
}