import java.util.Scanner;

public class hello {

    public static void main(String args[]){
        Scanner input = new Scanner(System.in);

        int a=input.nextInt();
        int b=input.nextInt();

        if (a>b) {
            System.out.println("a is greater");
        }else if (a<b) {
            System.out.println("a is lesser");
            
        }else{
            System.out.println("a is equal");
        }
    }
}