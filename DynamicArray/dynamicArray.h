#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:

	DynamicArray();
	DynamicArray(int _capacite);
	~DynamicArray();
	int getCapacite();
	int getElement(int i);
	void setElement(unsigned int _index, int _valeur);
	void setCapacite(unsigned int _capacite);

private:

	unsigned int capacite;
	int * tabElements;

};


#endif //DYNAMICARRAY_H_