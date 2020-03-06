#ifndef QS_H
#define QS_H

#include <iostream>
#include <string>
#include "QSInterface.h"

using namespace std;

class QS : public QSInterface {
    
private:
    int *array = NULL;
    int numItems = 0;
    int arrayCapacity = 0;
public:
    QS();
	~QS();

	void sortAll();
    
    int medianOfThree(int left, int right);
	
	int partition(int left, int right, int pivotIndex);
	
	string getArray() const;

	int getSize() const;

	bool addToArray(int value);
	
	bool createArray(int capacity);

	void clear();
	
	void quicksort(int left, int right);
};
#endif