// Online Java Compiler
// Use this editor to write, compile and run your Java code online

class Fibo {
    public static void main(String[] args) {
        int a=0;
        int b=1;
        // System.out.println(a+' ');
        // System.out.println(b);
        for(int i=0;i<7;i++){
            int c=a+b;
            a=b;
            b=c;
            System.out.println(c);
        }
        System.out.println("Hello, World!");
    }
}