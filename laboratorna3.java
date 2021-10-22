import java.util.Scanner;

public class laboratorna3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введіть к-ть знаків після крапки");
        int n = in.nextInt();
        System.out.println("Введіть x");
        int x = in.nextInt();
        if(n > 16){
            System.out.println("Double має обмеження в 16 знаків після крапки, скорегуйте данні з урахуванням цього.");
        }
        else if(n == 0){
            System.out.print("Результат: ");
            System.out.println(1);
        }else {
            System.out.print("Результат: ");
            System.out.println(cosinusx(n, x));
        }
    }
    public static String cosinusx(int n, int x){
        if(x == 0){
            String s = "1.";
            for(int i = 0; i < n; i++){
                s += "0";
            }
            return s;
        }
        double cos = (double) 1;
        double i = 1.0;
        while(!(Double.toString(cos).length() - 2 >= n)){
            cos += (Math.pow(-1, i))*((Math.pow(x, 2*i))/calculateFactorial((i*2)));
            i++;
        }
        double scale = Math.pow(10, n);
        double result = Math.ceil(cos * scale) / scale;
        return (Double.toString(result));
    }
    static double calculateFactorial(double n){
        double result = 1;
        for (int i = 1; i <=n; i ++){
            result = result*i;
        }
        return result;
    }
}
