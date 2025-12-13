import math

def generate_sin_lut(table_size=256, precision=16, type_name="int32_t", var_name="SIN_LUT"):
    """
    Generate a C++ lookup table for sin(x) in [0, pi/2] using fixed-point arithmetic.
    
    table_size: number of entries in the lookup table
    precision: number of fractional bits in the fixed point format
    type_name: C++ integer type (e.g. int32_t)
    var_name: name of the generated C++ array
    """
    
    scale = 1 << precision
    cpp_lines = []
    cpp_lines.append(f"static const fixed<{type_name}, {precision}> {var_name}[{table_size}] = {{")

    for i in range(table_size):
        x = (math.pi / 2) * (i / (table_size - 1))
        fx = math.sin(x)
        fixed_val = int(round(fx * scale))
        cpp_lines.append(f"    {fixed_val},  // sin({i}/{table_size-1} * pi/2)")

    cpp_lines.append("};")
    return "\n".join(cpp_lines)

print(generate_sin_lut(40, 12, "int16_t"))

