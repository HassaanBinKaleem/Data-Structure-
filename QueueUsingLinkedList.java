class Queue
{
    int data;
    Queue link;
}

public class QueueUsingLinkedList
{
    public static void main(String args[])
    {
        Queue front = new Queue();
        Queue rear = new Queue();
        front = rear = null;
                
        Insert(front, rear, 10);
        Insert(front, rear, 20);
        Insert(front, rear, 30);

       
        //DelQ(front, rear);

       Display(front, rear);
    }

    public static void Insert(Queue front, Queue rear, int d)
    {
        Queue r = new Queue();
        r.data = d;
        r.link = null;

        if(front == null)
        {
            front = rear = r;
        }
        else
        {
            rear.link = r;
            rear = r;
        }
    }

    public static int DelQ(Queue front, Queue rear)
    {
        if(front == null)
        {
            System.out.println("Queue UnderFlow");
        }
        else
        {
            Queue temp = new Queue();
            temp = front;
            int data = temp.data;
            if(front == rear)
            {
                front = rear = null;
            }
            front = temp.link;
            temp = null;
        }
        return data;
    }

    public static void Display(Queue front, Queue rear)
    {
        Queue temp = new Queue();
        temp = front;
        while(temp != null)
        {
            System.out.println("Data: "+temp.data+"\t"+"Address: "+temp.link+"\t"+"Front:"+front+"\t"+"Rear: "+rear+"\n");
            temp = temp.link;
        }
    }
}