//-----------------------------------------------------------------------------
//  MatrixClient.java
//  A test client for the Matrix ADT
//-----------------------------------------------------------------------------


public class MatrixClient{
   public static void main(String[] args){
      int i, j, n=1000;
      Matrix A = new Matrix(n);
      Matrix B = new Matrix(n);

      A.changeEntry(1,1,1); B.changeEntry(1,1,2);
      A.changeEntry(1,2,2); B.changeEntry(1,2,3);
      A.changeEntry(1,3,3); B.changeEntry(1,3,5);
      A.changeEntry(2,1,4); B.changeEntry(2,1,6);
      A.changeEntry(2,2,5); B.changeEntry(2,2,2);
      A.changeEntry(2,3,6); B.changeEntry(2,3,1);
      A.changeEntry(3,1,7); B.changeEntry(3,1,0);
      A.changeEntry(3,2,8); B.changeEntry(3,2,0);
      A.changeEntry(3,3,9); B.changeEntry(3,3,0);

      System.out.println(A.getNNZ());
      System.out.println(A);
	
      System.out.println(B.getNNZ());
      System.out.println(B);
     
      System.out.println("ScalarMult C = A*(3.5)");

      Matrix C = A.scalarMult(3.5);
      System.out.println(C.getNNZ());
      System.out.println(C);

      System.out.println("Add D = A + A");

      Matrix D = A.add(A);
      System.out.println(D.getNNZ());
      System.out.println(D);

      System.out.println("Sub E = D - A");

      Matrix E = D.sub(A);
      System.out.println(E.getNNZ());
      System.out.println(E);

      System.out.println("Transpose B");

      Matrix F = B.transpose();
      System.out.println(F.getNNZ());
      System.out.println(F);

      System.out.println("Mult G = B*B");

      Matrix G = B.mult(B);
      System.out.println(G.getNNZ());
      System.out.println(G);

      System.out.println("Copy A");

      Matrix H = A.copy();
      System.out.println(H.getNNZ());
      System.out.println(H);
      System.out.println(A.equals(H));
      System.out.println(A.equals(B));
      System.out.println(A.equals(A));
      
      System.out.println("\nX = 10*(A + ( Transpose B)) ");
      Matrix X = A.add(B.transpose());
      X = X.scalarMult(10);
      System.out.println(X);

      System.out.println("Make Zero A");

      A.makeZero();
      System.out.println(A.getNNZ());
      System.out.println(A);
      
      System.out.println("X = X*A");
      X = X.mult(A);
      System.out.println(X);
      System.out.println("X  == A");
      System.out.println(X.equals(A)); 
   }
}
