
class teacher {
    String name,gender;
    int age;
    teacher(String n,String g){
        name=n;
        gender=g;
    }
     teacher(String n,String g,int  a){
        name=n;
        gender=g;
        age=a;
    }
    teacher(){
        System.out.println("no value");

    }
     void display () {
        System.out.println("name="+name);
        System.out.println("gender="+gender);
        System.out.println("age="+age);
    }
}
public class Innerteacher {
    public static void main(String args[]){
        teacher teacher=new teacher();
        teacher teacher1= new teacher("anis","male");
        teacher1.display();
        teacher teacher2=new teacher("anis","male",28);
teacher2.display();
    }
    
}
