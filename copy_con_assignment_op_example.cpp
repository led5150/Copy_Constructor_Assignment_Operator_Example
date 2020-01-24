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

    cout << "\n1. Using the default constructor to initialze an ArrayPoint \n"
            "object p.  We then print out the variables to make sure \n"
            "our initialzation was correct\n\n";

    // Initializing like this runs the default constructor
    ArrayPoint p;

    // Printing the values to show the default values we set 
    // in our constructor.
    cout << "Printing p: \n";
    p.print_xy();
    p.print_array();



    cout << "2. Now we set some new values for the member variables. \n";
    p.set_xy(42, 99);
    p.set_array(42, 99);

    cout << "Printing out the values of p to prove that they "
            "were changed correctly: \n\n";
    cout << "Printing p: \n";
    p.print_xy();
    p.print_array();



    cout << "3. Initializing a new ArrayPoint q using the default "
            "copy constructor\n";

    // Now we use the default copy constructor to initialize 
    // a new ArrayPoint with a copy of our original ArrayPoint p.
    
    ArrayPoint q = p;  // Note: Initializing with parens 
                        // also calls the copy constructor.
                        // Example:  ArrayPoint q(p);

    // NOTE:  Comment out the copy constructor example above and 
    //        uncomment the assignment operation below to see how the same 
    //        thing happens with the overloaded assignment operator!
    
    // ArrayPoint q;
    // q = p;

    cout << "4. Priting q after copy constructing from p to see that\n"
            "the values 'SEEM' to all have been copied:\n\n";
    cout << "Printing q: \n";
    q.print_xy();
    q.print_array();

    cout << "****************** The Interesting Part *******************\n";
    cout << "Now we change the values in p.  You might expect that this \n"
            "change will only be reflected in p.  However as demonstrated \n"
            "below, changing the values of the dynamically allocated array \n"
            "of p will also be reflected in the array in q.  This is\n"
            "the result of the default copy constructor making a shallow\n"
            "copy.  The integers however, do act as we might expect\n"
            "therefore, copy constructors are not needed when only using\n"
            "primitive data types.\n\n";
    p.set_xy(4444, 5555);
    p.set_array(4444, 5555);

    cout << "Showing how variables changed in p as expected:\n\n";
    cout << "Printing p: \n";
    p.print_xy();
    p.print_array();


    cout << "Notice how the xy_array contained in q got changed to the \n"
            "values we changed the xy_array in p to!!\n"
            "This is because the shallow copy only copied the address of\n"
            "the array in p, not it's actual contents.\n\n";

    cout << "Printing q: \n";
    q.print_xy();
    q.print_array();

    cout << "\nNow run valgrind to see that there are memory leaks because \n"
            "we have not implemented a working destructor. BAD!\n\n";
    // NOTE: IN THIS NEXT SECTION YOU WILL INTENTIONALLY CREATE A DOUBLE FREE
    //       ERROR.  Just undo this step after you have done so to continue.
    cout << "You might think to fix the memory leak, all you need is a \n"
            "destructor.  Now go and uncomment the 'delete [] xy_array' \n"
            "command in destructor of the .h file. \n"
            "Copile and run the code now....\n"
            "This will cause a double free memory error!! YIKES!! \n\n";

    // Now you can uncomment the copy constructor and overloaded assignment
    // operator and the destructor to see how proper implementations 
    // of this will fix both the memory leaks and the double free!  Remember 
    // to do so in both the .cpp and .h files!!  Without a working copy
    // constructor and assignment overload, your destructor will cause double
    // free errors.  But notice with them, everything works as you want!

    cout << "Hope this helped you understand Copy Constuctors and \n"
            "Overloaded Assignment Operators!  Have a nice day!\n";


    return 0;
}