#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <cmath>
#include <iomanip>  // 出力フォーマット調整のため

void ScalarConverter::convert(const std::string& literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool validChar = true, validInt = true;

    // 文字リテラルの判別と変換
    if (isCharLiteral(literal)) 
    {
        c = literal[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    // 整数リテラルの判別と変換
    else if (isIntLiteral(literal))
    {
        i = std::atoi(literal.c_str());
        if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        {
            validChar = false;
        } 
        else
        {
            c = static_cast<char>(i);
        }
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    // floatリテラルの判別と変換
    else if (isFloatLiteral(literal))
    {
        f = std::strtof(literal.c_str(), NULL);
        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        {
            validInt = false;
        }
        else
        {
            i = static_cast<int>(f);
        }
        c = static_cast<char>(f);
        d = static_cast<double>(f);
    }
    // doubleリテラルの判別と変換
    else if (isDoubleLiteral(literal))
    {
        d = std::strtod(literal.c_str(), NULL);
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        {
            validInt = false;
        }
        else
        {
            i = static_cast<int>(d);
        }
        c = static_cast<char>(d);
        f = static_cast<float>(d);
    }
    // 無効なリテラル
    else
    {
        std::cerr << "Invalid literal input." << std::endl;
        return;
    }

    // 結果を表示
    printResults(c, i, f, d, validChar, validInt);
}

// 型判別メソッド
bool ScalarConverter::isCharLiteral(const std::string& literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isIntLiteral(const std::string& literal)
{
    if (literal.empty()) return false;
    size_t i = (literal[0] == '-' ? 1 : 0);
    for (; i < literal.size(); ++i)
    {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
    if (literal.empty() || literal[literal.size() - 1] != 'f') return false; // literal.back()を使わない形
    size_t i = (literal[0] == '-' || literal[0] == '+' ? 1 : 0);
    bool hasDot = false;
    for (; i < literal.size() - 1; ++i)
    {
        if (literal[i] == '.')
        {
            if (hasDot) return false;
            hasDot = true;
        }
        else if (!isdigit(literal[i])) return false;
    }
    return hasDot;
}

bool ScalarConverter::isDoubleLiteral(const std::string& literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
    if (literal.empty()) return false;
    size_t i = (literal[0] == '-' || literal[0] == '+' ? 1 : 0);
    bool hasDot = false;
    for (; i < literal.size(); ++i)
    {
        if (literal[i] == '.')
        {
            if (hasDot) return false;
            hasDot = true;
        }
        else if (!isdigit(literal[i])) return false;
    }
    return hasDot;
}

void ScalarConverter::printResults(char c, int i, float f, double d, bool validChar, bool validInt)
{
    bool isNanOrInf = std::isnan(d) || std::isinf(d) || std::isinf(f) || std::isnan(f);

    std::cout << "char: ";
    if (isNanOrInf || !validChar)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (isNanOrInf || !validInt)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // 小数点以下2桁までの精度で出力
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f;
    if (std::isnan(f) || std::isinf(f))
        std::cout << "f" << std::endl;
    else
        std::cout << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}
