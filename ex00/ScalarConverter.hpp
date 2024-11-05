#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();  // インスタンス化を防ぐためのコンストラクタはプライベート
    static bool isCharLiteral(const std::string& literal);
    static bool isIntLiteral(const std::string& literal);
    static bool isFloatLiteral(const std::string& literal);
    static bool isDoubleLiteral(const std::string& literal);
    static void printResults(char c, int i, float f, double d, bool validChar, bool validInt);
};

#endif
