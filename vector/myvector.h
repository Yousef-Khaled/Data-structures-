#ifndef MVECTOR_H
#define MVECTOR_H

#include<cstdlib>
#include<stdexcept>
#include <iostream>
#include <algorithm>

using namespace std;

template<class type>
class mvector {
private:
	type *vec;
	int siz;
	int cap;
public:
	mvector(); // done
	mvector(int SIZ); // done
	mvector(int SIZ, type data); // done
	// DEEP copy constructor
	mvector(mvector<type> &other); //done
	~mvector(); // done
	int size(); // done
	int capacity(); //done
	bool empty(); // done
	// change the size of the vector
	void resize(int SIZ); //done
	// change the capacity of the vector to be exactly equal to its current size
	void shrink_to_fit(); //done
	// return a pointer to the first element
	type* begin(); //done
	// return a pointer AFTER the last element
	type* end(); //done

	void push_front(type data); //done
	void push_back(type data); //done
	void insert(type data, int index) throw (out_of_range);

	type pop_front() throw (out_of_range); //done
	type pop_back() throw (out_of_range); //done
	type erase(int index) throw (out_of_range); //done
	void clear(); // done

	//swap this vector with the parameter vector
	void swap(mvector<type> &other); // done
	// find an element in the vector and return its index, return -1 if not found
	int find(type target); // done

	type& operator[](int index) throw (out_of_range); //done
	// DEEPLY copy the parameter vector into this vector
	mvector<type> & operator=(mvector<type> &other); // done
};
#include "myvector.hpp"

#endif
