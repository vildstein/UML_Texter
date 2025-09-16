 #include <iostream>
 #include <vector>
 #include <string> 


bool isStartsWithCharacters(const char ch, const std::string string) {
    auto result{false};

    if (!string.empty()) {
        if (string.at(0) == ch) {
            //std::cout << "CHAR CHAR CHAR CHAR = " << ch << " ";
            //std::cout << "string string string string = " << string.at(0) << std::endl;
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
            if (!str.empty()/* && !isStartsWithCharacters(char('#'), str)*/) {
                stringVector.push_back(str);
                str.clear();
            }
        }
    }





   
   
   for (const auto& str : stringVector) {
        std::cout << str << std::endl;
   }




   //Удалить макросы препроцессора




   
   
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