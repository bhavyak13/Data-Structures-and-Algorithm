class Stackk{
    int[] arr=new int[100];
    int top=0;
    public boolean empty(){
        return top==0;
    }
    public void push(int e){
        arr[top]=e;
        top++;
    }
    public int pop(){
        if(empty())return -1;
        int e=arr[--top];
        return e;
    }
    public int peek(){
        if(empty())return -1;
        return arr[top-1];
    }
}
class StackProgram {
    public static void main(String[] args) {
        Stackk stk=new Stackk();
        stk.push(3);
        stk.push(4);
        stk.push(9);
        System.out.println(stk.pop());
        System.out.println(stk.pop());
        // System.out.println(stk.empty());
    }
}