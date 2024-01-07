//#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

typedef struct A_ {
    int x;
    double y;
} typeA;
typeA A={0};

typedef struct diff_rec_ {
  short week;
  short time;
  unsigned char sv;
  float el;
  float az;
  unsigned char freq;
  float diff;
  unsigned char ref_ant;
  unsigned char dut_ant;
} diff_rec;


int add(int i, int j) { return i+j; }

typeA* create_struct(int x) {
    //auto buf = input1.request();
    //A *ptr = (A *) buf.ptr;
    //ptr->y = (float)ptr->x * (float)ptr->x;
    A.x = x
    A.y = (float)x * (float)x;
    return &A;
}

py::array_t<diff_rec> create_array(int len) {
    //auto buf1 = input1.request();
    //auto buf2 = input2.request();

    #define NDIM 1
    auto result = py::array(py::buffer_info(
        nullptr,                                /* Pointer to data (nullptr -> ask NumPy to allocate!) */
        sizeof(diff_rec),                       /* Size of one item */
        py::format_descriptor<diff_rec>::value, /* Buffer format */
        NDIM,                                   /* How many dimensions? */
        { len },                                /* Number of elements for each dimension */
        { sizeof(diff_rec) }                    /* Strides for each dimension */
    ));

    auto buf3 = result.request();

    //double *ptr1 = (double *) buf1.ptr,
    //       *ptr2 = (double *) buf2.ptr;
    diff_rec *ptr3 = (diff_rec *) buf3.ptr;

    unsigned char freq=0;
    for (size_t i=0; i<buf3.shape[0]; i++)
        ptr3[i].week = 2296;
        ptr3[i].time = i;
        ptr3[i].sv = 0;
        ptr3[i].el = 10.0;
        ptr3[i].az = 90.0;
        ptr3[i].freq = 0;
        ptr3[i].diff = 3.0 + (float)i;
        ptr3[i].ref_ant = 0;
        ptr3[i].dut_ant = 0;

    return result;
}

PYBIND11_MODULE(example, m) {

    PYBIND11_NUMPY_DTYPE(A, x, y);
    PYBIND11_NUMPY_DTYPE(diff_rec,
                         week, time, sv, el, az, freq, diff, ref_ant, dut_ant
                         );
    /* now both A and B can be used as template arguments to py::array_t */
    m.doc() = "pybind11 example"; // optional module docstring
    m.def("create_struct", &create_struct, "A function that create an array of structs")
    m.def("create_array", &create_array, "A function that create an array of structs")
    m.def("add", &add, "a function to add integers")
}
