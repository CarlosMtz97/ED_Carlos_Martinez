/*
 * vector.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "exception.h"
#include <sstream>

template <class T>
class Vector {
private:
	unsigned int size;
	T	*data;

public:
	Vector(unsigned int) throw (RangeError,OutOfMemory);
	Vector(unsigned int, T&) throw (RangeError, OutOfMemory);
	Vector(const Vector<T>&) throw (OutOfMemory);
	~Vector();

	unsigned int length() const;
	unsigned int resize(unsigned int) throw (RangeError, OutOfMemory);
	unsigned int resize(unsigned int, T&) throw (RangeError, OutOfMemory);
	std::string toString() const;

	T& operator[](unsigned int) const throw (IndexOutOfBounds);
	void operator=(const Vector<T>&);
};

template <class T>
Vector<T>::Vector(unsigned int numberOfElements) throw (RangeError, OutOfMemory) {
	if(numberOfElements == 0)
		throw RangeError();
	size = numberOfElements;
	data = new T[size];
	if(data == 0)
		throw OutOfMemory();
}

template <class T>
Vector<T>::Vector(unsigned int numberOfElements, T &initialValue) throw (RangeError, OutOfMemory) {
	if(numberOfElements == 0)
		throw RangeError();
	size = numberOfElements;
	data = new T[size];
	if(data == 0)
		throw OutOfMemory();
	for(unsigned int i =0; i < size; i++){
		data[i] = initialValue;
	}
}

template <class T>
Vector<T>::Vector(const Vector<T> &source) throw (OutOfMemory) {
	size = source.size;
	data = new T[size];
	if(data == 0)
		throw OutOfMemory();
	for(unsigned int i=0; i<size; i++){
		data[i] = source.data[i];
	}
}

template <class T>
Vector<T>::~Vector() {
	delete [] data;
	data = NULL;
	size = 0;
}

template <class T>
unsigned int Vector<T>::length() const {
	return size;
}

template <class T>
unsigned int Vector<T>::resize(unsigned int newSize) throw (RangeError, OutOfMemory) {
	if (newSize == 0){
    throw RangeError();
  }

  // Crear nuevo vector temporal
  T *newData = new int[newSize];

  if(newData == 0){
		throw OutOfMemory();
  }

  // Copiar los valores del vector actual al temporal
  unsigned int limit = newSize;
  if (newSize >= size){
    limit = size;
  }
  for(unsigned int i = 0; i < limit; i++){
   newData[i] = data[i];
  } 

  // Borrar datos de vector actual
  delete [] data;

  data = newData;
  size = newSize;
  return 0;
}

template <class T>
unsigned int Vector<T>::resize(unsigned int newSize, T &initValue) throw (RangeError, OutOfMemory) {
  if (newSize == 0){
    throw RangeError();
  }

  // Crear nuevo vector temporal
  T *newData = new int[newSize];

  if(newData == 0){
		throw OutOfMemory();
  }

  // Copiar los valores del vector actual al temporal
  unsigned int i;
  for(i = 0; i < size; i++){
    newData[i] = data[i];
  } 
  if (newSize > size){
    for(i = size; i < newSize ; i++ ){
      newData[i] = initValue;
    }
  } 

  // Borrar datos de vector actual
  delete [] data;

  data = newData;
  size = newSize;
  return 0;
}

template <class T>
std::string Vector<T>::toString() const {
	std::stringstream aux;

	aux << "[" << data[0];
	for (unsigned int i = 1; i < size; i++) {
		aux << ", " << data[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
T& Vector<T>::operator[] (unsigned int index) const throw (IndexOutOfBounds) {
  if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}
	return data[index];
}

template <class T>
void Vector<T>::operator=(const Vector<T> &right) {
	if (size != right.size) {
	  resize(right.size);
	}
	for (unsigned int i = 0; i < right.size; i++) {
		data[i] = right.data[i];
	}
}

#endif /* VECTOR_H_ */