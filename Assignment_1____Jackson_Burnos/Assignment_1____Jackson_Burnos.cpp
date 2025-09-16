
//Jackson Burnos 
// Assignment 1
// CS303  T/Th  1p-2:15p

#include "Functions_Assignment_1.h"


int main()
{
    a::array<int> arr;   //initial array of size 20

    //opening file
    std::ifstream file("A1input.txt");
    //checking file state
    if (!file.is_open()) {
        std::cout << "could not open file" << std::endl;
        return 1;
    }

    std::string line, token;

    try {
        while (std::getline(file, line)) {
            std::stringstream ss(line);  // turn line into stream
            std::string num;
            // get integers separated by spaces
            while (ss >> num) {         
                int x = stoi(num);
                arr.addEnd(x);
            }
        }
    }
    //catching things that aren't ints
    catch (...) {
        std::cout << "Error reading file" << std::endl;
    }

    //output formatting and tests
    std::cout << "TEST: Making sure all elements were read into array using .getSize()" << std::endl;
    std::cout << arr.getSize() << std::endl << std::endl;

    //function 1 test
    std::cout << "FUNCTION 1 TEST: Seeing if value is in the array and returning index" << std::endl;
    std::cout << "Enter good value to check for: ";
    int val;
    std::cin >> val;
    int ind = arr.isPresent(val);
    if (ind != -1) {
        std::cout << std::endl << "Value " << val << " is at position " << ind << std::endl;
    }
    else
        std::cout<<std::endl<<"value is not present"<<std::endl;
    std::cout << "Enter bad value to check for: ";
    int val2;
    std::cin >> val2;
    int ind2 = arr.isPresent(val2);
    if (ind2 != -1) {
        std::cout << std::endl << "Value " << val << " is at position " << ind << std::endl;
    }
    else
        std::cout << std::endl << "value is not present" << std::endl;

    //function 2 test
    std::cout << "FUNCTION 2 TEST: Modifying value at index and returning both old and new" << std::endl;
    std::cout << std::endl;
    int v, i;
    std::cout << "Enter index to modify: ";
    std::cin >> i;
    std::cout << std::endl<< std::endl;
    std::cout << "Enter new value: ";
    std::cin >> v;
    arr.modIndex(i, v);

    //function 3 test
    std::cout << "FUNCTION 3 TEST: Adding to end of the array" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter number to add at the end: ";
    int xx;
    std::cin >> xx;
    arr.addEnd(xx);
    std::cout << "Number at end using [] operator and num items:  " << arr[arr.getSize()-1] << std::endl << std::endl;

    //function 4 test
    std::cout << "FUNCTION 4 TEST: removal function" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter valid index to remove: ";
    int yx;
    std::cin >> yx;
    std::cout << std::endl << "Value at index " << yx << " is " << arr[yx] << std::endl;
    arr.removeIndex(yx);
    std::cout << "Value at index " << yx << " after removal is " << arr[yx] << std::endl << std::endl;







}


