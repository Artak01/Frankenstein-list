#include <iostream>
#include <vector>
#include "frank_list.h"

int main() {
    FrankList<int> list = {1, 2, 6, 2, 5};
    
    std::cout << "Original list:" << std::endl;
    list.display();
    list.sort(1);    
    std::cout << "Sort list:" << std::endl;
    list.display();
    return 0;

}
