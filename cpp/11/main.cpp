
#include<iostream>

using namespace std;

 enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

 class Mammal
 {
	 public:
	 // constructors
	 Mammal():itsAge(2),itsWeight(5){}
	 ~Mammal(){}

	 //accessors
	 int GetAge() const {return itsAge;}
	 void SetAge(int age) {itsAge=age;}
	 int GetWeight() const{return itsWeight;}
	 void SetWeight(int weight) {itsWeight=weight;}

	 //Other methods
	 void Speak() const {cout<<"mammal speek \n";}
	 void Sleep() const {cout<<"I m Sleeping \n";}


	 protected:
	 int itsAge;
	 int itsWeight;
 };
 
class Dog : public Mammal
{
	public:
	Dog():itsBread(GOLDEN) {}
	~Dog(){}
	
	BREED GetBread()const {return itsBread;}
	void SetBread(BREED bread) {itsBread=bread;}
	
	// Other methods
	 void WagTail() const {cout<<"Dog wagtail\n";}
	 void BegForFood() const {cout<<"BegForFood\n";}
	
	
	protected:
	BREED itsBread;
};


int main()
{
		Dog Fido;
		Fido.Speak();
		Fido.WagTail();
		return 0;
}









