/*---------------------------------------------------------------------------------------
 * 
 * Rahil Bhatnagar
 * Rabhatna
 * CMPS101
 * Programming Assignment 1 
 * Lex.java
 * 
 * The file takes in a text file and inputs each line it into the array. 
 * Then a list is created and holds the indices of the array and is sorted into 
 * lexicographical order. 
 * 
 * ---------------------------------------------------------------------------------------
 */

import java.io.*;
import java.util.Scanner;
public class Lex {

	public static void main(String[] args) throws IOException {
		Scanner in = null;
		PrintWriter out  = null;
		//Checks to make sure the user inputs files that exists
		try{
			in = new Scanner(new File("TestIn.txt"));
			out = new PrintWriter(new FileWriter("TestOut.txt"));

			
		}
		catch(FileNotFoundException e){
			System.err.println("File not found");
			System.exit(1);
		}
		//Reads in the lines 
		String file = "";
		while( in.hasNextLine() ){
			file += in.nextLine()+ "\n";
		}
		in.close();
		//Splits the string by new lines, creates array and list 
		String[] A = file.split("\\n");
		List L = new List();
		for(int i =0; i < A.length; i++){
			A[i] = A[i].toLowerCase();
			L.append(i);
		}
		//Sorts the List 
		L = lexSort(A, L);
		//prints the list into the file 
		printList(A,L, out);
		

	}

	//Prints the list 
	static void printList(String []A, List L, PrintWriter out) throws IOException{
		L.moveFront();
		while(L.index() >= 0){
			out.println(A[L.get()]);
			L.moveNext();
		}
		out.close();
	}

	//Sorts the list in lexicographic order 
	static List lexSort(String []A, List L){
		for(int i = 1; i < A.length; i++){
			int j = i-1;
			L.moveFront();

			//Grabbing J
			while(j >= 0 && L.index()>=0){
				L.moveNext();
				j--;
			}
			int temp = L.get();
			L.delete();
			L.moveFront();

			//Finding j-1 and looking for position
			j = i -1;
			while(j >= 0 && A[L.get()].compareTo(A[i]) < 0 ){
				L.moveNext();
				j--;
			}
			//For special case of when the array is of length 2 
			if(L.length() < 2){
				L.append(temp);
			}else{
				L.insertBefore(temp);
			}
			

		}
		return L;
	}

}

