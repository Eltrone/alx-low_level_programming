#!/usr/bin/python3

def find_peak(list_of_integers):
    """
    Find a peak in a list of unsorted integers
    Trouve un pic dans une liste d'entiers non triés
    """
    if not list_of_integers:
        return None

    def peak_helper(start, end, nums):
        if start == end:
            return nums[start]

        mid = (start + end) // 2
        if nums[mid] < nums[mid + 1]:
            return peak_helper(mid + 1, end, nums)
        else:
            return peak_helper(start, mid, nums)

    return peak_helper(0, len(list_of_integers) - 1, list_of_integers)
