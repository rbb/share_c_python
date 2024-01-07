# Experiments in passing data between python and C++

These are some experiments in passing data between C++ and python

* numpy-c-api: This uses the native Numpy C-API to pass data
* exp-ctypes: This uses cython and ctypes to pass data

# Rurther Reading:

* Stackoverflow: [Passing a C++ std::Vector to numpy array in Python](https://stackoverflow.com/questions/18780570/passing-a-c-stdvector-to-numpy-array-in-python)
* Stackoverflow: [Passing 2 dimensional C array to python numpy](https://stackoverflow.com/questions/27940848/passing-2-dimensional-c-array-to-python-numpy)
* [ndarray](https://ndarray.github.io/ndarray/): NumPy-friendly multidimensional arrays in C++
* Numpy docs: [Using NumPy C-API](https://numpy.org/doc/stable/user/c-info.html)
* Numpy Dev Docs: [Status of numpy.distutils and migration advice](https://numpy.org/doc/stable/user/c-info.html)
* Gist: [A template of writing C or C++ extension for python and numpy](https://gist.github.com/kanhua/8f1eb7c67f5a031633121b6b187b8dc9#file-test_mod-py)
   * This is the basis for the stuff in `numpy-c-api/`
* All found examples use distutils, which is deprecated in favor of setuputils
   * Stackoverflow: How to build a [C extension in keeping with PEP 517](https://stackoverflow.com/questions/66157987/how-to-build-a-c-extension-in-keeping-with-pep-517-i-e-with-pyproject-toml-ins), i.e. with pyproject.toml instead of setup.py?
* Found [setuptools](https://setuptools.pypa.io/en/latest/userguide/ext_modules.html#) example
* [pybind11](https://github.com/pybind/pybind11) and [docs](https://pybind11.readthedocs.io/en/latest/)
   * [Structured types](https://pybind11.readthedocs.io/en/stable/advanced/pycpp/numpy.html#structured-types)
   * [More on working with numpy arrays](https://people.duke.edu/~ccc14/cspy/18G_C++_Python_pybind11.html#More-on-working-with-numpy-arrays)
      * this shows how to have python allocate the return vector
   * [NumPy Support](https://pybind11-jagerman.readthedocs.io/en/stable/advanced.html#numpy-support)
   * [Not clear how to expose existing C++ vector as numpy array](https://github.com/pybind/pybind11/issues/1042)
   * [Return an std::vector to python as a numpy array](https://stackoverflow.com/questions/58756764/return-an-stdvector-to-python-as-a-numpy-array)
   * According to [this](https://stackoverflow.com/questions/69831285/pybind11-how-to-pass-an-n-dimentional-numpy-array-from-python-c),
     We should probably consider using the [Eigen library](https://gitlab.com/libeigen/eigen) on the C++ side,
     as it knows how to deal with 2D arrays.
   * [Pybind Numpy access 2D / ND arrays](https://stackoverflow.com/questions/49582252/pybind-numpy-access-2d-nd-arrays)
     expands on the basic 1D example, by using  `idx*Y + idy` for the indexes
   * Another, more condenced example of modifying an array
   * From this [example](https://github.com/pybind/pybind11/issues/2149)

     C++:

         ```
         struct a_t
         {
             int b[10];
         };

         py::class_<a_t>(m, "a_t")
               .def(py::init())
               .def_property_readonly("b", [](py::object& obj) {
                      a_t& o = obj.cast<a_t&>(); // must be 'cast<a_t&>'
                      return py::array{10, o.b, obj};
                  }
               );
         ```

      Python:
         ```
         obj = a_t()
         obj.b[0] = 0
         obj.b[1] = 9
         ```
