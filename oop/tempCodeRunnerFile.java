public class test2 {
    private String name ;
    private int age;

    public void setInfo(String name,int age){
        this.name=name;
        this.age=age;
    }
    public String getInfo(){
        return name+" "+age;
    
    }}
    public class print {
     public static void main (String args[]){
        test2 in=new test2();
        in.setInfo("anis",28);
        System.out.println(in.getInfo());

    }
        
    }
   