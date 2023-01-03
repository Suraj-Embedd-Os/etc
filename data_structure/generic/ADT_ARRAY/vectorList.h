
#include"linearList.h"

template<class T>
class vectorList:public linearList<T>
{
    public:
     bool empty() const;
		//return true if empty
	 int size() const;
		// return number of element in list
	 T& get(int theIndex)const;
		//return element whose index is theIndex
	 int indexOf(const T& theElement)const;
		//return index of first occurance of theElement
	 void erase(int theIndex);
		//Remove the element whose index is theIndex
	 void insert(int theIndex,const T& theElement);
		//insert theElement so that its index is theIndex
	 void output() const;
		//insert list into stream out
	// Additional method
	int capacity()const {return arrayLenght;}
	 
	 protected:
};



