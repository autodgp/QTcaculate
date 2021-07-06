#include "calculate.h"

calculate::calculate()
{

}

void calculate::change_minus(string &s){
    for(string::size_type i=0;i<s.size();i++){     //检测到"-"号时，如果前面是左括号或者处于字符串首位，则判断为负号
        if(s[i]=='-'&&(i==0||s[i-1]=='(')){
            s[i]='~';
        }
     }
}

int calculate::precedence(const char& s) const
{
    switch (s) {
    case'=': return 0;
    case'#':case'(':case')':return 1;
    case'+':case'-':return 2;
    case'*':case'/':case'~':return 3;
    case'%':case'^':case'E':return 4;
    case's':case'c':case't':case'q':case'!':case'n':case'g':case'b':case'a':case'f':return 5;
    }
}

double calculate::readnum(string::const_iterator& it)
{
    string t;
    while (isnum(it))
        t += *it++;
    return stod(t);

}

double calculate::calculate_it(string s)
{
    change_minus(s);
    replace_opr(s, "sin", "s");
    replace_opr(s, "sin", "c");
    replace_opr(s, "tan", "t");
    replace_opr(s, "sqrt", "q");
    replace_opr(s, "cbrt", "b");
    replace_opr(s, "lg", "g");
    replace_opr(s, "ln", "n");
    replace_opr(s, "tg", "a");
    replace_opr(s, "abs", "f");
    m_opr.push('#');
    m_num.clear();
    double a, b;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (isnum(it))      //读取数字
            m_num.push(readnum(it));
        if (!isnum(it)) {      //读取运算符以及运算
            if (precedence(*it) > precedence(m_opr.top()) || *it == '(')
                m_opr.push(*it);
            else {
                while (precedence(*it) <= precedence(m_opr.top())) {
                    if (m_opr.top() == '#' && *it == '=') {
                        m_opr.pop();
                        return m_num.top();
                    }
                    else if (m_opr.top() == '(' && *it == ')') {
                        ++it;
                    }//当左右括号相遇时，跳过右括号，删除左括号
                    else {
                        a = m_num.top();
                        m_num.pop();
                        if (m_opr.top() == '+') {
                            b = m_num.top();
                            m_num.pop();
                            b += a;
                            m_num.push(b);
                        }
                        else if (m_opr.top() == '-') {
                            b = m_num.top();
                            m_num.pop();
                            b -= a;
                            m_num.push(b);
                        }
                        else if (m_opr.top() == '*') {
                            b = m_num.top();
                            m_num.pop();
                            b *= a;
                            m_num.push(b);
                        }
                        else if (m_opr.top() == '/') {
                            b = m_num.top();
                            m_num.pop();
                            b /= a;
                            m_num.push(b);
                        }
                        else if (m_opr.top() == '^') {
                            b = m_num.top();
                            m_num.pop();
                            m_num.push(pow(b, a));
                        }
                        else if (m_opr.top() == '%') {
                            b = m_num.top();
                            m_num.pop();
                            m_num.push(fmod(b, a));
                        }
                        if (m_opr.top() == 'E') {
                            b = m_num.top();
                            m_num.pop();
                            b=b*pow(10,a);
                            m_num.push(b);
                        }
                        else if (m_opr.top() == 's') {
                            a = sin(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 'c') {
                            a = cos(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 't') {
                            a = tan(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 'a') {
                            a = atan(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 'q') {
                            a = sqrt(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 'n') {
                            a = log(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 'g') {
                            a = log10(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 'b') {
                            a = cbrt(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == 'f') {
                            a = fabs(a);
                            m_num.push(a);
                        }
                        else if (m_opr.top() == '~') {
                            a = -a;
                            m_num.push(a);
                        }
                        else if (m_opr.top() == '!') {
                            for(int i=a-1;i>0;i--)
                                a*=i;
                            m_num.push(a);
                        }
                    }
                    m_opr.pop();
                }//运算符优先级小于之前的，将前面的先计算
                m_opr.push(*it);
            }
        }
    }
}
