#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

bool hasContentInBrackets(const std::string& line, char open, char close){
    size_t openPos = line.find(open);
    while (openPos != std::string::npos) {
        size_t closePos = line.find(close, openPos + 1);
        if (closePos != std::string::npos && closePos > openPos + 1){
            return true;
        }
        openPos = line.find(open, openPos + 1);
    }
    return false;
}

void print(const std::string& filename){
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cout << "Не удалось открыть файл"<< std::endl;
        return;
    }
    std::cout<< filename <<std::endl;
    std::string line;
    bool isEmpty = true;
    while(std::getline(file, line)){
        std::cout << line << std::endl;
        isEmpty = false;
    }
    if(isEmpty)
        std::cout << "Пусто" << std::endl;
    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string inName, outName1, outName2;

    std::cout << "Исходный файл: ";
    std::cin >> inName;
    std::cout << "Выходной файл 1 (круглые скобки): ";
    std::cin >> outName1;
    std::cout << "Выходной файл 2 (квадратные скобки): ";
    std::cin >> outName2;

    std::ifstream inFile(inName);
    if (!inFile.is_open()) {
        return 1;
    }

    std::ofstream outFile1(outName1);
    std::ofstream outFile2(outName2);

    std::string line;
    while(std::getline(inFile, line)){
        if(hasContentInBrackets(line, '(', ')')){
            outFile1 << line << "\n";
        }
        if(hasContentInBrackets(line, '[', ']')){
            outFile2 << line << "\n";
        }
    }

    inFile.close();
    outFile1.close();
    outFile2.close();

    std::cout << "Готово" << std::endl;

    std::cout<<"Первый файл: "<<std::endl;
    print(outName1);
    std::cout<<"Второй файл: "<<std::endl;
    print(outName2);

    return 0;
}
