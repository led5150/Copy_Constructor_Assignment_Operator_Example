/******************************************************************************
 * ArrayPoint.cpp
 *
 * Created by: Matt Champlin for Comp 15
 * Date: 01/24/20
 *
 * Program Purpose:  Implementation of the ArrayPoint class.
 *****************************************************************************/


/********************************* READ ME ************************************
 * The class called ArrayPoint represents a point in two ways:
 * One way is with two ints x and y, the other is a dynamically allocated int 
 * array called xy_array where xy_array[0] represents x and xy_array[1] 
 * represents y.  
 *****************************************************************************/


#include <iostream>
#include "ArrayPoint.h"
using namespace std;


    // Default Constructor
    ArrayPoint::ArrayPoint() 
    {
        x = 1;
        y = 2;
        xy_array = new int[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++) {
            xy_array[i] = 0;
        }
    }

    // Destructor
    // NOTE:  the operation to perform the delete has been 
    //        commented out on purpose. Leave it as such for now!
    //        You will un-comment this soon to demonstrate how a double free
    //        error might occur. 
    ArrayPoint::~ArrayPoint() 
    {
        delete [] xy_array;
    }

    
    // NOTE: Leave this commented out until you compile and run it at least 
    //       once! You will be prompted at the end of the program to come
    //       back here and uncomment it.



    // Function:   Copy Constructor
    // Parameters: const ArrayPoint &source - an already initialized 
    //             ArrayPoint object
    // Returns:    A ArrayPoint object
    // Does:       Assigns an initialized ArrayPoint to another 
    //             initialized ArrayPoint

    // ******************* UNCOMMENT BELOW WHEN READY *************************
    // ArrayPoint::ArrayPoint(const ArrayPoint &rhs)
    // {
    //     x = rhs.x;
    //     y = rhs.y;
    //     xy_array = new int[MAX_SIZE];
    //     for (int i = 0; i < MAX_SIZE; i++) {
    //         xy_array[i] = rhs.xy_array[i];
    //     }
    // }


    // Function:   Overloaded Assignment Operator
    // Parameters: const ArrayPoint &source - an initialized ArrayPoint object
    // Returns:    An ArrayPoint Object
    // Does:       Assigns an initialized ArrayPoint to another initialized 
    //             ArrayPoint.

    // ******************* UNCOMMENT BELOW WHEN READY *************************
    // ArrayPoint &ArrayPoint::operator= (const ArrayPoint &rhs)
    // {
    //     if (this == &rhs) {
    //         return *this;
    //     }
    //     // recycle memory currently allocated
    //     delete [] xy_array;
    //     // Initialize other member variables from rhs (this looks familiar no?)
    //     x = rhs.x;
    //     y = rhs.y;
    //     xy_array = new int[MAX_SIZE];
    //     for (int i = 0; i < MAX_SIZE; i++) {
    //         xy_array[i] = rhs.xy_array[i];
    //     }
    //     return *this;
    // }





    // Function:   set_xy
    // Parameters: x_input - value for x
    //             y_input - value for y
    // Returns:    Nothing    
    // Does:       sets the variable x and y to the given input
    void ArrayPoint::set_xy(int x_input, int y_input) 
    {
        x = x_input;
        y = y_input;
    }

    // Function:   set_array
    // Parameters: x_input - value for x
    //             y_input - value for y
    // Returns:    Nothing    
    // Does:       sets the array x and y to the given input
    void ArrayPoint::set_array(int x_input, int y_input) 
    {
        xy_array[0] = x_input;
        xy_array[1] = y_input;
    }

    // Function:   print_xy
    // Parameters: none
    // Returns:    Nothing    
    // Does:       prints the x and y member variables to cout
    void ArrayPoint::print_xy() 
    {
        cout << "x is: " << x << " y is: " << y << endl;
    }

    // Function:   print_array
    // Parameters: none
    // Returns:    Nothing    
    // Does:       prints the contents of xy_array member variable to cout
    void ArrayPoint::print_array() 
    {
        cout << "xy_array[0]: " << xy_array[0] << " xy_array[1]: "  
             << xy_array[1] << endl << endl;    
    }


