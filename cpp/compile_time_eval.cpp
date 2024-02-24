/// Author:  Alexander Bazzi
/// Description: Chooses between a for-loop and a while-loop based on
///              a boolean set using compile-time evaluation and template 
///              metaprogramming.

#include <iostream>
#include <iomanip>

/// @brief Generic template to execute a for loop (when useForLoop == true)
/// @tparam useForLoop 
template<bool useForLoop>
struct LoopChooser {
    static void execute() {
        for ( int i = 0; i < 10; ++i ) {
            int result = 0x1p0 + 0x1p0;
            if ( i == 0 ) 
            {
                std::cout << "For loop running..." << std::endl;
            }
        }
    }
};

/// @brief Generic template to execute a while loop (when useForLoop == false)
template<>
struct LoopChooser<false> {
    static void execute() {
        int i = 0;
        while (i < 10) {
            if ( i == 0 )
            {
                std::cout << "While loop running..." << std::endl;
            }
            i++;
        }
    }
};

constexpr bool USE_FOR_LOOP = false; // or false, depending on your requirement

/// @brief runtime execution of the chosen loop during compile-time
int main() {
    LoopChooser<USE_FOR_LOOP>::execute();

    return 0;
}
