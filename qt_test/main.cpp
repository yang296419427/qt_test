#include <pybind11/embed.h> // ����pybind11��Ƕ��ʽ������
#include <iostream>
#include <QApplication>
#include "qt_test.h"

namespace py = pybind11;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // ��ʼ��Python������
    py::scoped_interpreter guard{};

    try {
        // ����Python�ű�
        py::module test_script = py::module::import("test_script");

        // ����Python����
        test_script.attr("hello")();

    }
    catch (const py::error_already_set& e) {
        std::cerr << "Python error: " << e.what() << std::endl;
    }

    qt_test w;
    w.show();

    return app.exec();
}
