//
//  DynamicArray.h
//  Raytracer
//
//  Created by Narendra Umate on 3/30/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__DynamicArray__
#define __Raytracer__DynamicArray__

template <class T>
class DynamicArray
{
	DynamicArray();
	DynamicArray(const int &size);
	~DynamicArray();

	bool append(const T& item);	// always add to end
	bool truncate();		// make arraysize = nData
	void clear();
	int length() const;
	bool empty() const;
	const T& operator[](const int& i) const;
	T& operator[](const int& i);

	T* data;
	int datasize;
	int arraysize;
};

template <class T>
DynamicArray<T>::DynamicArray()
{
	datasize = 0;
	arraysize = 1;
	data = new T[arraysize];
}

template <class T>
DynamicArray<T>::DynamicArray(const int &size)
{
	datasize = 0;
	arraysize = size;
	data = new T[arraysize];
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
	datasize = 0;
	arraysize = 0;
	delete [] data;
}

template <class T>
bool DynamicArray<T>::append(const T& item)
{
	if (datasize == arraysize)
	{
		T* temp = data;
		arraysize *= 2;
		if (!(data = new T[arraysize]))
		{
			return false;
		}

		for (int i = 0; i < datasize; i++)
		{
			data[i] = temp[i];
		}

		delete [] temp;
	}
	data[datasize++] = item;
	return true;
}

template <class T>
bool DynamicArray<T>::truncate()
{
	if (datasize != arraysize)
	{
		T* temp = data;
		arraysize = datasize;
		if (!(data = new T[arraysize]))
		{
			return false;
		}

		for (int i = 0; i < datasize; i++)
		{
			data[i] = temp[i];
		}

		delete [] temp;
	}
	return true;
}

template <class T>
void DynamicArray<T>::clear()
{
	datasize = 0;
}

template <class T>
int DynamicArray<T>::length() const
{
	return datasize;
}

template <class T>
bool DynamicArray<T>::empty() const
{
	return datasize == 0;
}

template <class T>
const T& DynamicArray<T>::operator[](const int& i) const
{
	return data[i];
}

template <class T>
T& DynamicArray<T>::operator[](const int& i)
{
	return data[i];
}

#endif /* defined(__Raytracer__DynamicArray__) */
