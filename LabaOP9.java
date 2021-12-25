import java.util.ArrayList;
import java.util.Scanner;

public class LabaOP9 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        System.out.println(s);
        String[] arrayS = s.split(" ");
        ArrayList<String> resultList = getSpecificWords(arrayS);
        System.out.println(resultList);
    }

    public static ArrayList<String> getSpecificWords(String[] arrayS){
        ArrayList<String> listS = new ArrayList<>();
        for(int i = 0; i < arrayS.length; i++){
            String[] buffer = arrayS[i].split("");
            try {
                if (arrayS[i].charAt(0) != 0 && buffer[0].equals(buffer[buffer.length - 1])) {
                    listS.add(arrayS[i]);
                }
            }catch(StringIndexOutOfBoundsException e){
            }
        }
        return listS;
    }
}