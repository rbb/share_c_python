#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <iostream>
//#include <fstream>
#include <string>
#include <map>
#include <array>
#include <cstdio>

//#include "numpy/arrayobject.h" // Include any other Numpy headers, UFuncs for example.

//#include <Python.h>
#include <stdio.h>
#include "numpy/ndarraytypes.h"
#include "numpy/ufuncobject.h"
#include "numpy/npy_3kcompat.h"

// Module method definitions
static PyObject* hello_world_c(PyObject *self, PyObject *args) {
    printf("Hello, world!\n");
    Py_RETURN_NONE;
}

struct diff_record {
  int week;
  int time;
  int sv;
  float el;
  float az;
  int freq;
  float cno_diff;
  int ref_ant;
  int dut_ant;
};


static PyObject* hello_numpy_c(PyObject *dummy, PyObject *args)
{
    PyObject *arg1=NULL;
    PyObject *arr1=NULL;
    int nd;

    if (!PyArg_ParseTuple(args, "O", &arg1))
        return NULL;

    //arr1 = PyArray_FROM_OTF(arg1, NPY_DOUBLE, NPY_IN_ARRAY);
    arr1 = PyArray_FROM_O(arg1);
    printf("Got arr1\n");
    /*
     * my code starts here
     */
    nd=PyArray_NDIM(arr1);
    printf("Got nd = %d\n", nd);

    //npy_intp *sp=PyArray_SHAPE(arr1);  // C Version
    PyArrayObject * np_arr1 = (PyArrayObject*)(arr1); // C++ Version
    printf("Got np_arr1\n");

    int type = PyArray_TYPE(np_arr1);
    printf("Got type = %d\n", type);

    PyArray_Descr *descr = PyArray_DESCR(np_arr1);
    printf("Got descr\n");
    printf("    kind = %d\n", descr->kind);
    printf("    type = %d\n", descr->type);
    printf("    elsize = %d\n", descr->elsize);

    npy_intp *sp=PyArray_DIMS(np_arr1);              // C++ Version
    for (int i=0; i<nd; i++) {
      printf("array length in dimension %d: %ld\n", i, sp[i]);
    }

    printf("Print array elements:\n");
    for (int i=0; i<*sp; i++)
    {
        printf("%lf ",*((npy_double*)PyArray_GETPTR1(arr1,i)));
    }

    printf("\n");

    if (arr1 == NULL)
        return NULL;

    nd = PyArray_NDIM(arr1);   //number of dimensions
    printf("Got nd = %d\n", nd);

    Py_DECREF(arr1);

    return PyInt_FromLong(nd);
}


static PyMethodDef hello_methods[] = {
        {
                "hello_python", hello_world_c, METH_VARARGS,
                "Print 'hello xxx'"
        },
        {
                "hello_numpy", hello_numpy_c, METH_VARARGS,
                "numpy function tester",
        },
        {NULL, NULL, 0, NULL}
};


static struct PyModuleDef hello_definition = {
        PyModuleDef_HEAD_INIT,
        "hello",
        "A Python module that prints 'hello world' from C code.",
        -1,
        hello_methods
};


PyMODINIT_FUNC PyInit_hello(void) {
    Py_Initialize();
    import_array();
    return PyModule_Create(&hello_definition);
}

/*
// Initialise Numpy
import_array();
if (PyErr_Occurred()) {
    std::cerr << "Failed to import numpy Python module(s)." << std::endl;
    return NULL; // Or some suitable return value to indicate failure.
}

assert(PyArray_API);


static PyObject *
example_wrapper(PyObject *dummy, PyObject *args)
{
    PyObject *arg1=NULL, *arg2=NULL, *out=NULL;
    PyObject *arr1=NULL, *arr2=NULL, *oarr=NULL;

    if (!PyArg_ParseTuple(args, "OOO!", &arg1, &arg2,
        &PyArray_Type, &out)) return NULL;

    arr1 = PyArray_FROM_OTF(arg1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    if (arr1 == NULL) return NULL;
    arr2 = PyArray_FROM_OTF(arg2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
    if (arr2 == NULL) goto fail;
    #if NPY_API_VERSION >= 0x0000000c
    oarr = PyArray_FROM_OTF(out, NPY_DOUBLE, NPY_ARRAY_INOUT_ARRAY2);
    #else
    oarr = PyArray_FROM_OTF(out, NPY_DOUBLE, NPY_ARRAY_INOUT_ARRAY);
    #endif
    if (oarr == NULL) goto fail;

    // code that makes use of arguments
    // You will probably need at least
    // nd = PyArray_NDIM(<..>)    -- number of dimensions
    // dims = PyArray_DIMS(<..>)  -- npy_intp array of length nd
    //                               showing length in each dim.
    // dptr = (double *)PyArray_DATA(<..>) -- pointer to data.
    //
    // If an error occurs goto fail.
    //

    Py_DECREF(arr1);
    Py_DECREF(arr2);
    #if NPY_API_VERSION >= 0x0000000c
    PyArray_ResolveWritebackIfCopy(oarr);
    #endif
    Py_DECREF(oarr);
    Py_INCREF(Py_None);
    return Py_None;

 fail:
    Py_XDECREF(arr1);
    Py_XDECREF(arr2);
    #if NPY_API_VERSION >= 0x0000000c
    PyArray_DiscardWritebackIfCopy(oarr);
    #endif
    Py_XDECREF(oarr);
    return NULL;
}
*/
