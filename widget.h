#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <calculate.h>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    calculate cal;

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_backspace_clicked();
    void on_pushButton_divide_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_factorial_clicked();
    void on_pushButton_left_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_mutiply_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_point_clicked();
    void on_pushButton_right_clicked();
    void on_pushButton_mod_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_pow_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_pi_clicked();
    void on_pushButton_e_clicked();
    void on_pushButton_lg_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_cbrt_clicked();
    void on_pushButton_exp_clicked();
    void on_pushButton_tg_clicked();
    void on_pushButton_abs_clicked();
    void on_pushButton_reverse_clicked();

private:
    Ui::Widget *ui;
    string formula;
    bool havenumber=0;  //havenumber为1时说明输入了数字，此时才能点击运算符，点击运算符会变为0
    bool havebracket=0;  //havebracket为1时说明输入了左括号，当输入右括号后bracket才能变为0
    bool havepoint=0;   //如果前面有输入小数点则变为1
    bool prohibite=0;   //用于保护计算结果，防止被修改
    int left_bracket=0;
    int right_bracket=0;
};
#endif // WIDGET_H
