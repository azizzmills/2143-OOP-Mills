/*
*    Author:           Azizz Mills
*    Email:            azizzmillz@gmail.com
*    Label:            A08
*    Title:            Copy Constructor Program 
*    Course:           CMPS 2143
*    Semester:         Spring 2021
*
*    Description:
*        This is an editied program. The class ColorPallette was written to dynamically store many random colors. 
         These colors will be printed out to the screen. 

*    Usage:
*        - $ ./main filename
*
*    Files:
*          main.cpp
*
*/


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// this show the use of copy constructor using dynam
//allocated memory due to the association with
//pointers that makes a deep copy

class NumContainer
{
private:

    int* array;     // pointer using dynam mem allocation
    int size;
public:    
    NumContainer()
    {
        size = 100;
        array = new int[size];
    }
    NumContainer(int s)
    {
        size = s;
        array = new int[size];
    }
    NumContainer(const NumContainer& other)
    {
        size = other.size;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
    }       
};


// implementation of rgb color class
// that intialize one instance, or three instance
class RgbColor
{
private:// private by default
    int red;                    // 0-255 red
    int green;                  // 0-255 green
    int blue;                  // 0-255 blue    
public:
    RgbColor();             // def. constructr
    RgbColor(int);          // overloaded 1 color
    RgbColor(int, int, int);  // overload three colors

    //3 setters for colors
    void SetR(int);         // set red
    void SetG(int);         // set green
    void SetB(int);         // set blue

  // three get functions for color

    int GetR();             // get red
    int GetG();             //get green
    int GetB();             //get blue

    void GrayScale();       // averages  of the colors

   
    RgbColor operator+(const RgbColor&);
                            
    // print to the outstream
    friend ostream& operator<<(ostream&, const RgbColor&);
   

    // overloaded addition operator
    // RgbColor operator+(const RgbColor&);

};

/*
Function: 
        SetR
Parameters:
         an integer
Description: 
         Sets an integer variable to a value
*/


void RgbColor::SetR(int r)
{
    red = r;    
}

void RgbColor::SetG(int g)
{
     green = g;   
}

void RgbColor::SetB(int b)
{
    blue = b;    
}

/*
Function:
        GetR
Parameter:
        none 
Description:
          Returns integer value to variable
*/

int RgbColor::GetR()
{
    return red;
}

int RgbColor::GetG()
{
    return green;
}

int RgbColor::GetB()
{
    return blue;
}

RgbColor RgbColor::operator+(const RgbColor& rhs) {
    int r = (this->red + rhs.red) / 2;
    int g = (this->green + rhs.green) / 2;
    int b = (this->blue + rhs.blue) / 2;

    return RgbColor(r,g,b);
}

//default constructor
RgbColor::RgbColor()
{
    red = green = blue = 0;
}
// intialize each to color
RgbColor::RgbColor(int color)
{
    red = green = blue = color;
}

// assign variable to make new

RgbColor::RgbColor(int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
}
//overload ostream using friend function
 ostream& operator<<(ostream& outfile, const RgbColor& other)
{
    outfile << "[" << other.red << "," << other.green << "," << other.blue << "]";
    return outfile;
}

 /*
 Function:
       GrayScale()
Parameters:
       none
Decription:
       Prints out the values the reperesent the color grey         
 */
 void RgbColor::GrayScale()
 {     
     RgbColor C4(50, 50, 50);
     cout << "the grayscale is:" << C4 << endl;
 }

int main()
{
    RgbColor C1(255, 200, 11);  //create instance of c1
    RgbColor C2(100, 14, 123);// create instance of c2
    RgbColor C3 = C1 + C2;// first color and second color add together addition overload assign to c3
    RgbColor C4;   
    cout <<"the combine values are:"<< C3 << endl;// print out c3 obj
    C4.GrayScale();

    return 0;
}