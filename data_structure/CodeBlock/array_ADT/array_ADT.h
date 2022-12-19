#ifndef ARRAY_ADT_H_INCLUDED
#define ARRAY_ADT_H_INCLUDED
using namespace std;

template <class T>
class array
{
private:
    T *dataPtr;
    int size;
    int lenght;

public:
    array(int _size);
    ~array() { delete [] dataPtr;}

    void display();
    void add(T data);
    void insert(T data,int index);
    void delete_array(int index);
    void delete_index(int index);
    int search(T data);
    T get(int index);
    void set(int index,T data);
    T max();
    T min();
    void reverse();
    void shift(int pos,int direction);
    void rotate(int pos);
    bool isoverflow()
    {
        return (lenght+1==size);
    }

    bool isunderflow()
    {
        return lenght ==-1;
    }
};



template <class T>array<T>::array(int _size)
{
    this->dataPtr = new T[_size];
    this->size=_size;
    this->lenght=-1;
}

template <class T> void array<T>::display()
{
    if(isunderflow())
    {
        cout<<"Under flow"<<endl;
        return;
    }
    for(int i=0;i<this->lenght+1;i++)
        cout<<dataPtr[i]<<" ";
    cout<<endl;
}

template <class T> void array<T>::add(T data)
{
    if(isoverflow())
    {
        cout<<"over flow "<<endl;
        return;
    }

    lenght++;
    this->dataPtr[lenght]=data;

}

template <class T> void array<T>::insert(T data,int index)
{
    if(isoverflow())
    {
        cout<<"over flow "<<endl;
        return;
    }
    if(index<this->size-1)
    {
        int i;
        for(i=this->lenght+1;i>index;--i)
        {
            dataPtr[i]=dataPtr[i-1];
        }
        this->dataPtr[i]=data;
        this->lenght++;
    }
}

template <class T> void array<T>::delete_index(int index)
{
    if(isunderflow())
    {
        cout<<"under flow "<<endl;
        return;
    }
    if(index<this->lenght)
    {
        for(int i=index;i<this->lenght;i++)
            this->dataPtr[i]=dataPtr[i+1];
        this->lenght--;
    }
}

template <class T> void array<T>::delete_array(int index)
{
     delete [] dataPtr;
}

template <class T> int array<T>::search(T data)
{
    bool found=false;
    int index=-1;
    for(int i=0;i<=this->lenght;i++)
    {
        if(this->dataPtr[i]==data)
        {
             found=true;
             index=i;
             break;
        }

    }
    if(found)
        cout<<"found at index "<<index<<endl;
     return index;
}


template <class T> T array<T>::get(int index)
{
    if(index>this->lenght)
    {
        cout<<"Not valid index"<<endl;
        return;
    }
    return this->dataPtr[index];
}

template <class T> void array<T>::set(int index,T data)
{
    if(index>this->lenght)
    {
        cout<<"Not valid index"<<endl;
        return;
    }
    this->dataPtr[index]=data;
}

template <class T> T array<T>::max()
{

}

template <class T> T array<T>::min()
{

}

template <class T> void array<T>::reverse()
{
    for(int i=0,j=this->lenght;i<j;i++,j--)
    {
        T tmp=this->dataPtr[i];
        this->dataPtr[i]=this->dataPtr[j];
        this->dataPtr[j]=tmp;
    }
}

template <class T> void array<T>::shift(int pos,int direction)
{
    for(int i=0;i<=lenght;i++)
    {

    }
}

template <class T>
void array<T>::rotate(int pos)
{
    for(int i=0;i<pos;i++)
    {
        T tmp=dataPtr[0];
        for(int j=0;j<this->lenght;j++)
        dataPtr[j]=dataPtr[j+1];

        dataPtr[lenght]=tmp;
    }
}

#endif // ARRAY_ADT_H_INCLUDED
