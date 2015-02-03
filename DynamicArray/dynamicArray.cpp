#include "dynamicArray.h"
#include <stdexcept>

DynamicArray::DynamicArray()
{
	this->capacite = 100;
	tabElements = new int[capacite];
	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

DynamicArray::DynamicArray(int _capacite)
{
	this->capacite = _capacite;
	tabElements = new int[capacite];
	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

int DynamicArray::getCapacite()
{
	return capacite;
}

int DynamicArray::getElement(int i)
{
	if (i <= capacite)
	{
		return tabElements[i];
	}
	else
	{
		throw std::out_of_range ("blah");
	}
}

void DynamicArray::setElement(unsigned _index, int _valeur)
{
	
	if (_index > capacite)
	{
		int * newTabElement = new int[_index];
		for (unsigned int i = 0; i < capacite; i++)
		{
			newTabElement[i] = tabElements[i];
		}
		
		tabElements = newTabElement;
		delete[]newTabElement;
	}
	tabElements[_index] = _valeur;
}

void DynamicArray::setCapacite(unsigned _capacite)
{
	int * newTabElement = new int[_capacite];
	for (unsigned int j = 0; j < _capacite; j++)
	{
		newTabElement[j] = 0;
	}
	if (capacite <= _capacite)
	{
		for (unsigned int i = 0; i < capacite; i++)
		{
			newTabElement[i] = tabElements[i];
		}
	}
	else
	{
		for (unsigned int i = 0; i < _capacite; i++)
		{
			newTabElement[i] = tabElements[i];
		}
	}
	
	
	tabElements = newTabElement;
	delete[]newTabElement;

}