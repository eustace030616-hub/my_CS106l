#include <map>
#include <iostream>
int main() {
    std::map<int, char> preston{
        {0, 'p'}, {1,'r'}, {2, 'e'}
    };

    for (const auto& [key, value] : preston) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}