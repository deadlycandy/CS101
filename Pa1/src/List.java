/*
 *  This is a list ADT 
 * 
 */
public class List {
	
	private class Node{
		//fields
		int data; 
		Node next;
		Node prev;
		
		//constructor 
		Node(int data){
			this.data = data;
			next = null;
		}
		
		//toString function override
		public String toString(){
			return String.valueOf(data);
		}
	}
	
	//fields
	private Node front;
	private Node curr;
	private Node back;
	private int length;
	private int index;
	
	//Constructor 
	List(){
		front = curr = back = null;
		length = index = 0;
	}
	
	//Access functions 
	
	//This returns the length of the list
	 int length(){
		 return this.length;
		
	}
	 
	//This returns the index of curr
	 int index(){
		 if(curr == null)
		 {
			 index = -1;
			 return -1;
		 }
		 return this.index;
	 }
	
	// returns the front element 
	int front(){
		if(this.length < 0)
		{
			throw new RuntimeException("Failed precondition length > 0");
		}
		return this.front.data;
	}
	
	//returns the back element
	int back(){
		if(this.length < 0)
		{
			throw new RuntimeException("Failed precondition length > 0");
		}
		return this.back.data;
	}
	
	//returns the cursor element 
	int get(){
		if(this.length < 0)
		{
			throw new RuntimeException("Failed precondition length > 0");
		}
		if(this.index < 0)
		{
			throw new RuntimeException("Failed precondition index > 0");
		}
		return this.curr.data; 
	}
	
	//Compares two lists to check if they are the same 
	boolean equals(List L ){
		if(this.length == L.length){
			Node current = this.front;
			Node current2 = L.front;
			while(current.next != null && current2.next != null){
				if(current.data != current2.data){
					return false;
				}
			}
			return true;
		}
		return false;
	}
	
	//Manipulation procedures 
	
	//Clears all the nodes in the list and sets it to an empty list
	void clear(){
		Node current = this.front;
		while(current.next != null){
			Node temp = current;
			current = current.next;
			temp = null;
		}
		front = back = curr = null;
		length = 0;
		index = 0;
	}
	
	//Moves cursor to the front of the list
	void moveFront(){
		if(this.length > 0){
			curr = front;
		}
		index = 0;
	}
	
	//Moves cursor to the back of the list
	void moveBack(){
		if(this.length > 0){
			curr = back;
		}
		
		index = length -1;
	}
	
	//Moves one to the left (previous)
	void movePrev(){
		if(curr != null && curr != front){
			curr = curr.prev;
			index -= 1;
		}
		else if(curr == front){
			curr = null;
		}
	}
	
	//Moves one to the right (next)
	void moveNext(){
		if(curr != null && curr != back){
			curr = curr.next;
			index += 1;
		}
		else if(curr == back){
			curr = null;
		}
	}
	
	//prepend adding node to the front of the list 
	void prepend(int data){
		Node newNode = new Node(data);
		if(this.length == 0){
			this.front = newNode;
			this.back = newNode;
			this.curr = newNode;
			this.length = 1;
		}
		else{
			newNode.next = front;
			front.prev = newNode;
			newNode.prev = null;
			front = newNode;
			length += 1;
			index += 1;
		}	
	}
	
	
	
}
