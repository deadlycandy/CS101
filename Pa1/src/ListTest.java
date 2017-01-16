
public class ListTest {

	public static void main(String[] args) {
		List A = new List();
		List B = new List();
		
		A.prepend(5);
		A.prepend(4);
		A.prepend(3);
		A.prepend(2);
		A.moveFront();
		while(A.index()>=0){
			System.out.println(A.index());
			System.out.println(A.get());
			A.moveNext();
		}
//		System.out.println(A.index());
//		System.out.println(A.get());
//		A.movePrev();
//		System.out.println(A.index());
//		System.out.println(A.get());
//		A.movePrev();
//		System.out.println(A.index());
//		System.out.println(A.get());
//		A.movePrev();
//		System.out.println(A.index());
//		System.out.println(A.get());
//		System.out.println("Moving forward");
//		System.out.println(A.index());
//		System.out.println(A.get());
//		A.moveNext();
//		System.out.println(A.index());
//		System.out.println(A.get());
//		A.moveNext();
//		System.out.println(A.index());
//		System.out.println(A.get());
//		A.moveNext();
//		System.out.println(A.index());
//		System.out.println(A.get());
	}

}
