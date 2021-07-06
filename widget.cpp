#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_0_clicked()
{
    if(prohibite!=1){
   formula.push_back('0');
   ui->Result->insertPlainText("0");
   havenumber=1;}
}

void Widget::on_pushButton_1_clicked()
{
    if(prohibite!=1){
   formula.push_back('1');
   ui->Result->insertPlainText("1");
   havenumber=1;}
}

void Widget::on_pushButton_2_clicked()
{
    if(prohibite!=1){
   formula.push_back('2');
   ui->Result->insertPlainText("2");
   havenumber=1;}
}
void Widget::on_pushButton_3_clicked()
{
    if(prohibite!=1){
   formula.push_back('3');
   ui->Result->insertPlainText("3");
   havenumber=1;}
}
void Widget::on_pushButton_4_clicked()
{
    if(prohibite!=1){
   formula.push_back('4');
   ui->Result->insertPlainText("4");
   havenumber=1;}
}
void Widget::on_pushButton_5_clicked()
{
    if(prohibite!=1){
   formula.push_back('5');
   ui->Result->insertPlainText("5");
   havenumber=1;}
}
void Widget::on_pushButton_6_clicked()
{
    if(prohibite!=1){
   formula.push_back('6');
   ui->Result->insertPlainText("6");
   havenumber=1;}
}
void Widget::on_pushButton_7_clicked()
{
    if(prohibite!=1){
   formula.push_back('7');
   ui->Result->insertPlainText("7");
   havenumber=1;}
}
void Widget::on_pushButton_8_clicked()
{
    if(prohibite!=1){
   formula.push_back('8');
   ui->Result->insertPlainText("8");
   havenumber=1;}
}
void Widget::on_pushButton_9_clicked()
{
    if(prohibite!=1){
    formula.push_back('9');
    ui->Result->insertPlainText("9");
    havenumber=1;}
}

void Widget::on_pushButton_point_clicked()
{
    if(havenumber&&!havepoint&&!formula.empty()&&formula.back()!=')'&&prohibite!=1){
    formula.push_back('.');
    ui->Result->insertPlainText(".");
    havenumber=1;
    havepoint=1;}
}

void Widget::on_pushButton_backspace_clicked()
{
   if((formula.back() >= '0' && formula.back() <= '9') || formula.back() == '.'){
       if(formula.back()=='.')
           havepoint=0;
    formula.pop_back();
    QTextCursor cursor = ui->Result->textCursor();//获取当前光标位置
    cursor.deletePreviousChar();//删除光标前的单个字符
    }
}

void Widget::on_pushButton_divide_clicked()
{
    if(havenumber){
    formula.push_back('/');
    ui->Result->insertPlainText("/");
    havenumber=0;
    havepoint=0;
    prohibite=0;
    }
}

void Widget::on_pushButton_equal_clicked()
{
    if(havenumber&&!havebracket)
    {
    formula.push_back('=');
    ui->Result->clear();
    double b= cal.calculate_it(formula);
    QString a;
    a=QString::number(b);
    ui->Result->insertPlainText(a);
    formula.clear();
    formula+=a.toStdString();
    prohibite=1;  //不能修改结果
    double temp=stod(formula); //判断结果是否为小数
    int temp_1=temp;
    if(temp_1!=temp)
        havepoint=1;
    }
}

void Widget::on_pushButton_factorial_clicked()
{
    bool haveminus=0;
    if(!havepoint&&havenumber){
        for (size_t i = formula.size() - 1; i >=0; i--) {
                 if(!(formula[i] >= '0' && formula[i] <= '9')) {
                     if(formula[i]=='-'&&i==0){
                         haveminus=1;
                         break;}
                     if(formula[i]=='-'&&formula[i-1]=='('){
                         haveminus=1;
                         break;
                     }
                 }
                 if(i==0)break;
         }
        if(!haveminus){
        formula.push_back('!');
        ui->Result->insertPlainText("!");
        prohibite=1;}
    }
}



void Widget::on_pushButton_minus_clicked()
{
    if(havenumber||formula.empty()||havebracket){
    formula.push_back('-');
    ui->Result->insertPlainText("-");
    havenumber=0;
     havepoint=0;
     prohibite=0;
    }
}

void Widget::on_pushButton_mutiply_clicked()
{
    if(havenumber){
    formula.push_back('*');
    ui->Result->insertPlainText("*");
    havenumber=0;
     havepoint=0;
     prohibite=0;
    }
}

void Widget::on_pushButton_plus_clicked()
{
    if(havenumber){
    formula.push_back('+');
    ui->Result->insertPlainText("+");
    havenumber=0;
     havepoint=0;
     prohibite=0;
    }
}

void Widget::on_pushButton_left_clicked()
{
    if(!havenumber||formula.empty()){
    formula.push_back('(');
    ui->Result->insertPlainText("(");
    havebracket=1;
    left_bracket++;
    }
}

void Widget::on_pushButton_right_clicked()
{
    if(havebracket&&havenumber&&(right_bracket<left_bracket)){
    formula.push_back(')');
    ui->Result->insertPlainText(")");
    right_bracket++;
    }
    if(right_bracket==left_bracket)
      havebracket=0;
}

void Widget::on_pushButton_mod_clicked()
{
    if(havenumber){
    formula.push_back('%');
    ui->Result->insertPlainText("%");
    havenumber=0;
     havepoint=0;
     prohibite=0;
    }
}

void Widget::on_pushButton_C_clicked()
{
    formula.clear();
    ui->Result->clear();
    havenumber=0;
    havepoint=0;
    prohibite=0;
    havebracket=0;
}

void Widget::on_pushButton_pow_clicked()
{
    if(havenumber){
    formula.push_back('^');
    ui->Result->insertPlainText("^");
    havenumber=0;
     havepoint=0;
     prohibite=0;
    }
}

void Widget::on_pushButton_sin_clicked()
{
    if(!havenumber){
        formula+="sin(";
        ui->Result->insertPlainText("sin(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_cos_clicked()
{
    if(!havenumber){
        formula+="cos(";
        ui->Result->insertPlainText("cos(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_tan_clicked()
{
    if(!havenumber){
        formula+="tan(";
        ui->Result->insertPlainText("tan(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_pi_clicked()
{
    if(!havepoint){
    formula+="3.1415926";
    ui->Result->insertPlainText("3.1415926");
    havenumber=1;
    prohibite=1;
    havepoint=1;}
}

void Widget::on_pushButton_e_clicked()
{
    if(!havepoint){
    formula+="2.718281828459045";
    ui->Result->insertPlainText("2.718281828459045");
    havenumber=1;
    prohibite=1;
    havepoint=1;}
}

void Widget::on_pushButton_lg_clicked()
{
    if(!havenumber){
        formula+="lg(";
        ui->Result->insertPlainText("lg(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_ln_clicked()
{
    if(!havenumber){
        formula+="ln(";
        ui->Result->insertPlainText("ln(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_sqrt_clicked()
{
    if(!havenumber){
        formula+="sqrt(";
        ui->Result->insertPlainText("sqrt(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_cbrt_clicked()
{
    if(!havenumber){
        formula+="cbrt(";
        ui->Result->insertPlainText("cbrt(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_exp_clicked()
{
    if(havenumber&&prohibite!=1){
    formula.push_back('E');
    ui->Result->insertPlainText("E");
    havenumber=0;
    havepoint=0;
    }
}

void Widget::on_pushButton_tg_clicked()
{
    if(!havenumber){
        formula+="tg(";
        ui->Result->insertPlainText("tg(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_abs_clicked()
{
    if(!havenumber){
        formula+="abs(";
        ui->Result->insertPlainText("abs(");
        havebracket=1;
        havenumber=1;
        left_bracket++;
    }
}

void Widget::on_pushButton_reverse_clicked()
{
    if(havenumber){
        for (size_t i = formula.size() - 1; i >=0; i--) {
                 if(!((formula[i] >= '0' && formula[i] <= '9') || formula[i] == '.')) {
                    if (formula[i] == '-') {
                        if (i == 0) {
                            formula.erase(0,1);
                            break;         //减号在首位判断为负号
                        }
                        if (formula[i - 1] == '(') {
                            formula.erase(i - 1, 2);
                            if (formula.back() == ')')
                                formula.pop_back();
                            left_bracket--;
                            right_bracket--;
                            break;       //减号前有左括号判断为负号
                        }
                        if (formula[i - 1] != '(') {
                            formula.insert(i+1, "(-");
                            formula.push_back(')');
                            left_bracket++;
                            right_bracket++;
                            break;                     //不是负号是减号
                        }
                    }
                    else if (formula[i] == '(') {     //正数前有左括号
                        formula.insert(i + 1, "-");
                        if(formula.back()!=')')
                          formula.push_back(')');
                        break;
                    }
                    else if (formula.back() == ')') {   //跳过右括号
                    }
                    else {                //正数变为负数
                        formula.insert(i+1,"(-");
                        formula.push_back(')');
                        break;
                    }
                }
                 if(i==0){ //字符串中只有数字
                      formula.insert(0, "-");
                      break;
                 }
            }
        ui->Result->clear();
        ui->Result->insertPlainText(QString::fromStdString(formula));
    }
}
