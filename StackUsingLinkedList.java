class Node 
{
    int data;
    Node link;
}

public class StackUsingLinkedList 
{
    public static void main(String args[]) 
    {
        Node top = new Node();
        top = null;
        top = Push(top , 10);
        top = Push(top , 20);
        top = Push(top , 30);
        top = Push(top , 40);
        top = Push(top , 50);

        top = Pop(top);
        //top = Pop(top);

        Display(top);
    }

    public static Node Push(Node top, int d)
    {
        Node r = new Node();
        r.data = d;
        r.link = null;
        if(top == null)
        {
            top = r;
        }
        else
        {
            r.link = top;
            top = r;
        }

        return top;
    }

    public static Node Pop(Node top)
    {
        if(top == null)
        {
            System.out.println("Stack UnderFlow"+"\n"+"Cannot Pop Elements");
        }
        else
        {
            Node temp = new Node();
            temp = top;
            top = temp.link;
            temp = null;
        }

        return top;
    }

    public static void Display(Node top)
    {
        if(top == null)
        {
            System.out.println("Stack UnderFlow");
        }
        else
        {
            while(top != null)
            {
                System.out.println("Data: "+top.data+"\t"+"Address: "+top.link+"\n");
                top = top.link;
            }
        }
    }
}