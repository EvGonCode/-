import java.util.Scanner;


public class laba7 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Введіть кількість елементів массиву: ");
        int[] array = new int[in.nextInt()];
        array = artificialGenerate(array);

        System.out.println("Згенерований массив:");
        printMass(array);
        System.out.println("Оброблений масив:");
        printMass(chngeBigAndSmall(array));
    }

    public static void printMass(int[] array){
        System.out.print("[");
        for(int i = 0; i < array.length; i++){
            if(i +1 != array.length) {
                System.out.print(array[i] + ", ");
            }else{
                System.out.print(array[i]);
            }
        }
        System.out.print("]\n");
    }

    public static int[] artificialGenerate(int[] array){
        Scanner in = new Scanner(System.in);
        for(int i = 0; i < array.length; i++){
            System.out.print("Введіть " + (i+1) +"-й елемент масиву: ");
            array[i] = in.nextInt();
        }
        return array;
    }

    public static int[] chngeBigAndSmall(int[] array){
        int smallIndex;
        int small;
        int bigIndex;
        int big;
        for(int i = 0; i < array.length; i++){
            if(array[i] >= 0){
                small = array[i];
                smallIndex = i;
                big = small;
                bigIndex = smallIndex;
                for(int j = 0; j < array.length; j++){
                    if(array[j] >= 0) {
                        if (small > array[j]){     small = array[j]; smallIndex = j; }
                        else if (big < array[j]){  big = array[j];   bigIndex = j;   }
                    }
                }
                array[smallIndex] += array[bigIndex];
                array[bigIndex] = array[smallIndex] - array[bigIndex];
                array[smallIndex] = array[smallIndex] - array[bigIndex];
                return array;
            }
        }
        return array;
    }
}