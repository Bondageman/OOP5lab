#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void permutationSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}   

template <typename T>
class ArrayTransformer {
private:
    T* arr;
    int size;

public:
    ArrayTransformer(T arr[], int size) {
        this->size = size;
        this->arr = new T[size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
    }

    void squareElements() {
        for (int i = 0; i < size; i++) {
            arr[i] *= arr[i];
        }
    }

    void printArray() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~ArrayTransformer() {
        delete[] arr;
    }
};

int main()
{
    SetConsoleOutputCP(1251);

    cout << "Завдання 1: " << endl;

    int intArr[] = { 7, 3, 9, 2, 8 };
    int size = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Масив перед сортуванням: ";
    for (int i = 0; i < size; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    permutationSort(intArr, size);

    cout << "Масив після сортування методом перестановок: ";
    for (int i = 0; i < size; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    cout << endl;
    cout << "Завдання 2: " << endl;

    ArrayTransformer<int> transformer(intArr, size);
    cout << "Масив перед перетворенням: ";
    transformer.printArray();

    transformer.squareElements();
    cout << "Масив після перетворення (квадрат кожного елемента): ";
    transformer.printArray();
}

