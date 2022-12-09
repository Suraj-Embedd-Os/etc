
#include<iostream>

using namespace std;

 enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

 class Mammal
 {
	 public:
	 // constructors
	 Mammal();
	 ~Mammal();

	 //accessors
	 int GetAge() const {return itsAge;}
	 void SetAge(int age) {itsAge=age;}
	 int GetWeight() const{return itsWeight;}
	 void SetWeight(int weight) {itsWeight=weight;}

	 //Other methods
	 void Speak() const {cout<<"mammal speek \n";}
	 void Sleep() const {cout<<"I m Sleeping \n";}
	 
	 void Move() {cout<<"Mammal move 1 step \n";}
	 void Move(int distance) {cout<<"Mammal move "<<distance<<" step \n";}


	 protected:
	 int itsAge;
	 int itsWeight;
 };
 
class Dog : public Mammal
{
	public:
	Dog();
	~Dog();
	
	BREED GetBread()const {return itsBread;}
	void SetBread(BREED bread) {itsBread=bread;}
	
	// Other methods
	 void WagTail() const {cout<<"Dog wagtail\n";}
	 void BegForFood() const {cout<<"BegForFood\n";}
	 
	 void Move() {cout<<"Dog move 1 step \n";}
	
	
	protected:
	BREED itsBread;
};


int main()
{
		Dog Fido;
		Fido.Speak();
		Fido.WagTail();
		Fido.Move();
		Fido.Mammal::Move(10);
		return 0;
}


Mammal::Mammal():itsAge(2),itsWeight(5){
	cout<<"Mammal constructor called\n";
}
Mammal::~Mammal(){
	cout<<"Mammal destructor called\n";
}


Dog::Dog():itsBread(GOLDEN) {
	cout<<"Dog constructor called\n";
}
Dog::~Dog(){
	cout<<"Dog constructor called\n";
}



