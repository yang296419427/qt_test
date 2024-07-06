#include <pybind11/embed.h> 
#include <iostream>
#include <QApplication>
#include "qt_test.h"


namespace py = pybind11;

int main(int argc, char* argv[]) {
    // 初始化 Python 解释器
    py::scoped_interpreter guard{};
    QApplication app(argc, argv);
    qt_test w;
    w.show();

    return app.exec();
}
