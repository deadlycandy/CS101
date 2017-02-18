
import java.io.*;
import java.util.Scanner;
import java.io.PrintWriter;

public class Sparse{
	public static void main(String [] args) throws IOException{
		Scanner in = null;
		PrintWriter out = null;

		try{
			in = new Scanner(new File(args[0]));
			out = new PrintWriter(new FileWriter(args[1]));
			
		}catch(FileNotFoundException e){
			System.err.println("File not found");
			System.exit(1);
		}

		int size = in.nextInt();
		Matrix A = new Matrix(size);
		Matrix B = new Matrix(size);
		in.nextLine();
		in.nextLine();
		String condition = in.nextLine();
		String [] nums = condition.split(" ");
		int row = 0;
		int col = 0;
		double val = 0;
		while(nums.length > 1 ){
			row = Integer.parseInt(nums[0]);
			col = Integer.parseInt(nums[1]);
			val = Double.parseDouble(nums[2]);
			A.changeEntry(row, col, val);
			condition = in.nextLine();
			nums = condition.split(" ");			
		}
		row = col = 0;
		val = 0;
		while( in.hasNextLine()){
			condition = in.nextLine();
			nums = condition.split(" ");
			if(nums.length > 1){
				row = Integer.parseInt(nums[0]);
				col = Integer.parseInt(nums[1]);
				val = Double.parseDouble(nums[2]);
			}		 
			B.changeEntry(row, col, val);
		}
		in.close();
		out.println("A has " + A.getNNZ() + " non-zero entries:");
		out.println(A);

		out.println("B has " + B.getNNZ() + " non-zero entries");
		out.println(B);

		out.println("(1.5)*A = ");
		out.println(A.scalarMult(1.5));

		out.println("A+B = ");
		out.println(A.add(B));
		
		out.println("A+A = ");
		out.println(A.add(A));

		out.println("B-A = ");
		out.println(B.sub(A));

		out.println("A-A = ");
		out.println(A.sub(A));

		out.println("Transpose (A) = ");
		out.println(A.transpose());

		out.println("A*B = ");
		out.println(A.mult(B));
		
		out.println("B*B = ");
		out.println(B.mult(B));

		out.close();
				
		
	}
	
}
