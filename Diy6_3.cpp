#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int* arr;
    int size;

public:
    SafeArray(int n) {
        size = n;
        arr = new int[size]();
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range!");
        }
        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }
};

int main() {
    SafeArray a(5);

    try {
        for (int i = 0; i < 5; i++) {
            a[i] = (i + 1) * 10;
        }

        cout << "Array elements: ";
        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }

        cout << "\nAccessing invalid index...\n";
        cout << a[7];
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
