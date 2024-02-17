#include <iostream> // for basic input / output
#include <cmath> // for std::pow(base, exp)
#include <cctype> // for std::tolower()
#include <vector> // for fibonacci

#ifndef _WIN32
    #ifndef _WIN64
        const std::string os = "non-windows";
    #else
        const std::string os = "windows";
    #endif
#else
    const std::string os = "windows";
#endif

typedef long long int lli;

class Calculator {
    public:

    inline static auto add = [](lli num1, lli num2)->lli {return num1 + num2;};
    inline static auto sub = [](lli num1, lli num2)->lli {return num1 - num2;};
    inline static auto multi = [](lli num1, lli num2)->lli {return num1 * num2;};
    inline static auto div = [](lli num1, lli num2) {if (num1 == 0 || num2 == 0) {throw std::runtime_error("ZeroDivisionError");} else {return num1 / num2;}};
    inline static auto mod = [](lli num1, lli num2)->lli {return num1 % num2;};

    static std::vector<lli> fibonacci(int n) {
        std::vector<lli> fibonacciSeq;
        if (n >= 1) {
            fibonacciSeq.push_back(0);
        }
        if (n >= 2) {
            fibonacciSeq.push_back(1);
        }
        for (int i = 2; i < n; ++i) {
            lli next = fibonacciSeq[i - 1] + fibonacciSeq[i - 2];
            fibonacciSeq.push_back(next);
        }
        return fibonacciSeq;
    }

    static void print_fibonacci(int n) {
        std::vector<lli> fibonacci_nums = fibonacci(n);

        for (lli num : fibonacci_nums) {
            std::cout << num << " ";
        }
    }

    static lli factorial(lli n) {
        if (n <= 0) {
            std::cout << "Factorial is undefined for non-positive integers";
            exit(1);
        } else if (n == 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
};

std::string toLowercase(const std::string &str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

int main(int argc, char **argv, char **envp) {

    std::cout << "Enter choice: ";

    std::string userInput;
    std::getline(std::cin, userInput);

    std::string lUserInput = toLowercase(userInput);

    if (lUserInput == "fibonacci") {
        std::cout << "Enter n: ";
        int n;
        std::cin >> n;
        std::cout << "Fibonacci series up till " << n << " are: ";
        Calculator::print_fibonacci(n);
        
    } else if (lUserInput == "factorial") {
        std::cout << "Enter n: ";
        lli n;
        std::cin >> n;
        std::cout << "Factorial of " << n << " is " << Calculator::factorial(n) << std::endl;
    } else if (lUserInput == "exponent") {
        std::cout << "Enter base: ";
        lli base;
        std::cin >> base;
        std::cout << "Enter exp: ";
        lli exp;
        std::cin >> exp;
        lli result = std::pow(base, exp);
        std::cout << "Result: " << result << std::endl;
    } else if (lUserInput == "add") {
        std::cout << "Enter first number: ";
        lli fNum;
        std::cin >> fNum;
        std::cout << "Enter second number: ";
        lli sNum;
        std::cin >> sNum;
        std::cout << "Result: " << Calculator::add(fNum, sNum) << std::endl;
    } else if (lUserInput == "sub") {
        std::cout << "Enter first number: ";
        lli fNum;
        std::cin >> fNum;
        std::cout << "Enter second number: ";
        lli sNum;
        std::cin >> sNum;
        std::cout << "Result: " << Calculator::sub(fNum, sNum) << std::endl;
    } else if (lUserInput == "multi") {
        std::cout << "Enter first number: ";
        lli fNum;
        std::cin >> fNum;
        std::cout << "Enter second number: ";
        lli sNum;
        std::cin >> sNum;
        std::cout << "Result: " << Calculator::multi(fNum, sNum) << std::endl;
    } else if (lUserInput == "div") {
        std::cout << "Enter first number: ";
        lli fNum;
        std::cin >> fNum;
        std::cout << "Enter second number: ";
        lli sNum;
        std::cin >> sNum;
        try {
            std::cout << "Result: " << Calculator::div(fNum, sNum) << std::endl;
        } catch (const std::runtime_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
            exit(1);
        }
    } else if (lUserInput == "mod") {
        std::cout << "Enter first number: ";
        lli fNum;
        std::cin >> fNum;
        std::cout << "Enter second number: ";
        lli sNum;
        std::cin >> sNum;
        std::cout << "Result: " << Calculator::mod(fNum, sNum) << std::endl;
    } else {
        std::cout << "Invalid choice" << std::endl;
        exit(1);
    }

    if (os == "windows") {
        system("pause");
    } else {
        system("read -p \"Press Enter to continue...\"");
    }

    return 0;
}
