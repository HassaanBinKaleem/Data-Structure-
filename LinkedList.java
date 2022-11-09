class Node
{
	int data;
	Node link;
}

public class LinkedList
{
	public static void main(String args[])
	{
		Node p = null;
		p = appends(p , 10);
		p = appends(p , 20);
		p = appends(p , 30);
		p = appends(p , 40);
		p = insertAtBeg(p , 50);
		p = insertAtIndex(p , 60 , 2);
		display(p);
	}
	
	public static Node appends(Node q , int d)
	{
		Node r = new Node();
		Node temp = new Node();
		temp = q;
		r.data = d;
		r.link = null;
		if(q == null)
		{
			q = r;
		}
		else
		{
			for( ; temp.link != null ; temp = temp.link);
			{
				temp.link = r;
			}
		}
		return q;
	}
	
	public static void display(Node q)
	{
		while(q != null)
		{
			System.out.println("DATA: "+q.data);
			q = q.link;
		}
	}
	
	public static Node insertAtBeg(Node q , int d)
	{
		Node r = new Node();
		r.data = d;
		r.link = q;
		return r;
	}
	
	public static Node insertAtIndex(Node q , int d , int index)
	{
		Node r = new Node();
		Node t = new Node();
		r.data = d;
		
		t = q;
		
		int i = 0;
		while(i != index-1)
		{
			t = t.link;
			i++;
		}
		r.link = t.link;
		t.link = r;
		
		return q;
	}
}