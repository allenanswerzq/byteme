#include<bits/stdc++.h>
// template_friend3.cpp  
// compile with: /EHsc  
using namespace std;  

template <class T>  
class X  
{  
private:  
   T* data;  
   void InitData(int seed) { data = new T(seed); }  
public:  
   void print() { cout << *data << endl; }  
   template <class U> friend class Factory;  
};  

template <class U>  
class Factory  
{  
public:  
   U* GetNewObject(int seed)  
   {  
    U* pu = new U;  
    pu->InitData(seed);  
    return pu;  
   }  
};  

int main()  
{  
   Factory< X<int> > XintFactory;  
   X<int>* x1 = XintFactory.GetNewObject(65);  
   X<int>* x2 = XintFactory.GetNewObject(97);  

   Factory< X<char> > XcharFactory;  
   X<char>* x3 = XcharFactory.GetNewObject(65);  
   X<char>* x4 = XcharFactory.GetNewObject(97);  
   x1->print();  
   x2->print();  
   x3->print();  
   x4->print();  
}  
