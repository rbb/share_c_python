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
