#include <Python.h>
#include <object.h>
#include <unicodeobject.h>

/**
 * print_python_string - Prints information about Python strings.
 * @p: PyObject string object.
 */
void print_python_string(PyObject *p)
{
    /* Vérifier si p est une chaîne valide */
    if (!PyUnicode_Check(p))
    {
        printf("[.] string object info\n  [ERROR] Invalid String Object\n");
        return;
    }

    /* Afficher les informations sur la chaîne */
    Py_ssize_t length = PyUnicode_GET_LENGTH(p);
    Py_UNICODE *value = PyUnicode_AsUnicode(p);
    const char *type = PyUnicode_IS_COMPACT_ASCII(p) ? "compact ascii" : "compact unicode object";

    printf("[.] string object info\n");
    printf("  type: %s\n", type);
    printf("  length: %ld\n", length);
    printf("  value: %ls\n", value);
}
