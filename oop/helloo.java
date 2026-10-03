import java.util.Scanner;

public class helloo {
    public static void main(String args []){
        Scanner in= new Scanner(System.in);
        int a= in.nextInt();

        if (a%2==0) {
            System.out.println("a is a even number");
            
        }else System.out.println("a is a odd ");
    }
}
