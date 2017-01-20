import java.io.*;
import java.util.Scanner;
public class Lex {

	public static void main(String[] args) throws IOException {
		Scanner in = null;
		PrintWriter out  = null;
		try{
			in = new Scanner(new File(args[0]));
			out = new PrintWriter(new FileWriter(args[1]));

			
		}
		catch(FileNotFoundException e){
			System.err.println("File not found");
			System.exit(1);
		}
		
		String file = "";
		while( in.hasNextLine() ){
			file += in.nextLine()+ "\n";
		}
		in.close();
		
		String[] A = file.split("\\n");
		List L = new List();
		for(int i =0; i < A.length; i++){
			A[i] = A[i].toLowerCase();
			L.append(i);
		}
		System.out.println(A.length); 
		System.out.println(L.toString());
		L = lexSort(A, L);
		printList(A,L, out);
		

	}

	//Prints the list 
	static void printList(String []A, List L, PrintWriter out) throws IOException{
		L.moveFront();
		while(L.index() >= 0){
			System.out.println(A[L.get()]);
			out.println(A[L.get()]);
			L.moveNext();
		}
		out.close();
	}

	//Sorts the list in lexicographic order 
	static List lexSort(String []A, List L){
		for(int i = 1; i < A.length; i++){
			int j = i;
			L.moveFront();

			//Grabbing J
			while(j > 0 && L.index()>=0){
				L.moveNext();
				j--;
			}
			int temp = L.get();
			L.delete();
			L.moveFront();

			//Finding j-1 and looking for position
			j = i -1;
			while(j >= 0 && A[L.get()].compareTo(A[i]) > 0 ){
				L.moveNext();
				j--;
			}
			L.insertAfter(temp);

		}
		return L;
	}

}

