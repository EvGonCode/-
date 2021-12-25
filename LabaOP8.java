import java.security.spec.RSAOtherPrimeInfo;
import java.util.ArrayList;
import java.util.Scanner;

public class LabaOP8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введіть розмір сторони матриці: ");
        int size = in.nextInt();
        System.out.println();
        int[][] matrix = generateIntMatrix(size, size);
        System.out.println("Згенерована матриця");
        printIntMatrix(matrix);
        ArrayList<Integer> highlightedElementsList = getHighlightedElements(matrix);
        System.out.println("Виділені елементи матриці");
        System.out.println(highlightedElementsList);
        System.out.print("Найбільший виділений елемент: ");
        System.out.println(getMaxFromList(highlightedElementsList));
        System.out.print("Сума виділених елементів: ");
        System.out.println(getSumOfList(highlightedElementsList));
    }

    public static ArrayList<Integer> getHighlightedElements(int[][] matrix) {
        int size = matrix.length;
        ArrayList<Integer> list = new ArrayList<>();
        if (size % 2 == 0) {
            int target = 0;
            for (int i = 2; i <= size; i += 2) {
                for (int j = (size - i) / 2; j < (size - i) / 2 + i; j++) {
                    list.add(matrix[target][j]);
                }
                target++;
            }
            for (int i = size; i >= 2; i -= 2) {
                for (int j = (size - i) / 2; j < (size - i) / 2 + i; j++) {
                    list.add(matrix[target][j]);
                }
                target++;
            }
        } else {
            int target = 0;
            for (int i = 1; i <= size; i += 2) {
                for (int j = (size - i) / 2; j < (size - i) / 2 + i; j++) {
                    list.add(matrix[target][j]);
                }
                target++;
            }
            for (int i = size - 2; i >= 1; i -= 2) {
                for (int j = (size - i) / 2; j < (size - i) / 2 + i; j++) {
                    list.add(matrix[target][j]);
                }
                target++;
            }
        }

        return list;
    }

    public static int getMaxFromList(ArrayList<Integer> list) {
        int max = list.get(0);
        for (int i = 0; i < list.size(); i++) {
            if (max < list.get(i)) {
                max = list.get(i);
            }
        }
        return max;
    }

    public static int getSumOfList(ArrayList<Integer> list) {
        int sum = 0;
        for (int i = 0; i < list.size(); i++) {
            sum += list.get(i);
        }
        return sum;
    }

    public static void printIntMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            System.out.print("| ");
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] < 10) {
                    System.out.print(matrix[i][j] + "  ");
                } else {
                    System.out.print(matrix[i][j] + " ");
                }
            }
            System.out.println("|");
        }
    }

    public static int[][] generateIntMatrix(int height, int weight) {
        int[][] matrix = new int[height][weight];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < weight; j++) {
                matrix[i][j] = (int) (Math.random() * (99)) + 1;
            }
        }
        return matrix;
    }
}
