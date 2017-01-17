
public class Lex {

	public static void main(String[] args) {
		String[] A = {"One", "Two", "Three", "Four", "Five"};
		List L = new List();
		for(int i = 0; i < A.length; i++){
			L.append(i);
		}
		System.out.println(L.toString());
		
		int counter = 0;
		for(int i = 0; i < A.length; i++){
			L.moveFront();
			for(int j = 0; j <= counter+1; j++){
				L.moveNext();
			}
			int temp = L.get();
			L.delete();
			while(L.index() >= 0){
				if(A[temp] <= A[L.get()]){
					
				}
			}
			
		}

	}

}
