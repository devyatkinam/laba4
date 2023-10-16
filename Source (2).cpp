#include <iostream>

int my_atoi(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ') {
        i++;
    }
 
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    return sign * result;
}

int main() {
    const char* str = "-300";
    int num = my_atoi(str);
    std::cout << "Результат: " << num << std::endl;
    return 0;
}
