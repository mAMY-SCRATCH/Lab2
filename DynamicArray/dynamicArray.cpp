#include "dynamicArray.h"
#include <stdexcept>
#include <algorithm>

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
	if (_capacite < 1)
	{
		throw std::invalid_argument("capacite de un minimum");
	}
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
		throw std::out_of_range ("out of range");
	}
}

void DynamicArray::setElement(unsigned _index, int _valeur)
{
	
	if (_index >= capacite)
	{
		setCapacite(_index + 1);
	}
	tabElements[_index] = _valeur;
}

void DynamicArray::setCapacite(unsigned _capacite)
{
	if (_capacite < 1)
	{
		throw std::invalid_argument("capacite de un minimum");
	}

	int * newTabElement = new int[_capacite];

	for (unsigned int j = 0; j < _capacite; j++)
	{
		newTabElement[j] = 0;
	}
	
	for (unsigned int i = 0; i < std::min(capacite,_capacite); i++)
	{
		newTabElement[i] = tabElements[i];
	}
	
	
	capacite = _capacite;
	delete[]tabElements;
	tabElements = newTabElement;
	

}