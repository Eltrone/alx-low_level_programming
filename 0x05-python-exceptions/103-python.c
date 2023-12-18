#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

void print_python_list(PyObject *p)
{
    long unsigned int size, alloc, i;  // Modifiez ici
    const char *type;

    printf("[*] Python list info\n");
    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_GET_SIZE(p);
    alloc = ((PyListObject *)p)->allocated;
    printf("[*] Size of the Python List = %lu\n", size);
    printf("[*] Allocated = %lu\n", alloc);

    for (i = 0; i < size; i++)  // i est maintenant du même type que size
    {
        type = Py_TYPE(PyList_GetItem(p, i))->tp_name;
        printf("Element %lu: %s\n", i, type);  // Utilisez %lu pour i
    }
}

void print_python_bytes(PyObject *p)
{
    char *string;
    Py_ssize_t size, i, max;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    string = PyBytes_AsString(p);
    max = size < 10 ? size + 1 : 10;

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", string);
    printf("  first %zd bytes:", max);

    for (i = 0; i < max; i++)
        printf(" %02x", (unsigned char)string[i]);
    printf("\n");
}

void print_python_float(PyObject *p)
{
    double value;

    printf("[.] float object info\n");
    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    value = PyFloat_AsDouble(p);
    printf("  value: %g\n", value);
}
