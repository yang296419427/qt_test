#include <pybind11/embed.h> // pybind11头文件
#include "qt_test.h"
#include <QDebug>

namespace py = pybind11;

qt_test::qt_test(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 连接按钮点击信号到槽函数
    connect(ui.pushButton, &QPushButton::clicked, this, &qt_test::onButtonClicked);

}

void qt_test::onButtonClicked() {
    // 获取输入框内容
    QString input1Text = ui.num1->text();
    QString input2Text = ui.num2->text();
    //qDebug() << "Input 1:" << input1Text;
    //qDebug() << "Input 2:" << input2Text;

    try {
        // 导入Python脚本
        py::module test_script = py::module::import("test_script");
        //qDebug() << "Python script imported successfully.";

        // 获取Python函数并调用
        auto result = test_script.attr("add")(input1Text.toStdString(), input2Text.toStdString());
        //qDebug() << "Python function object retrieved successfully.";

        // 将结果显示在输出框中
        ui.result->setText(QString::fromStdString(result.cast<std::string>()));
    }
    catch (const std::exception& e) {
        // 处理异常
        ui.result->setText("Error: " + QString::fromStdString(e.what()));
    }
}

qt_test::~qt_test()
{}
