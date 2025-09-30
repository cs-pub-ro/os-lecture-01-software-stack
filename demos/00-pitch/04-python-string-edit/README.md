# Python string vs bytearray

Python strings are immutable.
Write / append operations with strings imply allocating a new string.

Demonstrate the alternative of using [Python `byterray`](https://docs.python.org/3/library/stdtypes.html#bytearray) for frequent write operations.
`bytearray` is a mutable data type in Python.

Sample run:

```console
$ python string_vs_bytearray.py
Time for string concatenation: 0.2166 seconds
Time for bytearray modifications: 0.1397 seconds
```
