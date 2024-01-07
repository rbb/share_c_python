import numpy as np
import pass_struct

print(pass_struct.add(1, 2))
print(pass_struct.create_struct(2))

myarray = np.array(
    [
        (2296, 1, 0, 10.0, 90.0, 0, 3.0, 0, 0)
        (2296, 2, 0, 10.0, 90.0, 0, 3.0, 0, 0),
        (2296, 3, 0, 10.0, 90.0, 0, 3.0, 0, 0),
    ],
    dtype=pass_struct.diff_rex,
    )
