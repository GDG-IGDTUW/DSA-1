def peak(arr):
  if len(arr)==1:
    return 0

  if arr[0]>arr[1]:
    return 0
  
  if arr[len(arr)-1]>arr[len(arr)-2]:
    return len(arr)-1
  
  st=0
  end=len(arr)-1
  mid=(st+end)//2

  while st<=end:
    if arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]:
      return mid

    elif arr[mid]<arr[mid-1] and arr[mid]>arr[mid+1]: 
      end=mid-1
    
    elif arr[mid]<arr[mid+1] and arr[mid]>arr[mid-1]:
      st=mid+1

    else:
      st=mid+1
    
    mid=(st+end)//2

  return -1  


length=int(input("Enter length of array: "))
arr=[]
for i in range(length):
  arr.append(int(input("Enter element: ")))

# Calling the function
peakele = peak(arr)
print("peak element index = ", peakele)
