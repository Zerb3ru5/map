# include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(map, m) {
    m.doc() = "map\n---\nSimulate physics easily";

    m.def("add", &add, "Add two numbers");

    m.def("subtract", [](int i, int j) { return i - j; }, "Subtract two numbers");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
