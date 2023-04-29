#include <iostream>

const int SIZE = 8; //the length of the array 

    void printArray(int x[]){ // parameter: array

		for(int i=0;i<SIZE;i++){ // traverse while i is less than the size of the array
			std::cout<< x[i] << " "; // print each value
		}
		std::cout<<"\n";
	}

	void heapsort(int x[]){ // parameter: array
		int i, parent, child;

		if(SIZE == 0)	return; // if array is empty
		
		// preprocessing phase; create initial heap
		for(i = 1; i < SIZE; i++){ // while i is less than the size of the array
			int elt = x[i]; // elt = current value at index i 
			std::cout <<"bubble-up i=" << i << "  x[i]=" << x[i] << "\n"; // print index and value at index 

			// bubble_up
			child = i; // child = index
			parent = (child - 1)/2; // parent is (index - 1)/2
			while(child > 0 && x[parent] < elt){ // while the index is bigger than 0 and the value at index parent is less than elt value
				x[child] = x[parent]; // value at child becomes value at parent
				child = parent; // child index become parent index
				parent = (child - 1)/2; // parent becomes (child index - 1)/2
			}
			x[child] = elt; // value at child becomes elt value
		}

		std::cout << "Initial heap: " <<"\t";
		printArray(x);
		
		// selection phase; repeatedly remove x[0], insert it
		// in its proper position and adjust the heap
		for(i = SIZE-1; i > 0; i--){ // while i is the size of the array and bigger than zero, decrement
			// bubble-down

			std::cout <<"i=" << i << "  x[i]=" << x[i] << "\t";  // print index and value
			printArray(x);
			
			//put x[0] in i-th position
			int iValue = x[i]; // iValue = value at index i
			x[i] = x[0]; // value at index i = value at x[0]
			
			parent = 0;
			
			//select the large child
			if(i == 1) 						child = -1;
			else							child = 1;
			if(i > 2 && x[2] > x[1])		child = 2;

			while(child >= 0 && iValue < x[child]){
				
				//move child into parent position
				x[parent] = x[child];
				parent = child;
				child = 2*parent + 1; //first child index
				
				if(child > i-1)  //no child
					break;
				
				//if there is a second child and it is larger
				if(child + 1 <= i-1 && x[child] < x[child+1])
					child = child + 1;  //get second child 				
			}
			x[parent] = iValue;
		}
		std::cout <<"\t\t"; 
		printArray(x);
		
	} // end heapsort


int main(){
		int b[] = {75, 3, 4, 83, 51, 45, 67, 72	};     
		std::cout << "Numbers:\t";
		printArray(b);
		
		heapsort(b);
		std::cout << "\nSorted numbers using Heap sort:";
		printArray(b);
}
