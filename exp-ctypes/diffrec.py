# Based on "Heterogeneous Types Example" from:
# https://scipy-cookbook.readthedocs.io/items/Ctypes.html

import numpy as np
import ctypes

dat = [[2289, 245101000, 3, 42.000, 199.750, 0.1],
       [2289, 245101000, 4, 42.000, 199.750, 0.2],
       ]

diffrec_dtype = np.dtype([
    ('week','i'),
    ('time','i'),
    ('sv','i'),
    ('el','f'),
    ('az','f'),
    ('cno_diff','f'),
    ])
arr = np.rec.fromrecords(dat,dtype=diffrec_dtype)

_diffrec = np.ctypeslib.load_library('libdiffrec','.')
_diffrec.print_diff_rec.restype = None
_diffrec.print_diff_rec.argtypes = [
    np.ctypeslib.ndpointer(diffrec_dtype, flags='aligned, contiguous'),
    ctypes.c_int
    ]
_diffrec.sim_diff.restype = ctypes.c_int
_diffrec.sim_diff.argtypes = [
    np.ctypeslib.ndpointer(diffrec_dtype, flags='aligned, contiguous'),
    ctypes.c_int_p
    ]


def print_diff(x):
    _diffrec.print_diff_rec(x, x.size)

def sim_diff():
    sim_arr = np.rec.fromrecords([],dtype=diffrec_dtype)
    print(f"{sim_arr.size=}")
    _diffrec.simulate_diff(sim_arr, ctypes.byref(sim_arr.size))
    print(f"{sim_arr.size=}")
    print("sim diff:")


if __name__=='__main__':
    print_diff(arr)
    sim_diff()
