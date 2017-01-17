
public class ListTest {

	public static void main(String[] args) {
		List A = new List();
		List B = new List();
		
		A.append(5);
		A.append(4);
		A.moveBack();

		System.out.println(A.index());
		System.out.println(A.get());
		A.insertAfter(3);
		A.append(2);
		while(A.index()>=0){
			System.out.println(A.index());
			System.out.println(A.get());
			A.moveNext();
		}
	}

}
