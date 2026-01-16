#include <iostream>
#include <clocale>

char* _strrchr(const char* string, int c){
    char* last = nullptr;
    char ch = (char)c;

    while(*string != '\0'){
        if(*string == ch){
            last = (char*)string;
        }
        string++;
    }

    if(ch == '\0'){
        return (char*)string;
    }

    return last;
}

bool uniqueChars(const char* s, const char* e){
    for(const char* i = s; i < e; i++){
        for(const char* j = i + 1; j < e; j++){
            if(*i == *j) return false;
        }
    }
    return true;
}

int main(){
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите строку: " << std::endl;
    char testStr[301];
    std::cin.getline(testStr, 301);
    std::cout << "Введите символ: " << std::endl;
    char symbol;
    std::cin>>symbol;
    char* pos = _strrchr(testStr, symbol);
    std::cin.ignore(1000, '\n');

    if(pos){
        std::cout << "Строка: " << testStr << std::endl;
        std::cout << "Последнее вхождение '" << symbol << "' найдено на позиции: "
                  << (pos - testStr) << std::endl;
    }
    else{
        std::cout << "Символ не найден." << std::endl;
    }


    char str[301];
    std::cout << "Введите строку до 300 символов: " << std::endl;

    std::cin.getline(str, 301);

    int i = 0;
    bool uWord = false;

    while(str[i] != '\0'){
        while(str[i] == ' ' && str[i] != '\0'){
            i++;
        }

        if(str[i] == '\0')
            break;

        int s = i;
        while(str[i] != ' ' && str[i] != '\0'){
            i++;
        }
        int e = i;

        if(uniqueChars(&str[s], &str[e])){
            std::cout << "Первое слово с уникальными символами: ";
            for (int k = s; k < e; k++){
                std::cout << str[k];
            }
            std::cout << std::endl;
            uWord = true;
            break;
        }
    }

    if(!uWord){
        std::cout << "Слово с полностью уникальными символами не найдено." << std::endl;
    }

    return 0;
}
