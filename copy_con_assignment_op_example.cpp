/******************************************************************************
 * copy_con_assigment_op_example.cpp
 *
 * Created by: Matt Champlin for Comp 15
 * Date: 01/24/20
 *
 * Program Purpose:  To demonstrate the proper use of a copy constructor
 *                   and an overloaded assignment operator.  Shows what can
 *                   happen when these two are not implemented and you are
 *                   using a class with memory allocated on the heap.
 *****************************************************************************/

#include <iostream>
#include "ArrayPoint.h"
using namespace std;


int main() {
    cout << "\nCopy Constructors and Overloaded Assignment Operators\n";
    cout << "          An example of why we need them: \n" << endl;


    /*  
        1.  Using the default constructor to initialze an ArrayPoint
            object p.  We then print out the variables to make sure
            our initialzation was correct.
    */

    ArrayPoint p;   // Initialization using Default Constructor

    cout << "1. Printing p: \n" << endl;
    p.print_xy();
    p.print_array();


    /*
    2. Now lets set some new values for the member variables of p.
       We'll print these out to make sure they were updated correctly:
    */

    cout << "2. Setting p..." << endl;
    p.set_xy(42, 17);
    p.set_array(42, 17);


    cout << "   Printing p: \n" << endl;
    p.print_xy();
    p.print_array();


    /*
    3. Initializing a new ArrayPoint q from our original ArrayPoint p.
       Since we have not defined our own copy constructor, C++ synthesizes 
       one for us and does a "shallow copy".  Lets see how shallow copies
       work when we have dynamically allocated memory in our class.
    */

    
    
    ArrayPoint q = p;   // Note: Initializing with parens like this:
                        //       ArrayPoint q(p);
                        //       also calls the copy constructor.

    // JFFE:  When you're finished, comment out the copy constructor example    
    //        above and uncomment the assignment operation below to see 
    //        how the same thing happens with the overloaded assignment 
    //        operator!


    // ArrayPoint q;    // runs default constructor
    // q = p;           // Copies from p to q using the overloaded 
    //                  // assignment operator



    /*
    Priting q after copy constructing from p to see that
    the values 'SEEM' to all have been copied:
    */

    cout << "3. Printing q: \n" << endl;
    q.print_xy();
    q.print_array();

    /*

    ******************** The Interesting Part ************************

    4. Now we change the values in p. You might expect that this
       change will only be reflected in p. However as demonstrated
       below, changing the values of the dynamically allocated array
       of p will also be reflected in the array in q! This is
       the result of the default copy constructor making a shallow
       copy. The only information that is copied about our dynamically
       allocated array is the pointer to p's first value. Crucially, it
       does not copy the contents of the array.

       The integers however, do act as we might expect, therefore, 
       copy constructors 'may' not needed when only using
       built-in or "primitive" data types, though it is usually best 
       practice to implement them anyway.

    */

    p.set_xy(4444, 5555);
    p.set_array(4444, 5555);

    cout << "4. Showing how variables changed in p as expected." << endl;
    cout << "   Printing p: \n" << endl;
    p.print_xy();
    p.print_array();

    /*

    5. Now we will print the values of q.  Notice how the xy_array 
       contained in q got changed to the values we changed the xy_array 
       in p to!  

    */

    cout << "5. Showing how variables changed in q NOT as expected." << endl;
    cout << "   Printing q: \n" << endl;
    q.print_xy();
    q.print_array();

    /*

    6. Now run valgrind to see that there are memory leaks because
       we have not implemented a working destructor.


    // NOTE: IN THIS NEXT SECTION YOU WILL INTENTIONALLY CREATE A DOUBLE FREE
    //       ERROR. However, once you complete step 8 you will have a working
             program with no memory leaks or double frees.

    7. You might think to fix the memory leak, all you need is a
       destructor.  Go and uncomment the 'delete [] xy_array'
       command in destructor of the .h file.

       Copile and run the code now....
       This will cause a double free memory error!! YIKES!!

       The reason for this is that the code to destoy our ArrayPoint p runs.
       It frees the memory assosiated with p's xy_array.  Then the destuctor
       for q runs.  Since the pointer in xy_array pointer in q is pointing
       to the same memory location that we just freed, C++ throws the 
       double free error.


    8. Now you can uncomment the copy constructor and overloaded 
       assignment operator and the destructor to see how proper
       implementations of this will fix both the memory leaks and the
       double free!  Remember to do so in both the .cpp and .h files!!

             
    */
    cout << "Hope this helped you understand Copy Constuctors and \n"
            "Overloaded Assignment Operators!  Have a nice day!\n";


    return 0;
}