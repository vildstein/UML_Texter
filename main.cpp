#include <iostream>
#include <string>
#include <fstream>

//прочитать файл



void parseClass(const std::string& headerFile);


void readFromFile(const char* fileName, std::string& out) {

	std::ifstream file{fileName};
	
	if (!file) {
		std::cout << "WHERE IS A FILE?" << std::endl;
		std::cerr << "I'M NOT ABBLE TO OPEN THIS SHIT" << std::endl;
		return; 
	}
	
	std::string readedLine{};
	//while(std::getline(file, readedLine)) {
	//	out.append(readedLine + '\n');
	//}

	char ch{'0'};

	while(file.get(ch)) {
		out.push_back(ch);
	}

	file.close();
}

int main(const int argc, char** argv) {
	
	std::cout << "Количество аргументов = " << argc << std::endl;
	std::cout << std::endl;
	
	if (argc > 1) {
		
		const int argumentsCount = argc;
		char** begin = argv;
		char** end = argv + 1;
		
		std::cout << "Lets READ a file with name " << argv[1] << std::endl;
		std::cout << std::endl;
		
		std::string outFrom{};		
		readFromFile(argv[1], outFrom); //Читаем файл

		//std::cout << outFrom << std::endl; //Выводим на экран        
		
		parseClass(outFrom);
		
		//Парсим
	} else {
		std::cout << "Exit" << std::endl;
		exit(1);
	}
	
	return 0;
}
//Code in Jet Brains CLion thanks them all