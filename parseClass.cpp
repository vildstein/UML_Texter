#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


bool isStartsWithCharactersAndNotEmpty(const char ch, const std::string& string) {
    auto result{false};

    if (!string.empty()) {
        if (string.at(0) == ch) {
            result = true;
        }
    }
    return result;
} 


void parseClass(const std::string& headerFile) {
   //Удалить комментарии

   std::string str{};
   std::vector<std::string> stringVector{};
   
    for (const auto& ch : headerFile) {
        if (ch != char('\n')) {
            str.push_back(ch);            
        } else {        
            if (!str.empty()) {
                stringVector.push_back(str);
                str.clear();
            }
        }
    }

    //Удалить макросы препроцессора
    for (auto& string : stringVector) {
        if (isStartsWithCharactersAndNotEmpty('#',string)) {
            string.clear();
        }
    }

    //Remove empty strings
    auto isStringEmpty = [&](std::string& str)->bool { return str.empty() ;};
    const auto removeIt = std::remove_if(stringVector.begin(), stringVector.end(),isStringEmpty);
    stringVector.erase(removeIt, stringVector.end());

    for (const auto& string : stringVector) {
        std::cout << string << std::endl;
    }



    //Найти правильное имя класса

   /*std::string str{};

   std::vector<std::string> stringVector{};

    for (const auto& ch : headerFile) {
        if (ch != char('\n')) {
            str.push_back(ch);
        }

   }*/


   
   //Найти методы

   //Найти поля

   //Разбить на private protected public:
           


}