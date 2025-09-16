#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//introducing new namespace to make my own array class
namespace a {

	// making array templace class
	template<typename T>
	class array {
	private:
		size_t numItems;
		size_t currentCap;
		static const size_t initialCap = 20;
		T* data;
	public:
		int getSize() { return numItems; }

		//  [] operator overload for indexing
		T& operator[](size_t index);

		//constuctor
		array();

		//function that expands array
		void resize(int cap);

		//function checking if thing is in array and returning index
		int isPresent(T value);

		//function adding to end
		void addEnd(T value);

		//function removing item at index
		void removeIndex(int index);

		//funciton modifying val at index and returning both
		void modIndex(int index, int newVal);

	};

	//implementations - they are in header because it is a template

	template<typename T>
	//[] operator definition
	T& a::array<T>::operator[](size_t index) {
		// index validation 
		if (index >= numItems) {
			throw std::out_of_range
			("that index isnt in the array");
		}
		return data[index];
	}

	template<typename T>
	//constructor definition
	a::array<T>::array() {
		data = new T[initialCap];
		currentCap = initialCap;
		numItems = 0;
	}

	template<typename T>
	//resize function implementation
	void a::array<T>::resize(int cap) {
		currentCap = cap;  //resizing cap

		T* newA = new T[currentCap];   //new array of double size
		for (int i = 0; i < numItems; i++) {    //copying data over O(n)
			newA[i] = data[i];
		}
		//clearing space
		delete[] data;
		data = newA;

	}

	template<typename T>
	//function checking if value is in array implementation
	int a::array<T>::isPresent(T value) {
		for (int a = 0; a < numItems; a++) {
			if (data[a] == value) {
				return a;
			}
		}
		return -1;
	}

	template<typename T>
	//function adding to end implementation
	void a::array<T>::addEnd(T value) {
		if (numItems == currentCap) {
			resize(2 * currentCap);
		}
		data[numItems] = value;
		numItems++;

		/*try {
			data[numItems] = value;
		}
		catch (...) {
			if (numItems == currentCap) {
				resize(2 * currentCap);
			}
			data[numItems] = value;
		}
		numItems++;*/
		
	}

	template<typename T>
	//function removing item at an index implementation
	void a::array<T>::removeIndex(int index) {
		if (index < 0 || index >= numItems) {
			throw std::out_of_range
			("index to remove is not valid");
			return;
		}
		for (int i = index + 1; i < numItems; i++) {
			data[i - 1] = data[i];
		}
		numItems--;
	}

	template<typename T>
	//funciton modifying val at index and returning both implementation
	void a::array<T>::modIndex(int index, int newVal) {
		//checking index validity
		if (index < 0 || index >= numItems) {
			std::cout << "item index to modify is not valid" << std::endl;
		}
		//replacing the index with new val
		int temp = data[index];
		data[index] = newVal;

		//printing out both elements
		std::cout << "Index " << index << " replaced. " << temp << " is now " << data[index] <<"."<< std::endl;

	}


}
