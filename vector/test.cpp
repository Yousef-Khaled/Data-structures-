/*
 * Author: Ahmed Fahmy
 * Date: 27/1/2015 11:00 PM
 * test for vector interface
 */

#include "myvector.h"
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

void testMvector() {
	mvector<int> v;
	assert(v.size() == 0);
	assert(v.empty());

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	assert(v.size() == 4);
	assert(v.capacity() >= v.size());

	v.shrink_to_fit();
	assert(v.capacity() == v.size());

	assert(*v.begin() == 10);
	assert(*(v.end()-1) == 40);

	v.push_front(0);
	assert(*v.begin() == 0);

	v.insert(5, 1);
	assert(v[1] == 5);

	int sz = v.size();
	v.pop_front();
	assert(*v.begin() == 5);
	assert(sz - v.size() == 1);

	sz = v.size();
	assert(*(v.end()-1) == v.pop_back());
	assert(sz - v.size() == 1);

	v.erase(0);
	assert(sz - v.size() == 2);

	v.clear();
	assert(v.size() == 0);

	mvector<int> sizeAndInit(10, 1);
	assert(sizeAndInit.size() == 10);
	assert(sizeAndInit[0] == sizeAndInit[9]);

	mvector<int> copyConstructor(sizeAndInit);
	assert(copyConstructor.size() == 10);
	assert(copyConstructor[0] == 1);
	assert(copyConstructor[1] == 1);

	copyConstructor[0]++;
	copyConstructor.swap(sizeAndInit);
	assert(copyConstructor[0] == 1);
	assert(sizeAndInit[0] == 2);

	mvector<int> assign;
	assign = copyConstructor;
	assert(&assign[0] != &copyConstructor[0]);

}

int main() {
	testMvector();
	cout << "3aaa4 ! (Y)\n";
}
