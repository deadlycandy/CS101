
public class Lex {

	public static void main(String[] args) {
		//cat rat bat hat vat mat pet set met fat 
		String[] A = {"Cat", "rat", "Bat", "hat", "Eleven", "Ten", "Cat", "set", "pEt", "vat", "mat", "Ten"};
		for(int k = 0; k < A.length; k++){
			A[k] = A[k].toLowerCase();
		}
		List L = new List();
		List L2 = new List();
		for(int j = 0; j < A.length; j++){
			L.append(j);
		}
		
		for(int i = 1; i < A.length; i++){
			String x = A[i];
			int j = i;
			L.moveFront();
			//Grabbing J
			while(j > 0 && L.index()>=0){
				L.moveNext();
//				System.out.println("Loop " + L.index());
				j--;
			}
//			System.out.println("temp " + L.get());
			int temp = L.get();
			L.delete();
			L.moveFront();
			
			
			//Finding j-1
			j = i -1;
			while(j >= 0 && A[L.get()].compareTo(x) < 0 ){
				L.moveNext();
//				System.out.println("Loop1 " + L.index());
				j--;
			}
			L.insertBefore(temp);
		}
		L.moveFront();
		while(L.index() >= 0){
			System.out.println(A[L.get()]);
			L.moveNext();
		}
		
		
	}

}
/*
 * first while loop locates J the element that needs to be sorted 
 * second while loop finds the begining of the sorted subarry 
 * thrid while loops finds the position of j
 */
