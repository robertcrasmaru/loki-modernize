#include <iostream>
#include "SmartPtr.h"

void say_hello(){
    std::cout << "Hello, from Loki-Modernize!\n";
}

struct MyClass
{
  int i_;
  
  MyClass( int i ) : i_(i) { std::cout << "MyClass cstr. " << i_ << "\n"; }
  ~MyClass() { std::cout << "MyClass dstr. " << i_ << "\n"; }

  void print() { std::cout << i_ << "\n"; }
};


typedef Loki::SmartPtr< 
  MyClass,
  Loki::RefCounted,
  Loki::AllowConversion,
  Loki::AssertCheck,          // Loki::RejectNull,
  Loki::DefaultSPStorage      // Loki::MallocSPStorage
> MyClassPtr;



int main()
{
    // let's just test a smart_ptr
    MyClass * mc2 = new MyClass( 4 );
    MyClassPtr sp2 = mc2;
    sp2->print();
  
    MyClassPtr sp1( new MyClass(3) );
    sp1->print();

    say_hello();

    return 0;
}