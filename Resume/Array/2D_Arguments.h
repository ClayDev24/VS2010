#include <iostream>
#include <algorithm> // std::fill

namespace resume {

	// === Method 1: Static 2D array ===
	void passStaticArray(int a[][10]) {
		std::cout << "Static 2D array:\n";
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				std::cout << "a[" << i << "][" << j << "] = " << a[i][j] << "\n";
	}

	// === Method 2: Array of pointers ===
	void passArrayOfPointers(int* a[10]) {
		std::cout << "\nArray of pointers:\n";
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				std::cout << "a[" << i << "][" << j << "] = " << a[i][j] << "\n";
	}

	// === Method 3: Pointer to pointer ===
	void passPointerToPointer(int** a) {
		std::cout << "\nPointer to pointer:\n";
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				std::cout << "a[" << i << "][" << j << "] = " << a[i][j] << "\n";
	}

	static void _func2DArrays() {
		// Method 1: Static 2D array
		int staticArray[10][10] = { {1, 2}, {3, 4} };
		passStaticArray(staticArray);

		// Method 2: Array of pointers
		int* pointerArray[10];
		for (int i = 0; i < 10; ++i)
			pointerArray[i] = new int[10]; // Allocate each row
		pointerArray[0][0] = 10;
		pointerArray[0][1] = 20;
		pointerArray[1][0] = 30;
		pointerArray[1][1] = 40;
		passArrayOfPointers(pointerArray);
		//passArrayOfPointers(&staticArray);

		// Method 3: Pointer to pointer
		int** doublePointerArray = new int*[10];
		for (int i = 0; i < 10; ++i)
			doublePointerArray[i] = new int[10];
		doublePointerArray[0][0] = 100;
		doublePointerArray[0][1] = 200;
		doublePointerArray[1][0] = 300;
		doublePointerArray[1][1] = 400;
		passPointerToPointer(doublePointerArray);

		// Free memory for methods 2 and 3
		for (int i = 0; i < 10; ++i) {
			delete[] pointerArray[i];
			delete[] doublePointerArray[i];
		}
		delete[] doublePointerArray;
	}


	// 1. Pass by REFERENCE:
	template<size_t rows, size_t cols>
	static void process_2d_array_ref(int (&array)[rows][cols]) {
		for(size_t r=0; r<rows; ++r) {
			std::cout << r << ": ";
			for(size_t c=0; c<cols; ++c)
				std::cout << array[r][c] << '\t';
			std::cout << std::endl;
		}
	}
	// In C++ passing the array by REFERENCE without losing the dimension information is probably the SAFEST,
	//		since one needn't worry about the caller passing an incorrect dimension (compiler flags when mismatching).
	// However, this isn't possible with dynamic (freestore) arrays; it works for automatic (usually stack-living) arrays
	// only i.e. the dimensionality should be known at compile time.

	// 2. Pass by POINTER:
	static void process_2d_array_ptr(int (*array)[5][10]) {
		for (size_t r=0; r<5; ++r) {
			std::cout << r << ": ";
			for (size_t c=0; c<10; ++c)
				std::cout << (*array)[r][c] << '\t';
			std::cout << std::endl;
		}    
	}

	// The C equivalent of the previous method is passing the array by POINTER.
	// This should not be confused with passing by the array's decayed pointer type (3), which is the common, popular method,
	// albeit less safe than this one but more flexible.
	// Like (1), use this method when all the dimensions of the array is fixed and known at compile-time.
	// Note that when calling the function the array's address should be passed process_2d_array_ptr(&a)
	// and not the address of the first element by decay process_2d_array_ptr(a).

	// Variable Size
	// These are inherited from C but are less safe, the compiler has no way of checking,
	// guaranteeing that the caller is passing the required dimensions.
	// The function only banks on what the caller passes in as the dimension(s).
	// These are more flexible than the above ones since arrays of different lengths can be passed to them invariably.

	// There's no such thing as passing an array directly to a function in C
	// (while in C++ they can be passed as a reference (1)); (2) is passing a pointer to the array and not the array itself.
	// Always passing an array as-is becomes a pointer-copy operation which is facilitated by array's nature of decaying into a pointer.

	// 3. Pass by (value) a pointer to the decayed type
	// int array[][10] is just fancy notation for the same thing
	static void process_2d_array(int (*array)[10], size_t rows) {

		for (size_t r=0; r<rows; ++r) {
			std::cout << r << ": ";
			for (size_t c=0; c<10; ++c)
				std::cout << array[r][c] << '\t';
			std::cout << std::endl;
		}
	}
	// Although int array[][10] is allowed, I'd not recommend it over the above syntax since the above syntax
	// makes it clear that the identifier array is a single pointer to an array of 10 integers, while this syntax looks like
	// it's a 2D array but is the same pointer to an array of 10 integers.
	// Here we know the number of elements in a single row (i.e. the column size, 10 here)
	// but the number of rows is unknown and hence to be passed as an argument.
	// In this case there's some safety since the compiler can flag when a pointer to an array with second dimension
	// not equal to 10 is passed. The first dimension is the varying part and can be omitted.
	// See here for the rationale on why only the first dimension is allowed to be omitted.

	// 4. Pass by pointer to a pointer
	// int *array[10] is just fancy notation for the same thing
	static void process_pointer_2_pointer(int **array, size_t rows, size_t cols) {
		for (size_t r=0; r<rows; ++r) {
			std::cout << r << ": ";
			for (size_t c=0; c<cols; ++c)
				std::cout << array[r][c] << '\t';
			std::cout << std::endl;
		}
	}
	//		Again there's an alternative syntax of int *array[10] which is the same as int **array. In this syntax the [10] is ignored
	// as it decays into a pointer thereby becoming int **array.
	// Perhaps it is just a cue to the caller that the passed array should have at least 10 columns, even then row count is required.
	// In any case the compiler doesn't flag for any length/size violations (it only checks if the type passed is a pointer to pointer),
	// hence requiring both row and column counts as parameter makes sense here.
	//		Note: (4) is the least safest option since it hardly has any type check and the most inconvenient.
	// One cannot legitimately pass a 2D array to this function; C-FAQ condemns the usual workaround of doing int x[5][10];
	// process_pointer_2_pointer((int**)&x[0][0], 5, 10); as it may potentially lead to undefined behaviour due to array flattening.
	// The right way of passing an array in this method brings us to the inconvenient part i.e. we need an additional (surrogate) array
	// of pointers with each of its element pointing to the respective row of the actual, to-be-passed array; this surrogate is then
	// passed to the function (see below); all this for getting the same job done as the above methods which are more safer, cleaner and perhaps faster.
	
	//Here's a driver program to test the above functions:

#define LINE   7
#define COLUMN 12
	static void _bidim_ArgumentsUsage() {
		// a[linha][coluna]
		int a[LINE][COLUMN] = { { } }; // Inicializa o array com zeros.
		// fill(início, fim, valor): 
		std::fill(&a[0][0], &a[0][0] + LINE * COLUMN, 2);

//		process_2d_array_ref(a);
//		process_2d_array_ptr(&a);	// <-- notice the unusual usage of addressof (&) operator on an array
//		process_2d_array(a, LINE);		// works since a's first dimension decays into a pointer thereby becoming int (*)[10]

		int *b[LINE];  // surrogate
		for (size_t i=0; i<LINE; ++i) {
			b[i] = a[i];
		}
		// another popular way to define b: here the 2D arrays dims may be non-const, runtime var
		// int **b = new int*[5];
		// for (size_t i = 0; i < 5; ++i) b[i] = new int[10];
		process_pointer_2_pointer(b, LINE, COLUMN);
		// process_2d_array(b, 5);
		// doesn't work since b's first dimension decays into a pointer thereby becoming int**
	}
	/*
	What about passing dynamically allocated arrays to functions in C++? In C11 standard it can be done for statically and dynamically allocated arrays like that fn(int col,int row, int array[col][row]): stackoverflow.com/questions/16004668/… I have made the question for this problem: stackoverflow.com/questions/27457076/… – 42n4 Dec 13 '14 at 9:16 
	@42n4 Case 4 covers (for C++ as well) that. For dynamically allocated arrays, just the line inside the loop would change from b[i] = a[i]; to, say, b[i] = new int[10];. One may also make b dynamically allocated int **b = int *[5]; and it'll still work as-is. – legends2k Dec 15 '14 at 6:42

	How does addressing array[i][j] work into the function in 4)? Because it has received ptr to ptr and does not know the value of last dimension, which is necessary to perform a shift for correct addressing? – user1234567 Dec 16 '14 at 16:27

	array[i][j] is just pointer arithmetic i.e. to the value of the pointer array, it'd add i and dereference the result as int*, to which it would add j and dereference that location, reading an int. So, no, it needn't know any dimension for this. But, that's the whole point! The compiler takes the programmer's word in faith and if the programmer was incorrect, undefined behaviour ensues. This is the reason I'd mentioned that case 4 is the least safest option. – legends2k Dec 17 '14 at 3:04 
	In such cases a struct may serve you well. – Xofo Nov 16 '18 at 18:17
	show 1 more comment

	A modification to shengy's first suggestion, you can use templates to make the function accept a multi-dimensional array variable (instead of storing an array of pointers that have to be managed and deleted):

	template <size_t size_x, size_t size_y>
	void func(double (&arr)[size_x][size_y])
	{
	printf("%p\n", &arr);
	}

	int main()
	{
	double a1[10][10];
	double a2[5][5];

	printf("%p\n%p\n\n", &a1, &a2);
	func(a1);
	func(a2);

	return 0;
	}
	The print statements are there to show that the arrays are getting passed by reference (by displaying the variables' addresses)

	Share
	Improve this answer
	Follow
	edited Jul 27 '14 at 19:21
	answered Jan 7 '12 at 4:27

	Zrax
	1,39288 silver badges1313 bronze badges

	You should use %p for printing a pointer, and even then, you must cast it to void *, else printf() invokes undefined behavior. Furthermore, you should not use the addressof (&) operator when calling the functions, since the functions expect an argument of type double (*)[size_y], whereas you currently pass them double (*)[10][10] and double (*)[5][5]. – user529758 Oct 20 '13 at 8:26
	If you're using templates making both dimensions as template arguments is more appropriate and is better since low-level pointer access may be completely avoided. – legends2k Mar 24 '14 at 12:43 

	This only works if the size of the array is known at compile time. – John Doe Dec 27 '17 at 16:51
	@Georg Code above in answer is exactly what I'd suggested. It works in GCC 6.3 - online demo. Did you forget to make the parameter a reference? – legends2k Nov 29 '18 at 5:39
	add a comment

	Surprised that no one mentioned this yet, but you can simply template on anything 2D supporting [][] semantics.

	template <typename TwoD>
	void myFunction(TwoD& myArray){
	myArray[x][y] = 5;
	etc...
	}

	// call with
	double anArray[10][10];
	myFunction(anArray);
	It works with any 2D "array-like" datastructure, such as std::vector<std::vector<T>>, or a user defined type to maximize code reuse.

	Share
	Improve this answer
	Follow
	answered Dec 22 '14 at 18:26

	LemonPi
	72377 silver badges1515 bronze badges
	1
	This should be the right answer. It solves all problems mentioned and some that were not mentioned here. Type safety, compile time incompatibility of arrays, no pointer arithmetic, no type casting, no data copying. Works for C and C++. – OpalApps Dec 7 '18 at 16:10 
	3
	Well, this works for C++; C doesn't support templates. Doing it in C would require macros. – Gunnar May 21 '19 at 21:22
	add a comment

	20

	You can create a function template like this:

	template<int R, int C>
	void myFunction(double (&myArray)[R][C])
	{
	myArray[x][y] = 5;
	etc...
	}
	Then you have both dimension sizes via R and C. A different function will be created for each array size, so if your function is large and you call it with a variety of different array sizes, this may be costly. You could use it as a wrapper over a function like this though:

	void myFunction(double * arr, int R, int C)
	{
	arr[x * C + y] = 5;
	etc...
	}
	It treats the array as one dimensional, and uses arithmetic to figure out the offsets of the indexes. In this case, you would define the template like this:

	template<int C, int R>
	void myFunction(double (&myArray)[R][C])
	{
	myFunction(*myArray, R, C);
	}
	Share
	Improve this answer
	Follow
	answered Jan 7 '12 at 4:20

	Benjamin Lindley
	94.4k88 gold badges169169 silver badges254254 bronze badges
	2
	size_t is the better type for array indexes than int. – Andrew Tomazos Jul 10 '13 at 11:42
	add a comment

	13

	anArray[10][10] is not a pointer to a pointer, it is a contiguous chunk of memory suitable for storing 100 values of type double, which compiler knows how to address because you specified the dimensions. You need to pass it to a function as an array. You can omit the size of the initial dimension, as follows:

	void f(double p[][10]) {
	}
	However, this will not let you pass arrays with the last dimension other than ten.

	The best solution in C++ is to use std::vector<std::vector<double> >: it is nearly as efficient, and significantly more convenient.

	Share
	Improve this answer
	Follow
	answered Jan 7 '12 at 3:54

	Sergey Kalinichenko
	667k7171 gold badges978978 silver badges13801380 bronze badges
	1
	I prefer this solution as the std library is very efficient - by the way I like dasblinkenlight; I used to use dasblikenlicht – mozillanerd Jan 18 '12 at 21:34
	Nearly as efficient? Yeah right. Pointer chasing is always more expensive than non-pointer chasing. – Thomas Eding Sep 24 '15 at 19:07
	add a comment

	8

	Single dimensional array decays to a pointer pointer pointing to the first element in the array. While a 2D array decays to a pointer pointing to first row. So, the function prototype should be -

	void myFunction(double (*myArray) [10]);
	I would prefer std::vector over raw arrays.

	Share
	Improve this answer
	Follow
	answered Jan 7 '12 at 3:54

	Mahesh
	32.1k1717 gold badges8080 silver badges110110 bronze badges
	add a comment

	8

	Here is a vector of vectors matrix example

	#include <iostream>
	#include <vector>
	using namespace std;

	typedef vector< vector<int> > Matrix;

	void print(Matrix& m)
	{
	int M=m.size();
	int N=m[0].size();
	for(int i=0; i<M; i++) {
	for(int j=0; j<N; j++)
	cout << m[i][j] << " ";
	cout << endl;
	}
	cout << endl;
	}


	int main()
	{
	Matrix m = { {1,2,3,4},
	{5,6,7,8},
	{9,1,2,3} };
	print(m);

	//To initialize a 3 x 4 matrix with 0:
	Matrix n( 3,vector<int>(4,0));
	print(n);
	return 0;
	}
	output:

	1 2 3 4
	5 6 7 8
	9 1 2 3

	0 0 0 0
	0 0 0 0
	0 0 0 0
	Share
	Improve this answer
	Follow
	answered Jul 7 '18 at 19:21

	edW
	1,5211717 silver badges1313 bronze badges
	add a comment

	7

	You can do something like this...

	#include<iostream>

	using namespace std;

	//for changing values in 2D array
	void myFunc(double *a,int rows,int cols){
	for(int i=0;i<rows;i++){
	for(int j=0;j<cols;j++){
	*(a+ i*rows + j)+=10.0;
	}
	}
	}

	//for printing 2D array,similar to myFunc
	void printArray(double *a,int rows,int cols){
	cout<<"Printing your array...\n";
	for(int i=0;i<rows;i++){
	for(int j=0;j<cols;j++){
	cout<<*(a+ i*rows + j)<<"  ";
	}
	cout<<"\n";
	}
	}

	int main(){
	//declare and initialize your array
	double a[2][2]={{1.5 , 2.5},{3.5 , 4.5}};

	//the 1st argument is the address of the first row i.e
	//the first 1D array
	//the 2nd argument is the no of rows of your array
	//the 3rd argument is the no of columns of your array
	myFunc(a[0],2,2);

	//same way as myFunc
	printArray(a[0],2,2);

	return 0;
	}
	Your output will be as follows...

	11.5  12.5
	13.5  14.5
	Share
	Improve this answer
	Follow
	answered Sep 20 '14 at 14:57

	Sagar Shah
	38155 silver badges1010 bronze badges
	1
	The only reason I can come up with of why one would mangle the array in this case, is because one is lacking knowledge about how array pointers work. – Lundin Jun 16 '15 at 8:09
	5
	the i variable must be multiplied by columns, not by rows unless columns and rows are equal like in this case – Andrey Chernukha Jan 5 '16 at 21:51
	* (a+ (i* cols) + j) is true. not this * (a+( i* rows) + j) . plz fix it – Sadegh Dec 14 '20 at 13:35 
	add a comment

	4

	We can use several ways to pass a 2D array to a function:

	Using single pointer we have to typecast the 2D array.

	#include<bits/stdc++.h>
	using namespace std;


	void func(int *arr, int m, int n)
	{
	for (int i=0; i<m; i++)
	{
	for (int j=0; j<n; j++)
	{
	cout<<*((arr+i*n) + j)<<" ";
	}
	cout<<endl;
	}
	}

	int main()
	{
	int m = 3, n = 3;
	int arr[m][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	func((int *)arr, m, n);
	return 0;
	}
	Using double pointer In this way, we also typecast the 2d array

	#include<bits/stdc++.h>
	using namespace std;

	void func(int **arr, int row, int col)
	{
	for (int i=0; i<row; i++)
	{
	for(int j=0 ; j<col; j++)
	{
	cout<<arr[i][j]<<" ";
	}
	printf("\n");
	}
	}

	int main()
	{
	int row, colum;
	cin>>row>>colum;
	int** arr = new int*[row];

	for(int i=0; i<row; i++)
	{
	arr[i] = new int[colum];
	}

	for(int i=0; i<row; i++)
	{
	for(int j=0; j<colum; j++)
	{
	cin>>arr[i][j];
	}
	}
	func(arr, row, colum);

	return 0;
	}
	Share
	Improve this answer
	Follow
	edited Jan 16 at 15:27

	ks1322
	28.8k1212 gold badges8686 silver badges133133 bronze badges
	answered Jun 20 '18 at 11:51

	rashedcs
	2,50122 gold badges2929 silver badges3030 bronze badges
	1
	Why should I not #include <bits/stdc++.h>? – David C. Rankin Dec 6 '20 at 6:20
	add a comment

	1

	One important thing for passing multidimensional arrays is:

	First array dimension need not be specified.
	Second(any any further)dimension must be specified.
	1.When only second dimension is available globally (either as a macro or as a global constant)

	const int N = 3;

	void print(int arr[][N], int m)
	{
	int i, j;
	for (i = 0; i < m; i++)
	for (j = 0; j < N; j++)
	printf("%d ", arr[i][j]);
	}

	int main()
	{
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	print(arr, 3);
	return 0;
	}
	2.Using a single pointer: In this method,we must typecast the 2D array when passing to function.

	void print(int *arr, int m, int n)
	{
	int i, j;
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
	printf("%d ", *((arr+i*n) + j));
	}

	int main()
	{
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int m = 3, n = 3;

	// We can also use "print(&arr[0][0], m, n);"
	print((int *)arr, m, n);
	return 0;
	}
	Share
	Improve this answer
	Follow
	edited Jan 16 at 15:19

	ks1322
	28.8k1212 gold badges8686 silver badges133133 bronze badges
	answered Jun 10 '17 at 4:41

	sonorous
	3155 bronze badges
	add a comment

	0

	You can use template facility in C++ to do this. I did something like this :

	template<typename T, size_t col>
	T process(T a[][col], size_t row) {
	...
	}
	the problem with this approach is that for every value of col which you provide, the a new function definition is instantiated using the template. so,

	int some_mat[3][3], another_mat[4,5];
	process(some_mat, 3);
	process(another_mat, 4);
	instantiates the template twice to produce 2 function definitions (one where col = 3 and one where col = 5).

	Share
	Improve this answer
	Follow
	edited Nov 22 '15 at 18:51
	answered Oct 14 '15 at 14:59

	vantony
	45355 silver badges88 bronze badges
	add a comment

	0

	If you want to pass int a[2][3] to void func(int** pp) you need auxiliary steps as follows.

	int a[2][3];
	int* p[2] = {a[0],a[1]};
	int** pp = p;

	func(pp);
	As the first [2] can be implicitly specified, it can be simplified further as.

	int a[][3];
	int* p[] = {a[0],a[1]};
	int** pp = p;

	func(pp);
	Share
	Improve this answer
	Follow
	answered Jun 1 '19 at 18:20

	Money Oriented Programmer
	4,64755 gold badges2626 silver badges6161 bronze badges
	add a comment

	0

	In the case you want to pass a dynamic sized 2-d array to a function, using some pointers could work for you.

	void func1(int *arr, int n, int m){
	...
	int i_j_the_element = arr[i * m + j];  // use the idiom of i * m + j for arr[i][j] 
	...
	}

	void func2(){
	...
	int arr[n][m];
	...
	func1(&(arr[0][0]), n, m);
	}
	Share
	Improve this answer
	Follow
	answered Jul 18 '19 at 7:18

	Purusharth Verma
	3633 bronze badges
	add a comment

	0

	You are allowed to omit the leftmost dimension and so you end up with two options:

	void f1(double a[][2][3]) { ... }

	void f2(double (*a)[2][3]) { ... }

	double a[1][2][3];

	f1(a); // ok
	f2(a); // ok 
	This is the same with pointers:

	// compilation error: cannot convert ‘double (*)[2][3]’ to ‘double***’ 
	// double ***p1 = a;

	// compilation error: cannot convert ‘double (*)[2][3]’ to ‘double (**)[3]’
	// double (**p2)[3] = a;

	double (*p3)[2][3] = a; // ok

	// compilation error: array of pointers != pointer to array
	// double *p4[2][3] = a;

	double (*p5)[3] = a[0]; // ok

	double *p6 = a[0][1]; // ok
	*/

} // resume