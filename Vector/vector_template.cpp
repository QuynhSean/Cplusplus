#include <bits/stdc++.h>
using namespace std;

template <typename T> class Classvector
{
private:
    T* arr;
    int capacity;
    int current;
public:
    Classvector(){
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    ~Classvector(){
        delete []arr;
    }

    //function to add element at the last
    void push(T data){
        if(current == capacity){
            int* temp = new T[2*capacity];
            for(int i = 0; i < capacity; i++){
                temp[i] = arr[i];
            }

            //delete previous array
            delete []arr;
            capacity *= 2;
            arr = temp;
        }

        //Insert data
        arr[current] = data;
        current++;
    }

    //function to add element at any index

    void push(T data,  int index){
        if(index==capacity){
            push(data);
        }
        else 
            arr[index] = data;
    }

    //function to extract element at any index
    T get(int index){
        //if index is within the range
        if(index < current){
            return arr[index];
        }
        //if index is out the range
        return -1;
    }

    //function to delete the last element
    void pop() {current--;}

    //function to get size of the vector
    int size(){return current;}

    //function to get capacity of the vector
    int getcapacity(){return capacity;}

    // function to print array element
    void print(){
        for(int i = 0; i< current; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Classvector<int> v1;
    Classvector<int> v;
    // Classvector v1;
    v.push(10);
    v.push(20);
    v.push(30);
    v1.push(71);
    v1.push(72);
    v1.push(73);
    v1.push(74);
    cout << "Vector size: " << v.size() << endl;
    cout << "Vector size : " << v.getcapacity() << endl;
    cout << "Vector elements : ";
    v.print();
 
    v.push(100, 1);
 
    cout << "\nAfter updating 1st index" << endl;
 
    cout << "Vector elements of type int : " << endl;
    v.print();
    // This was possible because we used templates
    cout << "Vector elements of type char : " << endl;
    v1.print();
    cout << "Element at 1st index of type int: " << v.get(1)
         << endl;
    cout << "Element at 1st index of type char: "  << v1.get(1) << endl;
 
    v.pop();
    v1.pop();
 
    cout << "\nAfter deleting last element" << endl;
 
    cout << "Vector size of type int: " << v.size() << endl;
    cout << "Vector size of type char: " << v1.size()
         << endl;
    cout << "Vector capacity of type int : "
         << v.getcapacity() << endl;
    cout << "Vector capacity of type char : "
         << v1.getcapacity() << endl;
 
    cout << "Vector elements of type int: ";
    v.print();
    cout << "Vector elements of type char: ";
    v1.print();
 
    return 0;
}

