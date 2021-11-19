import java.util.Scanner;

public class Laba6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введіть перше натуральне число");
        int a = in.nextInt();
        System.out.println("Введіть друге натуральне число");
        int b = in.nextInt();
        System.out.println("Введіть третє натуральне число");
        int c = in.nextInt();
        int summ = getFirst(a) + getFirst(b) + getFirst(c);
        System.out.println("Сума перших цифр трьох чисел: " + summ);
    }

    public static int getFirst(int x){
        if(x % 10 == x){
            return x;
        }
        else{
            x /= 10;
            x = getFirst(x);
        }
        return x;
    }
}
