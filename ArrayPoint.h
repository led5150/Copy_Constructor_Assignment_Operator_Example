/******************************************************************************
 * ArrayPoint.h
 * 
 * Created by: Matt Champlin for Comp 15
 * Date: 01/24/20
 *
 * Program Purpose:  Header file for ArrayPoint class.
 *****************************************************************************/

#ifndef _ARRAYPOINT_H_
#define _ARRAYPOINT_H_


class ArrayPoint
{
public:
    
    ArrayPoint();   // Default Constructor
    ~ArrayPoint();  // Default Destructor

                  /* LEAVE THESE UNCOMMENTED AT FIRST!! */
    // ArrayPoint(const ArrayPoint &rhs);              // Copy Constructor
    // ArrayPoint &operator= (const ArrayPoint &rhs);  // Assignment Overload

    void set_xy(int x_input, int y_input); 
    void set_array(int x_input, int y_input);
    void print_xy();
    void print_array();

private:
    int x;
    int y;
    static const int MAX_SIZE = 2;
    int *xy_array;
};

#endif
