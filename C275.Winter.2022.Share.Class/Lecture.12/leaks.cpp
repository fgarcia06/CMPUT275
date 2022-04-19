#include <iostream>
using std::cout; 
using std::endl;

int* leaky();
void dummy();

int main() {
    // memory leak - still reachable (still can be freed)
    dummy();

    // memory leak
    int code = 0;
    for (int i = 0; i < 100; i++) {
        // pointer to the allocated memory will be lost
        // in the next iteration
        code = *leaky();
        cout << "code is: " << code << endl;
    }

    return 0;
}

int* leaky() {
    int* number = new int;
    *number = 10;
    return number;
}

void dummy() {
    // static local variable will retain its value 
    // even after it goes out of scope
    static int *ptr;

    ptr = new int[5];
    for (int i=0;i<5;i++) {
        ptr[i] = 0;
    }

    cout << "code is: " << *ptr << endl;
}
