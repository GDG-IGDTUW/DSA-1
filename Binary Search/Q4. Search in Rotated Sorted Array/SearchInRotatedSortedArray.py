def SearchInRotatedSortedArray(arr, target):
    st = 0
    end = len(arr) - 1
    mid = (st + end) // 2
    while st <= end:
        if arr[mid] == target:
            return mid  # Target found
        
        elif arr[mid] >= arr[0]:  # Left half is sorted
            if target >= arr[0] and target < arr[mid]:
                end = mid - 1
            else:
                st = mid + 1
        
        else:  # Right half is sorted
            if target > arr[mid] and target <= arr[end]:
                st = mid + 1
            else:
                end = mid - 1
        
        mid = (st + end) // 2  # Update mid
    
    return -1  # Target not found


# Taking input from the user
length=int(input("Enter length of array: "))
arr=[]
for i in range(length):
  arr.append(int(input("Enter element: ")))
target = int(input("Enter target: "))

# Calling the function
index = SearchInRotatedSortedArray(arr, target)
print("Target index = ",index)
