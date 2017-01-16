
public class ListTest {

	public static void main(String[] args) {
		List A = new List();
		List B = new List();
		
		A.append(5);
		A.append(4);
		A.insertBefore(3);
		A.append(2);
		A.moveFront();
		while(A.index()>=0){
			System.out.println(A.get());
			A.movePrev();
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
