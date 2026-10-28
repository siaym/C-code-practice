import java.util.*;

class person{
   private String name;
    private int age;

    public void setinfo(String name,int age){
        this.name=name;
        this.age=age;
    }
    public void getinfo(){
        System.out.println("the name=" +name+" and age=" +age);
        // System.out.println("and age=" +age);
    }
}
public class scanner  {
    public static void main(String[] args) {

        Scanner input =new Scanner(System.in);
        System.out.println("enter the name=");
        String name=input.next();
        System.out.println("enter the age=");
        int age=input.nextInt();

        person person=new person();
        person.setinfo(name,age);
        person.getinfo();
    }
    
}
