#include <iostream>
#include <string>

const std::string SINGLES[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
                                 "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                 "sixteen", "seventeen", "eighteen", "nineteen"};
const std::string TENS[10] = {"0", "1", "twenty", "thrity", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const std::string LARGE[4] = {"hundred", "thousand", "million", "billion"};
const int THREE_DIGITS = 3;

int charToInt(const char chr)
{
    return chr - '0';
}

std::string toWords(const int number)
{
    std::string as_str = std::to_string(number);
    int length = as_str.size();

    switch (length)
    {
    case 1:
        return SINGLES[number];
    case 2:
        if (number <= 19)
        {
            return SINGLES[number];
        }
        if (number % 10 != 0)
        {
            return TENS[number / 10] + "-" + SINGLES[number % 10];
        }
        return TENS[number / 10];
    default:
        std::string str;
        int i = 0;
        while (length >= THREE_DIGITS)
        {
            if (charToInt(as_str[i]) == 0)
            {
                break;
            }
            str += SINGLES[charToInt(as_str[i])] + " " + LARGE[length - THREE_DIGITS - i];
            i++;
            length--;
        }
        // check if there are anything less than 100 to write
        if (number % 100 != 0)
            str += " and " + toWords(number % 100);
        return str;
    }
}

int countLetters(const std::string& str)
{
    int count = 0;
    for (const auto& chr : str)
    {
        if (chr >= 'a' && chr <= 'z')
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv)
{
    int words = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        words += countLetters(toWords(i));
    }
    std::cout << words << std::endl;
}