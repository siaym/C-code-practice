class A {
    A() {
        System.out.println("A's Constructor");
    }

    void show() {
        System.out.println("Show from A");
    }
}

class B extends A {
    B() {
        System.out.println("B's Constructor");
    }

    void show() {
        System.out.println("Show from B");
    }
}

public class test {
    public static void main(String[] args) {
        A obj = new B();
        // obj.show();
    }
}