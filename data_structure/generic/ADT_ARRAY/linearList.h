
#ifndef __LINEARLIST_H
#define __LINEARLIST_H

#include<iostream>
#include<sstream>

template<class T>
class linearList
{
	public:
	virtual ~linearList(){}
	virtual bool empty() const=0;
		//return true if empty
	virtual int size() const=0;
		// return number of element in list
	virtual T& get(int theIndex)const =0;
		//return element whose index is theIndex
	virtual int indexOf(const T& theElement)const=0;
		//return index of first occurance of theElement
	virtual void erase(int theIndex)=0;
		//Remove the element whose index is theIndex
	virtual void insert(int theIndex,const T& theElement) =0;
		//insert theElement so that its index is theIndex
	virtual void output() const=0;
		//insert list into stream out
	
};

template<class T>
class arrayList :public linearList<T>
{
	public:
		arrayList(int initialCapacity=10);
		arrayList(const arrayList<T>&);
		~arrayList() { delete [] element ;}
		
		//ADT Method
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
	void checkIndex(int theIndex) const;
	    //Throw illegal if index is not valid
	void copy(T *start,T *end,T *copyElement)
	{
		while(start!=end)
		{
			*copyElement=*start;
			copyElement++;
			start++;
		}
			
	}
		
	T* element;			//1D array
	int arrayLenght;	//capacity of array
	int listSize;		//list in the array
	
};

/*
Defaut constructor 

*/

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
	if(initialCapacity<1)
	{
		std::ostringstream s;
		s<<"Initial capacity "<<initialCapacity<<" must be >0 ";
	//	throw illegalParameterValue(s.str());
	}
	arrayLenght=initialCapacity;
	listSize=0;
	element = new T[arrayLenght];
}

/*
    copy constructor
*/

template<class T>
arrayList<T>::arrayList(const arrayList<T> & theList)
{
	arrayLenght=theList.arrayLenght;
	listSize=theList.listSize;
	
	element = new T[arrayLenght];
	copy(theList.element,theList.element+listSize,element);
}



/*
    	//return true if empty
*/
template<class T>
bool arrayList<T>::empty() const
{
    return listSize==0;
}

/*
    // return number of element in list
*/

template<class T>	
int arrayList<T>::size() const
{
    return listSize;
}


/*
    //return element whose index is theIndex

*/

		
template<class T>
T& arrayList<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    return element[theIndex];
}
		
/*
    //return index of first occurance of theElement
    
*/


template<class T>
int arrayList<T>::indexOf(const T& theElement)const
{
   
    for(int i=0;i<listSize;i++)
    {
        if(element[i]==theElement)
        return i;
    }
    return -1;
}
	
/*
    //Remove the element whose index is theIndex

*/
		
template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    
    for(int i=theIndex;i<listSize-1;i++)
    {
        element[i]=element[i+1];
    }
   listSize--;
}
		
/*
	//insert theElement so that its index is theIndex
*/

template<class T>
void arrayList<T>::insert(int theIndex,const T& theElement)
{
     checkIndex(theIndex);
	 
	  for(int i=listSize-1;i>=theIndex;i--)
		{
			element[i+1]=element[i];
		}
		element[theIndex]=theElement;
		listSize++;
}
	
/*
    //insert list into stream out
*/

template<class T>
void arrayList<T>::output() const
{
    for(int i=0;i<listSize;i++)
	{
		std::cout<<element[i]<<" ";
	}
	std::cout<<std::endl;
}
	

/*
     //Throw illegal if index is not valid
*/

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
   if(theIndex <0 || theIndex>listSize )
   {
       std::ostringstream s;
       s<<" index "<<theIndex<<" size "<<listSize;
      // throw illegalParameterValue(s.str());
      std::cout<<"index "<<theIndex<<" size "<<listSize<<" illegal Index\n";
      exit(-1);
   }
}




#endif