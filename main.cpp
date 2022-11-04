#include <iostream>
using namespace std;

int binArr[30]; int length = 0;

int *dec_to_bin(int n); // decimal to binary number converting function
int modExp(int b, int e, int m); // modular exponentiation calculator function

int main(){
    int modValue;
    int a, b, m;
    int *arr;

    cout << "MODULAR EXPONENTIATION CALCULATOR" << endl;
    cout << "(a^b mod m Solver)\n" << endl;

    cout << "Enter Base (a): ";
    cin >> a;
    cout << "Enter Exponent (b): ";
    cin >> b;
    cout << "Enter Modulus(m): ";
    cin >> m;

   arr=dec_to_bin(b);    //The address sent from the function is kept in the pointer

   cout << "\n" << endl;
   cout << b << " is equivalent to " << "(";

   for (int j=length-1; j>=0; j--) {   // binary number output
       cout << arr[j];
   }
   cout << ")" << " as binary number...\n" << endl;

   length = 0; //length holds the value of size , it needs to be reset
   modValue = modExp(a, b, m);
   cout <<"\nModular Exponentiation of "<<"("<<a<<"^"<<b<<")"<<" mod "<<"("<<m<<")"<<" = "<<modValue<< endl;

    return 0;
}



int *dec_to_bin(int n) {
    int num = n; 
    
    while (num > 0) { // this loop finds length of the array according to remaining number

        binArr[length] = num % 2;
        length++;                // length counter of array 
        num /= 2;
    }

    int* bin;   //array must be pointer to send values from function to main
    bin= new int[length];

    for (int  j = length - 1; j >= 0; j--) {

        bin[j] = binArr[j];  //array sends information to pointer array
    }
    return bin;
}

int modExp(int b, int e, int m) {

    int x = 1;
    int power = b % m;
    int* p;
    p = dec_to_bin(e);

    for (int i = 0; i < length; i++) {
        if (p[i] == 1) {

            cout << "Because b" <<i<< " is " << p[i] << ", We have x= " <<"("<<x<<"*"<<power%m<<")" << " and power = " <<  power << "^2" << " mod " << m  <<" = "<< (power*power) % m << endl;
            x = (x * power) % m;
        }
        if (p[i] == 0) {

            cout << "Because b" << i << " is " << p[i] << ", We have x= " << x<< " and power = " << power << "^2" << " mod " << m << " = " << (power * power) % m << endl;
        }
          power = (power * power) % m;


    }

    return x;
}
   

   
