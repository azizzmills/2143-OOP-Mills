///////////////////////////////////////////////////////////////////////////////
// 
//
// Author:           Azizz Mills 
// Email:            azizzmillz@gmail.com
// Label:            AO3
// Title:            Stack Class
// Course:           CMPS 2143
// Semester:         Spring 2021 
//
// Description:
//       This code creates a simple stack and displays the output. 
//
// Usage:
//       This program is self sufficient. (No need for user input or intervention)
//
// Files:            main.cpp : driver program
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 *
 * Description:
 *      This class defines a simple stack where it's contents can added or removed from it.
 *
 * Public Methods:
 *               CircularArrayQue
 *               CircularArrayQue(int size)
 *      void     Push(int item)
 *      int      Pop()
 *
 * Private Methods:
 *      void     init(int size)
 *      bool     Full()    
 *      
 * Usage:
 *        
 *      init(int size):                      this function intializes the begining and end of the stack and also the stack size
 *      CircularArrayQue() :                 this is a constructor that intializes the stack amount to 10
 *      CircularArrayQue(int size):          this is a constructor that intializes the stack amount. (it is not being used)
 *      void push(int item):                 this function enters an interger into the stack 
 *      int pop():                           removes intergers from the stack 
 *       
 */

class CircularArrayQue {
private:
    int* Container;      // pointer used to point to the stack
    int Front;           // begining of the stack 
    int Rear;            // bottom of the stack
    int QueSize;         // items in the queue
    int CurrentSize;     // tells the amount of integers in the stack 

    /**
     * Public: init
     *
     * Description:
     *      It intializes the begining and end of the stack and also the stack size
     *
     * Params:
     *      int size:     intilizes variabes Front, Rear and CurrentSize
     *
     * Returns:
     *      no return. it is a void method
     */


    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }


    /**
     * Public : Full
     *
     * Description:
     *      Checks whether the stack is filled or not 
     *
     * Params:
     *      None
     *
     * Returns:
     *      nothing. 
     */


    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push
     *
     * Description:
     *     Inputs integers into the stack 
     *
     * Params:
     *      int item:   it is the integer that is being added to the stack 
     *
     * Returns:
     *      nothing. it is a void function 
     */


    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public : Pop
     *
     * Description:
     *      Removes intergers from the stack 
     *
     * Params:
     *     none
     *
     * Returns:
     *      return the interger that was removed from the stack( fucntion not used)
     */


    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const CircularArrayQue& other); 
};

ostream& operator<<(ostream& os, const CircularArrayQue& other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}