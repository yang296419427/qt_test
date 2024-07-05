#include <pybind11/embed.h> // 引入pybind11的嵌入式解释器
#include <iostream>
#include <QApplication>
#include "qt_test.h"

namespace py = pybind11;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 初始化Python解释器
    py::scoped_interpreter guard{};

    try {
        // 导入Python脚本
        py::module test_script = py::module::import("test_script");

        // 调用Python函数
        test_script.attr("hello")();

    }
    catch (const py::error_already_set& e) {
        std::cerr << "Python error: " << e.what() << std::endl;
    }

    qt_test w;
    w.show();

    return app.exec();
}
