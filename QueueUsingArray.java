class Queue
{
    int size = 4 , front = -1, rear = -1;
    int[] queue = new int[size];

    void Insert(int data)
    {
        if(rear >= size-1)
        {
            System.out.println("Queue OverFlow"+"\n"+"Cannot Insert Elements");
        }
        else
        {
            rear++;
            queue[rear] = data;

            if(front == -1)
            {
                front++;
            }
        }
    }

    void QDel()
    {
        if(front == -1)
        {
            System.out.println("Queue UnderFlow"+"\n"+"Cannot Delete Elements");
        }
        else
        {
            int temp = queue[front];
            queue[front] = 0;
             System.out.println("Deleted Data: "+temp+"\n");
            
            if(front == rear)
            {
                front = rear = -1;
                System.out.println("Front: "+front+"\t"+"Rear: "+rear+"\n");
            }
            front++;
        }
    }

    void Display()
    {
        while(rear > -1)
        {
            System.out.println("Data: "+queue[rear]+"\t"+"Front: "+front+"\t"+"Rear: "+rear+"\n");
            rear--;
        }
    }
}

public class QueueUsingArray
{

    public static void main(String args[])
    {
        Queue q = new Queue();

        q.Insert(10);
        q.Insert(20);
        q.Insert(30);
        q.Insert(40);

        //q.QDel();
        //q.QDel();
        //q.QDel();
        //q.QDel();

        q.Display();
    }
}