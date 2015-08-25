/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include <iostream>
#include <string>
#include <utility>
using namespace std;
// for swap but we do not provide a using declaration for swap

// HasPtr with added move constructor
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	// default constructor and constructor that takes a string
    HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0) { cout<<"init with string"<<endl; }

	// copy constructor
    HasPtr(const HasPtr &p): 
		ps(new std::string(*p.ps)), i(p.i) {cout<<"init with copy constructor"<<endl; }

	// move constructor
	HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0; cout<<"move constructor "<<endl;}

	// assignment operator is both the move- and copy-assignment operator

	HasPtr& operator=(const HasPtr &rhs) 
  	{ 
		cout<<"copy assign "<<endl; 
		return *this;
   	}


	HasPtr& operator=(HasPtr &&rhs) 
  	{ 
		cout<<"move assign "<<endl; 
		return *this;
   	}
	
	// destructor
	~HasPtr() { delete ps; }
private:
    std::string *ps;
    int    i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
	swap(lhs.i, rhs.i);   // swap the int members
}

void f1(HasPtr p) {
	cout<<"com to value pass fucntion"<<endl;
}

void f2(HasPtr &p) {
	cout<<"come to ref pass function"<<endl;
}

HasPtr f3() {
	HasPtr local("local stroing ");
	cout<<"return local HasPtr to main function from f3 "<<endl;
	return local;
}


string f4() {
	string qq="new qq";
	cout<<"return string from f4"<<endl;
	return qq;
}

HasPtr f5(HasPtr &p) {
	cout<<"return ref HasPtr from f5"<<endl;
	return p;
}


int main()
{
	cout<<endl<<"----line1----- "<<endl;
	HasPtr hp("hi mom");

	cout<<endl<<"----line2----- "<<endl;
	HasPtr hp2(hp);
	
	cout<<endl<<"----line3----- "<<endl;
	hp = hp2; // hp2 is an lvalue; copy constructor used to copy hp2 
//	hp = string("new line"); // hp2 is an lvalue; copy constructor used to copy hp2 
	cout<<endl<<"----line4----- "<<endl;
	hp = std::move(hp); // move constructor moves hp2


	cout<<endl<<"----f1(HasPtr p)----- "<<endl;
	f1(hp);


	cout<<endl<<"----f2(HasPtr p)------ "<<endl;
	f2(hp);


	cout<<endl<<"----f3 return HasPtr----- "<<endl;
	 HasPtr hp3=f3();   // this place is strange, new HasPtr created in fucntion is reused by hp3, no copy constructor is called;
	 cout<<"------------------"<<endl;
	 hp3 = f3(); // f3 return a temp HasPtr , use move assign 


	cout<<endl<<"----f4 return string----- "<<endl;
	HasPtr hp4=f4(); // just string constructor is called             
	 cout<<"------------------"<<endl;
	hp4 = f4();   // return string , init with sting constructor , them use move assing


	cout<<endl<<"----fun return from ref----- "<<endl;
	HasPtr hp5=f5(hp2); // only copy constuctor is called 
	 cout<<"------------------"<<endl;
	hp5 = f5(hp2);   // move assign is called 

}


