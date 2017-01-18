
public class Lex {

	public static void main(String[] args) {
		String[] A = {"One", "Two", "Three", "Four", "Five"};
		List L = new List();
		List L2 = new List();
		for(int j = 0; j < A.length; j++){
			L.append(j);
		}
		for(int i = 0; i < A.length; i++){
			String x = A[i];
			int j = i - 1;
			L.moveFront();
			while(A[L.get()].compareTo(A[j]) < 0 ){
				L.moveNext();
			}
			int temp = L.get();
			L.delete();
			L.moveFront();
			while(j >= 0){
				L.moveNext();
				j--;
			}
			while(A[L.get()].compareTo(x) < 0){
				L.movePrev();
			}
			L.insertBefore(temp);
			System.out.println(L.toString());
		}
		
		
	}

}
/*
 * first while loop locates J the element that needs to be sorted 
 * second while loop finds the begining of the sorted subarry 
 * thrid while loops finds the position of j
 */
