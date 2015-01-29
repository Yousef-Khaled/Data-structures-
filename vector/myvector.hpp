#include "myvector.h"

template<class type>
mvector<type>::mvector() {
	siz = 0;
	cap = 10;
	vec = new type[cap];
}

template<class type>
mvector<type>::mvector(int SIZ) {
	siz = SIZ;
	cap = SIZ;
	vec = new type[siz];

}

template<class type>
mvector<type>::mvector(int SIZ, type data) {
	siz = SIZ;
	cap = SIZ;
	vec = new type[siz];
	for (int i = 0; i < siz; i++)
		vec[i] = data;
}
template<class type>
mvector<type>::mvector(mvector<type> & other) {
	siz = other.siz;
	cap = other.cap;
	vec = new type[cap];
	for (int i = 0; i < siz; i++)
		vec[i] = other.vec[i];
}
template<class type>
mvector<type>::~mvector() {
	delete[] vec;
}
template<class type>
int mvector<type>::size() {
	return siz;
}
template<class type>
int mvector<type>::capacity() {
	return cap;
}
template<class type>
bool mvector<type>::empty() {
	return !siz;
}
template<class type>
type* mvector<type>::begin() {
	if (!siz) {
		cout << "Vector is empty ()" << endl;
		return 0;
	} else {
		type* p = &vec[0];
		return p;
	}
}
template<class type>
type* mvector<type>::end() {
	if (!siz) {
		cout << "Vector is empty ()" << endl;
		return 0;
	} else
		return vec + siz;
}
template<class type>
void mvector<type>::push_front(type data) {
	if (siz < cap) {
		for (int i = siz; i > 0; i--) {

			type temp = vec[i];
			vec[i] = vec[i - 1];
			vec[i - 1] = temp;
		}
		vec[0] = data;
		siz++;
	}
	if (siz == cap) {
		siz++;
		cap *= 2;
		type * temp = new type[siz];
		for (int i = 1; i < siz; i++)
			temp[i] = vec[i - 1];

		temp[0] = data;

		delete[] vec;

		vec = new type[cap];

		for (int i = 0; i < siz; i++) {
			vec[i] = temp[i];
		}
		delete[] temp;
	}

}
template<class type>
void mvector<type>::push_back(type data) {
	if (siz < cap) {
		vec[siz] = data;
		siz++;
	}

	if (siz == cap) {
		cap *= 2;
		siz++;
		type *temp = new type[siz];
		for (int i = 0; i < siz - 1; i++) {
			temp[i] = vec[i];
		}
		temp[siz - 1] = data;

		delete[] vec;

		vec = new type[cap];

		for (int i = 0; i < siz; i++) {
			vec[i] = temp[i];
		}

		delete[] temp;
	}
}
template<class type>
void mvector<type>::shrink_to_fit() {
	cap = siz;
}
template<class type>
void mvector<type>::resize(int SIZ) {

	if (SIZ <= cap) {
		siz = SIZ;
	} else {
		cap = 2 * SIZ;
		type* temp = new type[siz];
		for (int i = 0; i < siz; i++) {
			temp[i] = vec[i];
		}
		delete[] vec;
		vec = new type[cap];
		for (int i = 0; i < siz; i++) {
			vec[i] = temp[i];
		}
		siz = SIZ;
	}
}
template<class type>
void mvector<type>::clear() {
	siz = 0;
}
template<class type>
int mvector<type>::find(type target) {
	for (int i = 0; i < siz; i++) {
		if (vec[i] == target)
			return i;
	}
	return -1;
}
template<class type>
void mvector<type>::swap(mvector<type> &other) {

	type *temp = new type[other.siz];
	int SIZ = other.siz;

	for (int i = 0; i < other.siz; i++)
		temp[i] = other.vec[i];

	delete[] other.vec;

	other.vec = new type[siz];

	other.siz = siz;

	for (int i = 0; i < siz; i++)
		other.vec[i] = vec[i];

	delete[] vec;

	siz = SIZ;

	vec = new type[siz];

	for (int i = 0; i < siz; i++)
		vec[i] = temp[i];

	delete[] temp;
}
template<class type>
type mvector<type>::pop_back() throw (out_of_range) {
	out_of_range s("out of range vector is empty!");

	if (!siz)
		throw s;
	else {
		siz--;
		return vec[siz];
	}
}
template<class type>
type mvector<type>::pop_front() throw (out_of_range) {
	out_of_range s("out of range vector is empty!");

	if (!siz)
		throw s;
	else {
		for (int i = 0; i < siz - 1; i++) {
			type temp = vec[i];
			vec[i] = vec[i + 1];
			vec[i + 1] = temp;
		}
		siz--;
		return vec[siz];
	}
}
template<class type>
type mvector<type>::erase(int index) throw (out_of_range) {
	out_of_range s("Wrong index");

	if (index < 0 || index >= siz)
		throw s;
	else {
		for (int i = index; i < siz - 1; i++) {
			type temp = vec[i];
			vec[i] = vec[i + 1];
			vec[i + 1] = temp;
		}
		siz--;
		return vec[siz];
	}

}
template<class type>
type& mvector<type>::operator [](int index) throw (out_of_range) {
	out_of_range s("Wrong index");

	if (index < 0 || index >= siz)
		throw s;
	else {
		return vec[index];
	}

}
template<class type>
mvector<type> & mvector<type>::operator =(mvector<type> &other) {
	delete[] vec;
	siz = other.siz;
	cap = other.cap;
	vec = new type[cap];
	for (int i = 0; i < siz; i++)
		vec[i] = other.vec[i];
	return *this;
}
template<class type>
void mvector<type>::insert(type data, int index) throw (out_of_range) {
	out_of_range s("out of range");

	if (index < 0 || index > siz) {
		throw s;
	}
	if (siz < cap) {
		for (int i = index; i < siz; i++) {
			type temp = vec[i];
			vec[i] = vec[i + 1];
			vec[i + 1] = temp;
		}
		vec[index] = data;
		siz++;
	}
	if (siz == cap) {
		siz++;
		cap *= 2;
		int it = 0;
		type * temp = new type[siz];
		for (int i = 0; i < siz - 1; i++) {
			if (i != index) {
				temp[i] = vec[it];
				it++;

			}
		}
		temp[index] = data;
		delete[] vec;
		vec = new type[siz];
		for (int i = 0; i < siz; i++)
			vec[i] = temp[i];

		delete[] temp;
	}

}
