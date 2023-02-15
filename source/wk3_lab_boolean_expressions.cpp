//------------------------------------------------------------------------------
// boolean_expressions.cpp : 
//
// - logical operator precedence
//      1) ()
//      2) !
//      2) ==, !=, <, >, <=, >=
//      4) &&
//      5) ||
// - short-circuit evaluation
// - if vs. switch
// - DeMorgan's Law
//------------------------------------------------------------------------------
#include "cmd_util.h"

#include <iostream>
using std::cout;


//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    int x = 0, y = 0;

    //--------------------------------------------------------------------------
    // Logical and, operator &&:
    // all sub-expressions must be true for the entire expression to be true
    //--------------------------------------------------------------------------
    if (x == 2 && y == 3) {
        cout << "x is 2 AND y is 3\n";
        cout << "short-circuit: if x is not 2 we don't care what y is!\n\n";
    }

    //--------------------------------------------------------------------------
    // Logical or, operator ||:
    // if one sub-expressions is true, the entire expression is true
    //--------------------------------------------------------------------------
    if (x == 2 || y == 3) {
        cout << "EITHER x is 2 OR y is 3 OR both\n\n";
        cout << "short-circuit: if x is 2 we don't care what y is!\n\n";
    }

    //--------------------------------------------------------------------------
    // Logical not, operator !:
    // negates the boolean value of an expression
    //--------------------------------------------------------------------------
    if (!(x == 2 && y == 3)) {
        cout << "EITHER x is 2 OR y is 3, OR neither\n\n";
    }

    //--------------------------------------------------------------------------
    // Programming idiom: !x is the same as x == 0, x is the same as x != 0
    //--------------------------------------------------------------------------
    if (!x) {
        cout << "!x is true when x is 0\n";
    }
    if (x == 0) {
        cout << "x == 0 is true when x is 0\n";
    }
    if (x) {
        cout << "x is not 0\n\n";
    }

    //--------------------------------------------------------------------------
    // Best practice: always compare to false, never compare to true
    // because true can be any numeric value other than 0, false is only zero
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // switch: can be used to compare one variable to many possible values
    // 
    // A switch statement is equivalent to an if/else if/else statement chain
    // 
    // Which to use is a matter of personal preference - I like if/else if/else
    // because:
    //  - it's easy to forget the break between cases, and
    //  - if/else if/else is not restricted to comparing one variable so
    //    it's more flexible, scales better, and
    //  - if/else if/else is more clear.
    // 
    // On the other hand, you can let execution "fall through" 
    // by omitting the break - but this is dangerous because it's not obvious!
    //--------------------------------------------------------------------------

    switch (x) {
    case 0:
        cout << "x is 0";
        break;
    case 1:
        cout << "x is 1";
        break;
    case 2:
        cout << "x is 2";
        break;
    default:
        cout << "x is not 0, x is not 1, x is not 2";
    }
    cout << "\n\n";

    //--------------------------------------------------------------------------
    // command loop example
    //--------------------------------------------------------------------------
    commandLoop();

    //--------------------------------------------------------------------------
    // DeMorgan's Laws can simplify long boolean expressions
    // 
    //      1) !(x && y) is the same as !x || !y
    // 
    //      2) !(x || y) is the same as !x && !y
    // 
    // Notice that: 
    //      !(x && y) is NOT THE SAME AS (x || y)
    //      !(x || y) is NOT THE SAME AS (x && y)
    // 
    // Proper use of DeMorgan's Laws involves negating each subexpression
    // separately!
    // 
    // Watch this short (6:00) video on DeMorgan's Laws for CS and programming:
    //      https://youtu.be/AGyjo2DLxjM
    //--------------------------------------------------------------------------
}
