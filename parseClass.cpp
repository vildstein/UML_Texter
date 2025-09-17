#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//constexpr char* list[] {"const", "override", "virtual"};
//constExpr wordsCount = 3;

bool isStartsWithCharactersAndNotEmpty(const char ch, const std::string& string) {
    auto result{false};

    if (!string.empty()) {
        if (string.at(0) == ch) {
            result = true;
        }
    }
    return result;
}

void removeEmptyStringsFromStringVector(std::vector<std::string>& stringList) {
    auto isStringEmpty = [&](const std::string& str)->bool { return str.empty(); };
    const auto removeIt = std::remove_if(stringList.begin(), stringList.end(),isStringEmpty);
    stringList.erase(removeIt, stringList.end());
}

void removeCharacterFromString(const char ch, std::string& string) {
    const auto removeIt = std::remove(string.begin(), string.end(), ch);
    string.erase(removeIt, string.end());
}

void removeCharactersFromBeginningOfString(const char ch, std::string& string) {

    auto charactersToFindInTheBeginningOfString = [ch] (char character)->bool { return character != ch; };
    const auto findIt = std::find_if(string.cbegin(), string.cend(), charactersToFindInTheBeginningOfString);

    if (findIt != string.cend() && *(findIt) != '\n') {

        std::string contentAfterCharacters{};
        std::copy(findIt, string.cend(), std::inserter(contentAfterCharacters, contentAfterCharacters.begin()));

        string = contentAfterCharacters;

    }
}

bool isOneLineComment(const std::string& string) {

    auto result{false};
    if (isStartsWithCharactersAndNotEmpty('/', string) && (string.cbegin() + 1) != string.end() && *(string.cbegin() + 1) == '/') {
        result = true;
    }
    return result;
}

void removeForwardClassDeclaration() {

}






void parseClass(const std::string& headerFile) {

   std::string str{};
   std::vector<std::string> stringVector{};
   
    for (const auto& ch : headerFile) {
        if (ch != '\n') {
            str.push_back(ch);            
        } else {        
            if (!str.empty()) {
                stringVector.push_back(str);
                str.clear();
            }
        }
    }

    //Remove Tabs from beginning of the string
    for (auto& string : stringVector) {
        if (isStartsWithCharactersAndNotEmpty('\t',string)) {
            removeCharacterFromString('\t', string);
        }
    }
    //remove spaces from the beginning of the string
    for (auto& string : stringVector) {
        if (isStartsWithCharactersAndNotEmpty(' ',string)) {
            removeCharactersFromBeginningOfString(' ', string);
        }
    }

    //Remove Macro And OneLineComments
    for (auto& string : stringVector) {
        if (isStartsWithCharactersAndNotEmpty('#',string) || isOneLineComment(string)) {
            string.clear();
        }
    }
    //Remove empty strings
    removeEmptyStringsFromStringVector(stringVector);

    //Remove Class Forward Declaration


    //removeEmptyStringsFromStringVector(stringVector);

    //remove comments

    // 1. Remove OneLightComment

    // 2. Remove MultiLineComments


    //Vector OutPut
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