#include "std_lib_facilities.h"

template<typename T, typename A>
struct vector_base {
    A alloc; 			                            	        
    T* elem; 				                                   
    int sz; 				                                    
    int space;			                                      
    vector_base(const A& a, int n)                      
    : alloc{a}, elem{alloc.allocate(n)}, sz{n}, space{n}{ }
    ~vector_base() { alloc.deallocate(elem,space); }
};

template<typename T, typename A = allocator<T>>
class our_vector : vector_base<T,A> {

public:

	our_vector() {this->sz = 0; this->elem = nullptr; this->space=0};				//Default Constructor

	explicit our_vector(size_t s) { 	//Normal Constructor
		this->sz = s;
        this->elem = this->alloc.allocate(s);
        this->space = s;
        for (T* p = this->elem; p != this->elem + s; p++)
			this->alloc.construct(p, T());
	}

	our_vector(const our_vector<T, A>& vec);					//Copy constructor

	our_vector<T, A>& operator=(const our_vector<T, A>& vec);
        our_vector(our_vector<T, A>&& vec);						    //Move Constructor
	    our_vector<T, A>& operator=(our_vector<T, A>&& vec);			//Copy Assignment

	~our_vector() {									//Destructor
		for (int i = 0; i < this->sz; ++i) 						
			this->alloc.destroy(&this->elem[i]);
		this->alloc.deallocate(this->elem, this->space);
	}

	T& operator[](int n) { return this->elem[n]; }				
	    int size() const { return this->sz; };
	    void print();
	    void reserve(int newalloc);					

    void new_reserve(int newalloc);                              //---------------NEW ADDED FOR TESTING---------
	    int capacity() const { return this->space; }
	    void resize(int newsize, T val = T());
	    void push_back(T& val);
	    T& at(int n) {
		    if (n < 0 || this->sz < n)
			    throw std::out_of_range("Out of range!");
		    return this->elem[n];
	}
	int size() const { return this->sz; };

	void print();

	void reserve(int newalloc);

	int capacity() const { return this->space; }

	void resize(int newsize, T val = T());

	void push_back(T& val);

	T& at(int n) {
		if (n < 0 || this->sz < n)
			throw std::out_of_range("It is out of range access!");
		return this->elem[n];
	}
};

template<typename T, typename A> our_vector<T, A>::our_vector(const our_vector<T, A>& vec) : sz{ vec.sz }, elem{ alloc.allocate(sz) }, space{ vec.sz } {	//Copy constructor
	this->sz = vec.sz;
    this->elem = this->alloc.allocate(this->sz);
    this->space = vec.sz;
    copy(vec.elem, vec.elem + this->sz, this->elem);
}

template<typename T, typename A> our_vector<T, A>& our_vector<T, A>::operator=(const our_vector<T, A>& vec) {
	if (this == &vec)
		return *this;
	if (vec.sz <= this->space) {								//never decrease deallocation
		copy(vec.elem, vec.elem + vec.sz, this->elem);
		/*for (int i = 0; i < vec.sz; i++)
			elem[i] = vec.elem[i];*/
		for (int i = vec.sz; i < this->sz; ++i) 
			this->alloc.destroy(&this->elem[i]);
		this->sz = vec.sz;
		return *this;
	}

	T* p = this->alloc.allocate(vec.sz); 							// allocate new space
	copy(vec.elem, vec.elem + vec.sz, p); 						// copy elements
	for (int i = 0; i < this->sz; ++i) 							// deallocate old space
		this->alloc.destroy(&this->elem[i]);
	this->alloc.deallocate(this->elem, space);
	this->space = this->sz = vec.sz;
	this->elem = p; 									// now we can reset elem
	return *this; 									// return a self-reference
}

template<typename T, typename A> our_vector<T,A>::our_vector(our_vector<T, A>&& vec) {		//Move Constructore
	this->sz = vec.sz;
    this->elem = vec.elem;
    this->space =vec.space;
    vec.sz = 0;
	vec.elem = nullptr;
}

template<typename T, typename A> our_vector<T, A>& our_vector<T, A>::operator=(our_vector<T, A>&& vec) {		//Move Assignment
	for (int i = 0; i < sz; ++i) 											// deallocate old space
		this->alloc.destroy(&this->elem[i]);
	this->alloc.deallocate(this->elem, this->space);
	this->elem = vec.elem; 			// copy a’s elem and sz
	this->sz = vec.sz;
	this->space = vec.space;
	vec.elem = nullptr; 		// make a the empty vector
	vec.sz = 0;
	return *this; 			// return a self-reference
}

template<typename T, typename A> void our_vector<T,A>::reserve(int newalloc) {
    if (newalloc <= this->space) return;
    vector_base<T,A> b(this->alloc,newalloc);
    uninitialized_copy(b.elem, &b.elem[this->sz], this->elem);
    for(int i=0; i<this->sz; ++i)
        this->alloc.destroy(&this->elem[i]);
    swap<vector_base<T,A>>(*this,b);		
}

//following reserve template from slide 44
template<typename T, typename A> void our_vector<T, A>::resize(int newsize, T val) {
	reserve(newsize);
	for (int i = this->sz; i < newsize; i++)
		alloc.construct(&elem[i], val);
	for (int i = newsize; i < this->sz; i++)
		this->alloc.destroy(&this->elem[i]);
	this->sz = newsize;
}

template<typename T, typename A> void our_vector<T, A>::push_back(T& val) {  		//increase vector size by one; initialize the new element with d
	if (this->space == 0)
		reserve(8); 								// start with space for 8 elements
	else if (this->sz == this->space)
		reserve(2 * this->space); 							// get more space
	this->alloc.construct(&this->elem[sz], val);
	++this->sz; 										// increase the size (sz is the number of elements)
}

template<typename T, typename A> void our_vector<T, A>::print() {
	for (int i = 0; i < this->sz; i++) {
		cout << this->elem[i] << " ";
	}
	cout << endl;
}

int main() {
	try {
		our_vector<string> p(2);
		p[0] = "first";
		p[1] = "second";

		cout << p.at(3)<< endl;
	}
	catch(out_of_range e){
		cout << e.what() << endl;
	}
	
	our_vector<double>* n_p = new our_vector<double>();
	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;

	n_p->resize(10);
	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;

	double x = 2;
	n_p->push_back(x);

	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;
	n_p->print();

	//Copy check
	our_vector<double>* copy_p(n_p);
	cout << copy_p->size() << endl;
	cout << copy_p->capacity() << endl;
	copy_p->print();

	our_vector<double>* copy_assign = copy_p;
	cout << copy_assign->size() << endl;
	cout << copy_assign->capacity() << endl;
	copy_assign->print();
		


	return 0;
}
