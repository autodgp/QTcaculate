#ifndef CALCULATE_H
#define CALCULATE_H
#include <QStack>
#include <QString>
#include <iostream>
#include <string>
using namespace std;

class calculate
{
public:
    calculate();
    double calculate_it(string s);
private:
    QStack<double>m_num;
    QStack<char>m_opr;
    string formula;

    int precedence(const char& s)const;
    bool isnum(string::const_iterator& c)const {
          return (*c >= '0' && *c <= '9') || *c == '.';
    }
    double readnum(string::const_iterator& it);
    string& replace_opr(string& str, const string& old_value, const string& new_value)
    {
        string::size_type pos = 0;
        while ((pos = str.find(old_value, pos)) != string::npos)
        {
            str = str.replace(pos, old_value.length(), new_value);
            if (new_value.length() > 0)
            {
                pos += new_value.length();

            }
        }
        return str;
    }
    void change_minus(string &s);
};

#endif // CALCULATE_H
