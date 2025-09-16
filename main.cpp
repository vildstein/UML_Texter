#include <iostream>
#include <string>
#include <fstream>

//прочитать файл

void readFromFile(const char* fileName, std::string& out) {

    std::ifstream file{fileName};

    if (!file) {
        std::cout << "WHERE IS A FILE?" << std::endl;
        std::cerr << "I'M NOT ABBLE TO OPEN THIS SHIT" << std::endl;
        return; 
    }

    std::string readedLine{};
    while(std::getline(file, readedLine)) {
        out.append(readedLine + '\n');
    }

    
    file.close();
}



int main(int argc, char** argv) {


    std::cout << "Количество аргументов = " << argc << std::endl;

    if (argc > 1) {

        const int argumentsCount = argc;

        char** begin = argv;
        char** end = argv + 1;

        std::cout << "Lets READ a file with name " << argv[1] << std::endl;

        std::string outFrom{};
        readFromFile(argv[1], outFrom);

        std::cout << outFrom << std::endl;


        //Читаем файл
        //Выводим на экран
        //Парсим

    } else {
        std::cout << "Exit" << std::endl;
        exit(1);
    }

    
    return 0;
}
