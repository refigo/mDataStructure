#include "sort.h"

void    quickSort(int *data, int size)
{
    int left;
    int right;
    int pivot;

    displayArray(data, size);
    if (size < 2)
        return ;
    left = 0;
    right = size - 1;
    pivot = data[right];
    while (left != right)
    {
        if (data[left] < pivot)
            left += 1;
        if (data[right] >= pivot)
            right -= 1;
        if (pivot < data[left] && pivot > data[right])
            swap(data, left, right);
    }
    if (pivot < data[left])
        swap(data, left, size - 1);
    displayArray(data, size);
    if (data[size - 1] == pivot)
    {
        quickSort(data, size - 1);
    }
    else
    {
        quickSort(data, left);
        quickSort(&data[left + 1], size - left - 1);
    }
}