import hello
import numpy as np

"""
df.astype({
    "Week":'int32',
    "Time":'int32',
    "SV":'int16',
    "El":'float32',
    "Az":'float32',
    "Freq":'int32',
    "CNoDiff":'float32',
    "ref_ant":'int8',
    "dut_ant":'int8',
    })
"""

"""
Week,Time,SV,El,Az,Freq,Track,CNoDiff,ref_ant,dut_ant
2289, 245101000, 3, 42.000, 199.750, L1, 0, 0.1, 1, 1
2289, 245101000, 3, 42.000, 199.750, L2, 5, -1.6, 1, 1
2289, 245101000, 3, 42.000, 199.750, L5/E5A, 8, 0.5, 1, 1
"""

hello.hello_python()
hello.hello_numpy(
        #np.array([1,2,3])
        #np.array([[1, 2, 3], [4, 5, 6]], np.int32)
        np.array([2289, 245101000, 3, 42.000, 199.750, 0, 0, 0.1, 1, 1],
                 dtype='i, i, i, f, f, i, i, f, i, i')
        )
