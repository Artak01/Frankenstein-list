#include <iostream>
#include <vector>
#include "frank_list.h"

using namespace vhuk;

int main() {
    FrankList<int> list = {1, 2, 6, 2, 5};
    
    std::cout << "Original list:" << std::endl;
    list.display();
    //list.sort(1);    
    auto it = list.begin();
    ++it;
//    std::cout << list.remove(5) << std::endl;
//    auto it1 = list.insert(it, 3, 0);
    auto it3 = list.find(6);
    std::cout << *it3 << std::endl;
    std::cout << "Original list:" << std::endl;
    //list.print(1, 0);
    //list.display();
    return 0;

}

