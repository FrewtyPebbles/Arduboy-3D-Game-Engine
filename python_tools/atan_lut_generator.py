import math

def gen_atan_list(increment = 0.1, end = 12):
    current = 0
    res = []
    i = 0
    try:
        while i*increment < end:
            current = math.atan(i*increment)
            res.append((i*increment, current))
            i += 1
    except KeyboardInterrupt:
        return res

    return res

def generate_atan_lut(table_size=256, precision=16, type_name="int32_t", var_name="ATAN_LUT", atan_inc = 0.1, end = 12):
    """
    Generate a C++ lookup table for atan(x) in [0, pi/2] using fixed-point arithmetic.

    table_size: number of entries in the lookup table
    precision: number of fractional bits
    type_name: integer type to emit (e.g. int32_t)
    var_name: name of the C++ array
    """
    atan_list = gen_atan_list(atan_inc, end)
    atan_list_sample_rate = len(atan_list) // table_size
    scale = 1 << precision
    cpp_lines = []
    cpp_lines.append(f"static const fixed<{type_name}, {precision}> {var_name}_0_TO_{str(end).replace('.', '_POINT_')}[{table_size}] = {{ // as input x approaches {atan_list[-1][0]} lerp x to {atan_list[-1][1]}")

    for i in range(table_size):
        # Domain is 0 .. π/2
        x, y = atan_list[i * atan_list_sample_rate]
        
        fixed_val = int(round(y * scale))
        cpp_lines.append(f"    {fixed_val},  // atan({x}) = {y}")

    cpp_lines.append("};")
    return "\n".join(cpp_lines)

print(generate_atan_lut(40, 11, "int16_t", end= 12, atan_inc= 0.000001))
