#include <iostream>
#include <string>
using namespace std;

struct address {
	string name;
	int streetNumber;
	string street;
	string city;
	string province;
	string postalCode;
};

// All three of these functions work.  But, you must supply a reference
// to the third function.  Note the different membership operators.
// Passing by value.
void printAddressVal(address a) {
	a.name = "Hee Hee!";
	cout << a.name << " lives at: "
		 << a.streetNumber << " " << a.street << ", "
		 << a.city << ", " << a.province << ", " << a.postalCode << endl;
}

// Passing by reference and then by constant reference.
void printAddress(address& a) {
	a.name = "Hah Hah!";
	cout << a.name << " lives at: "
		 << a.streetNumber << " " << a.street << ", "
		 << a.city << ", " << a.province << ", " << a.postalCode << endl;
}

// The -> dereferences before obtaining membership, since a is a pointer.
// Passing a pointer, then a pointer to constant and then a constant pointer.
void printAddressPtr(address* a) {
	a->name = "Ho Ho!";
	cout << "Pointer in function: " << a << endl;
	cout << a->name << " lives at: "
		 << a->streetNumber << " " << a->street << ", "
		 << a->city << ", " << a->province << ", " << (*a).postalCode << endl; // Demonstrating that (*a). is the same as a->
	a += 1; // Can I change the pointer?
	cout << "Pointer in function, again: " << a << endl;
}

int main() {

	// Normal C++ initialization:
	//address addr1 = {"Joe Shmoe", 29, "Endless Rd.", "Nowhere", "ON", "N0N 0N0"};
	// C++11 initialization:
	address addr1{"Joe Shmoe", 29, "Endless Rd.", "Nowhere", "ON", "N0N 0N0"};
	printAddressVal(addr1);
	cout << addr1.name << endl;
	printAddress(addr1);
	cout << addr1.name << endl;
	printAddressPtr(&addr1);
	cout << addr1.name << endl;

	// Showing another, lengthier way of assigning struct members:
/*	address addr2;
	addr2.name = "Jane Doe";
	addr2.streetNumber = 345;
	addr2.street = "Doe Lane";
	addr2.city = "Somewhere";
	addr2.province = "BC";
	addr2.postalCode = "B0B 0B0";
	printAddress(addr2);
	printAddressPtr(&addr2);

	cout << addr2.name << endl;
*/
	return 0;
}



