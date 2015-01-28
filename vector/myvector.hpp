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
	if (!siz)
		cout << "Vector is empty ()" << endl;
	else
		return &vec[0];
}
template<class type>
type* mvector<type>::end() {
	if (!siz)
		cout << "Vector is empty ()" << endl;
	else
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
// not finishef yet
