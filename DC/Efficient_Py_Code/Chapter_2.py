# Create a list of integers (0-50) using list comprehension
nums_list_comp = [num for num in range(51)]
print(nums_list_comp)

# Create a list of integers (0-50) by unpacking range
nums_unpack = [*(nums_list_comp)]
print(nums_unpack)

"""
Code profiling

Get detailed analysis without timeit magic commands
"""

# looks like this:

%load_ext line_profiler 
# or
%lprun -f convert_units(heroes, hts, wts)


"""
Code profiling for memory usage

Get detailed memory consumption analysis with sys module
"""
impot sys

%load_ext memory_profiler

%mprun -f convert_units convert_units(heroes, hts, wts)





