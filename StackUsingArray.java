class Stack
{
    int size = 5, top = -1;
    int[] stack = new int[size];

    void Push(int data)
    {
        if(top >= size-1)
        {
            System.out.println("Stack OverFlow"+"\n"+"Cannot Push Elements");
        }
        else
        {
            top++;
            stack[top] = data;
        }
    }

    int Pop()
    {
        if(top <= -1)
        {
            System.out.println("Stack UnderFlow"+"\n"+"Cannot Pop Elements");
        }
        else
        {
            int temp;
            temp = stack[top];
            stack[top] = 0;
            top--;
        }
        return top;
    }

    int stackTop()
    {
        return stack[top];
    }

    int stackBottom()
    {
        return stack[0];
    }

    void Display()
    {
        if(top <= -1)
        {
            System.out.println("Stack UnderFlow");
        }
        else
        {
            while(top > -1)
            {
                System.out.println("Data: "+stack[top]+"\t"+"Top: "+top+"\n");
                top--;
            }
        }
    }
}

public class StackUsingArray
{
    public static void main(String args[])
    {
        Stack s = new Stack();
        s.Push(10);
        s.Push(20);
        s.Push(30);
        s.Push(40);

        s.Pop();

        System.out.println("Top most value of Stack is: "+s.stackTop());
        System.out.println("Bottom most value of Stack is: "+s.stackBottom());

        s.Display();
    }
}