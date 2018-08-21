#include<bits/stdc++.h>
using namespace std;  

template <class T> class Array {  
   T* array;  
   int size;  

public:  
   Array(int sz): size(sz) {  
      array = new T[size];  
      memset(array, 0, size * sizeof(T));  
   }  

   Array(const Array& a) {  
      size = a.size;  
      array = new T[size];  
      memcpy_s(array, a.array, sizeof(T));  
   }  

   T& operator[](int i) {  
      return *(array + i);  
   }  

   int Length() { return size; }  

   void print() {  
      for (int i = 0; i < size; i++)        
         cout << *(array + i) << " ";  

      cout << endl;  
   }  

   template<class Y>  
   friend Array<Y>* combine(Array<Y>& a1, Array<Y>& a2);  
   //friend Array<T>* combine(Array<T>& a1, Array<T>& a2);  
};  

template<class T>  
Array<T>* combine(Array<T>& a1, Array<T>& a2) {  // this is not a member function 
   Array<T>* a = new Array<T>(a1.size + a2.size);  
   for (int i = 0; i < a1.size; i++)  
      (*a)[i] = *(a1.array + i);  

   for (int i = 0; i < a2.size; i++)  
      (*a)[i + a1.size] = *(a2.array + i);  

   return a;  
}  

int main() {  
   Array<char> alpha1(26);  
   for (int i = 0 ; i < alpha1.Length() ; i++)  
      alpha1[i] = 'A' + i;  

   alpha1.print();  

   Array<char> alpha2(26);  
   for (int i = 0 ; i < alpha2.Length() ; i++)  
      alpha2[i] = 'a' + i;  

   alpha2.print();  
   Array<char>*alpha3 = combine(alpha1, alpha2);  
   alpha3->print();  
   delete alpha3;  
}  
