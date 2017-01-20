/*---------------------------------------------------------------------------------------
 * 
 * Rahil Bhatnagar
 * Rabhatna
 * CMPS101
 * Programming Assignment 1 
 * Lex.java
 * 
 * This is a list ADT with multiple access and manipulation functions. Uses a private node
 * class to create the list and holds an int data type. 
 * 
 * ---------------------------------------------------------------------------------------
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
			this.next = null;
			this.prev = null;
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
		length = 0;
		index = -1;
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
			 return -1;
		 }
		 return this.index;
	 }
	
	// returns the front element 
	int front(){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		return this.front.data;
	}
	
	//returns the back element
	int back(){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		return this.back.data;
	}
	
	//returns the cursor element 
	int get(){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		if(this.index < 0)
		{
			throw new RuntimeException("Failed precondition index < 0");
		}
		return this.curr.data; 
	}
	
	//Compares two lists to check if they are the same 
	boolean equals(List L ){
		if(this.length == L.length){
			Node current = this.front;
			Node current2 = L.front;
			while(current != null && current2 != null){
				if(current.data != current2.data){
					return false;
				}
				current = current.next;
				current2 = current2.next;
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
		index = -1;
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
			index = -1;
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
			index = -1;
			curr = null;
		}
	}
	
	//prepend adding node to the front of the list 
	void prepend(int data){
		Node newNode = new Node(data);
		if(this.length == 0){
			this.front = newNode;
			this.back = newNode;
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
	
	//Append function for adding nodes at the end of the list 
	void append(int data){
		Node newNode = new Node(data);
		if(this.length == 0){
			this.front = newNode;
			this.back = newNode;
			this.length = 1;
		}
		else{
			back.next = newNode;
			newNode.prev = back;
			back = newNode;
			newNode.next = null;
			length += 1;
		}	
	}
	
	//Inserting a node before cursor 
	
	void insertBefore(int data){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		if(this.index < 0)
		{
			throw new RuntimeException("Failed precondition index < 0");
		}
		if(curr.prev == null)
		{
			this.prepend(data);
		}
		else{
			Node newNode = new Node(data);
			curr.prev.next = newNode;
			newNode.prev = curr.prev;
			newNode.next = curr;
			curr.prev = newNode;
			index += 1;
			length += 1;
		}
		
	}
	
	//Inserting a node after cursor 
	void insertAfter(int data){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		if(this.index < 0)
		{
			throw new RuntimeException("Failed precondition index < 0");
		}
		if(curr.next == null)
		{
			this.append(data);
		}
		else{
			Node newNode = new Node(data);
			newNode.next = curr.next;
			curr.next = newNode;
			newNode.next.prev = newNode;
			newNode.prev = curr;
			length += 1;
		}
		
	}
	
	//Deletes front element
	void deleteFront(){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		front = front.next;
		front.prev = null;
		index -= 1;
		length -= 1;
	}
	
	//Deletes back elements
	void deleteBack(){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		back = back.prev;
		back.next = null;
		length -=1;
	}
	
	//Deletes cursor elements (NULL PROB)
	void delete(){
		if(this.length <= 0)
		{
			throw new RuntimeException("Failed precondition length < 0");
		}
		if(this.index < 0)
		{
			throw new RuntimeException("Failed precondition index < 0");
		}
		if(curr.next ==  null){
			back = back.prev;
			back.next = null;
			curr = null;
			length -= 1;
			index = -1;
		}
		else if(curr.prev == null){
			front = front.next;
			front.prev = null;
			curr = null;
			length -= 1;
			index = -1;
		}
		else{
			curr.prev.next = curr.next;
			curr.next.prev = curr.prev;
			curr = null;
			length -= 1;
			index = -1;
		}
		
	}
	
	//ToString method for printing out a list
	public String toString(){
		Node temp = front;
		String strList = "";
		while(temp != null){
			strList += temp.data;
			strList += " ";
			temp = temp.next;
		}
		return strList;
	}
	
	//Copy into a new list
	List copy(){
		List c = new List();
		Node temp = this.front;
		while(temp != null){
			c.append(temp.data);
			temp = temp.next;
		}
		return c;
		
	}
	
	
}
