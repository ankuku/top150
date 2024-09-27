# 26. Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
- Return k.


## Personal note:

One way to think this problem is to return the Pythonic set of the array. A Pythonic set is the unique elements contained in a list/array.

### Update:
Turns out, nope. This is not a "set" problem. The problem has a qualifier where it wants to check the "in-place" substituted numbers, reasosn of which I do not fully understand at this moment.