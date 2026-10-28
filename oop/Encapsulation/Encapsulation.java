class person{
   private String name;
    private int age;

    public void setinfo(String name,int age){
        this.name=name;
        this.age=age;
    }
    public void getinfo(){
        System.out.println("name=" +name);
        System.out.println("age=" +age);
    }
}
public class Encapsulation {
    public static void main(String[] args) {
        person person=new person();
        person.setinfo("ansi",28);
        person.getinfo();
    }
    
}
