public class Matrix{
	private class Entry{
		//fields 
		int col;
		double val;
	
		//constructor 
		Entry(int col, double val){
			this.col = col;
			this.val = val;
		}


		public boolean equals(Object x){
			Entry that;
			if(x instanceof Entry){
				that = (Entry)x;
			}else{
				return false;
			}
		
			if(this.col == that.col && this.val == that.val){
				return true;
			}
			else{
				return false;
			}
		
		}
		
		public String toString(){
			return ("(" + this.col + ", " + this.val + ")"); 
		
		}

	}

	//fields
	private List[] matrix;
	private int NNZ;	
	private int size;	
	//constructor
	Matrix(int n){
		if(n < 1){
			throw new RuntimeException("Matrix: failed precondition n >= 1");
		}
		matrix = new List[n+1];
		for(int i = 1; i < n+1; i++){
			matrix[i] = new List();	
		}
		NNZ = 0;
		size = n;
	}	

	//access functions

	//returns the size of the matrix 
	int getSize(){
		return (size);
	}	

	//returns the number of non zero elements
	int getNNZ(){
		return this.NNZ;

	}

	//Checks if two matrixs are equal
	public boolean equals(Object x){
		Matrix that;
		if(x instanceof Matrix){
			that = (Matrix)x;
		}
		else{
			return false;
		}
		
		if(this.getSize() != that.getSize()){
			
			return false;
		}
		for(int i = 1; i <= this.getSize(); i++){
			if((this.matrix[i].equals(that.matrix[i]))){
				
			}else{
				return false;
			}
		}
		return true;
	}

	//Manipulation functions


	void changeEntry(int i, int j, double x){
		if(i > this.getSize() || i < 1){
			throw new RuntimeException("changeEntry: failed precondition 1<=i<=getSize");
		}
		if(j > this.getSize() || j < 1){
			throw new RuntimeException("changeEntry: failed precondition 1<=j<=getSize");
		}
		Entry input = new Entry(j,x);
		if(this.matrix[i].length() == 0){
			if(x!= 0){
				this.matrix[i].append(input);
				this.NNZ++;
			}
		}
		else{
				
			this.matrix[i].moveFront();
			while(this.matrix[i].index() >= 0){
				Entry entry = (Entry)this.matrix[i].get();
			
				if(x != 0){
					if(entry.col >= j){
						if(entry.val != 0 && j == entry.col){
							//overwrite
							entry.val = x;		
							this.matrix[i].moveBack();
						}else{
							//insert
							this.matrix[i].insertBefore(input);
							this.matrix[i].moveBack();
							this.NNZ++;
						}
					}else if (this.matrix[i].index()+1 == this.matrix[i].length()){
						//append
						this.matrix[i].append(input);
						this.matrix[i].moveBack();
						this.NNZ++;
					}
				}else{
					if(entry.col == j){
						if(entry.val != 0){
							//delete
							this.matrix[i].delete();
							this.matrix[i].moveBack();
							this.NNZ--;
						}				
					}
				}
				this.matrix[i].moveNext();
			}
				
		}
	
	}


	void makeZero(){
		for(int i = 1; i <= this.getSize(); i++){
			if(this.matrix[i].length() > 0){
				this.matrix[i].clear();
			}
		}
		this.NNZ = 0;		
	}


	Matrix copy(){
		Matrix x = new Matrix(this.getSize());
		for(int i = 1; i <= this.getSize();i++){
			if(this.matrix[i].length() > 0){
				this.matrix[i].moveFront();
				while(this.matrix[i].index() >= 0){
					Entry in = (Entry)this.matrix[i].get();
					Entry n = new Entry(in.col, in.val);
					x.matrix[i].append(n);
					x.NNZ++;
					this.matrix[i].moveNext();
				}	
			}
		} 
		return x;
	}

	
	Matrix scalarMult(double scale){
		Matrix scaled = this.copy(); 
		for(int i = 1; i <= scaled.getSize();i++){
			scaled.matrix[i].moveFront();
			while(scaled.matrix[i].index() >= 0){	
				Entry x = (Entry)scaled.matrix[i].get();
				x.val *= scale;
				scaled.matrix[i].moveNext();				
			}
		}
		return scaled;
	}


	Matrix add(Matrix m){
		if(this.getSize() != m.getSize()){
			throw new RuntimeException("Add: failed precondition getSize() == m.getSize()");
		}
		Matrix add = new Matrix(this.getSize());
		for(int i = 1; i <= this.getSize(); i++){
			if(this.matrix[i].length() >= 0 && m.matrix[i].length() >= 0){
				this.matrix[i].moveFront();
				m.matrix[i].moveFront();	
				while(this.matrix[i].index() >= 0 && m.matrix[i].index() >= 0){
					Entry a = (Entry)this.matrix[i].get();
					Entry b = (Entry)m.matrix[i].get();
							
					if(a.col == b.col){
						add.changeEntry(i, a.col, (a.val + b.val));
						if(this == m){
							this.matrix[i].moveNext();
						}else{
							this.matrix[i].moveNext();
							m.matrix[i].moveNext();
						}
					}else if(a.col > b.col){
						add.changeEntry(i, b.col, b.val);
						m.matrix[i].moveNext();
					}else if(a.col < b.col){
						add.changeEntry(i, a.col, a.val);
						this.matrix[i].moveNext();
					}
				}
				if(this.matrix[i].index() >= 0){
					while(this.matrix[i].index() >= 0){
						Entry a = (Entry)this.matrix[i].get();
						add.changeEntry(i, a.col, a.val);
						this.matrix[i].moveNext();
					}
						
				}else{
					while(m.matrix[i].index() >= 0){
						Entry b = (Entry)m.matrix[i].get();
						add.changeEntry(i, b.col, b.val);
						m.matrix[i].moveNext();
					}
				}
			}		
		}
	return add;
	}


	Matrix sub(Matrix m){
		if(this.getSize() != m.getSize()){
			throw new RuntimeException("Sub: failed precondition getSize() == m.getSize()");
		}
		Matrix sub = new Matrix(this.getSize());
		for(int i = 1; i <= this.getSize(); i++){
			if(this.matrix[i].length() >= 0 && m.matrix[i].length() >= 0){
				this.matrix[i].moveFront();
				m.matrix[i].moveFront();	
				while(this.matrix[i].index() >= 0 && m.matrix[i].index() >= 0){
					Entry a = (Entry)this.matrix[i].get();
					Entry b = (Entry)m.matrix[i].get();
							
					if(a.col == b.col){
						sub.changeEntry(i, a.col, (a.val - b.val));
						if(this == m){
							this.matrix[i].moveNext();
						}else{			
							this.matrix[i].moveNext();
							m.matrix[i].moveNext();
						}
					}else if(a.col > b.col){
						sub.changeEntry(i, b.col, -b.val);
						m.matrix[i].moveNext();
					}else if(a.col < b.col){
						sub.changeEntry(i, a.col, a.val);
						this.matrix[i].moveNext();
					}		
				}
				if(this.matrix[i].index() >= 0){
					while(this.matrix[i].index() >= 0){
						Entry a = (Entry)this.matrix[i].get();
						sub.changeEntry(i, a.col, a.val);
						this.matrix[i].moveNext();
					}
						
				}else{
					while(m.matrix[i].index() >= 0){
						Entry b = (Entry)m.matrix[i].get();
						sub.changeEntry(i, b.col, -b.val);
						m.matrix[i].moveNext();
					}
				}
			}		
		}
	return sub;
	}



	Matrix transpose(){
		Matrix transpose = new Matrix(this.getSize());	
		for(int i = 1; i <= this.getSize(); i++){
			//int j = 1;
			this.matrix[i].moveFront();
			while(this.matrix[i].index() >= 0){
				Entry in = (Entry)this.matrix[i].get();
				transpose.changeEntry(in.col, i, in.val);  
				//j++;
				this.matrix[i].moveNext();	
			}
		
		}
		return transpose;

	}


	private static double dot(List P, List Q){
		double dot = 0;	
		if(P.length() > 0 && Q.length() > 0){
			P.moveFront();
			Q.moveFront();	
			while(P.index() >= 0 && Q.index() >= 0){
				Entry a = (Entry)P.get();
				Entry b = (Entry)Q.get();
				if(a.col == b.col){
					dot += (a.val * b.val);
					if(P == Q){
						P.moveNext();
					}else{			
						P.moveNext();
						Q.moveNext();
					}
				}else if(a.col > b.col){
					Q.moveNext();
				}else if(a.col < b.col){
					P.moveNext();
				}		
			}
		}
		return dot;		
	}


	Matrix mult(Matrix m){
		if(this.getSize() != m.getSize()){
			throw new RuntimeException("Mult: failed precondition getSize() == M.getSize()");
		}
		Matrix trans = m.transpose();
		Matrix mult = new Matrix(this.getSize()); 	
		for(int i = 1; i <= this.getSize(); i++){
			this.matrix[i].moveFront();	
			for(int j = 1; j <= trans.getSize(); j++){
				trans.matrix[j].moveFront();
				mult.changeEntry(i, j, dot(this.matrix[i], trans.matrix[j]));			
			}
		}
		return mult;
	}


	public String toString(){
		String out = "";
		for(int i = 1; i <= this.getSize(); i++){
			if(this.matrix[i].length() == 0){

			}else{
				out += i + ": " + this.matrix[i].toString() + "\n";
			}
		}
		return out; 
	} 











}
