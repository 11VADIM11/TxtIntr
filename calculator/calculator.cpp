#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

void print_usage()
{
    std::cout << "Usage: calculator -o operation operand1 operand2 [operand3] [operand4]\n";
    std::cout << "Supported operations: multiplication, division\n";
    exit(0);
}

// Проверка, является ли строка допустимым числом (целым или дробным)
bool is_number(const std::string& str)
{
    std::istringstream iss(str);
    double d;
    char c;
  
    if(!(iss >> d) || (iss >> c)) {
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    if(argc < 5) { // Минимум 5 аргументов (операция + 2 операнда)
        print_usage();
    }

    std::string operation;
    std::vector<double> operands;
    bool operation_found = false;

    // Разбор аргументов командной строки
    for(int i = 1; i < argc; ++i) {
        if(std::strcmp(argv[i], "-o") == 0 || std::strcmp(argv[i], "--operation") == 0) {
            if(operation_found) {
                std::cerr << "Error: Only one operation can be specified.\n";
                exit(1);
            }
            if(i + 1 < argc) {
                operation = argv[i + 1];
                operation_found = true;
                i++; // Пропустить имя операции
            } else {
                print_usage();
            }
        } else {
            if(operands.size() < 4) { // Максимум 4 операнда, минимум 2
                std::string operand_str = argv[i];
                if(is_number(operand_str)) {
                    operands.push_back(std::stod(operand_str));
                } else {
                    std::cerr << "Error: Operand '" << operand_str << "' is not a valid number.\n";
                    exit(1);
                }
            } else {
                print_usage();
            }
        }
    }

    // Проверка, что операция задана и количество операндов корректное
    if(operation.empty() || operands.size() < 2 || operands.size() > 4) {
        print_usage();
    }

    // Выполнение операций
    if(operation == "multiplication") {
        double result = operands[0];
        for(size_t i = 1; i < operands.size(); ++i) {
            result *= operands[i];
        }
        std::cout << "Result: " << result << std::endl;
    } else if(operation == "division") {
        double result = operands[0];
        for(size_t i = 1; i < operands.size(); ++i) {
            if(operands[i] == 0) {
                std::cerr << "Error: Division by zero is not allowed.\n";
                exit(1);
            }
            result /= operands[i];
        }
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cerr << "Error: Unsupported operation '" << operation << "'.\n";
        print_usage();
    }

    return 0;
}
