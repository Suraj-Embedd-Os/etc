arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::1 low::0 high::9 mid::4 
arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::2 low::0 high::4 mid::2 
arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::3 low::0 high::2 mid::1 
arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::4 low::0 high::1 mid::0 

return arr[lo] step::5 low::0 high::0 
return arr[lo] step::6 low::1 high::1 
return arr[lo] step::7 low::2 high::2 

arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::8 low::3 high::4 mid::3 
return arr[lo] step::9 low::3 high::3 
return arr[lo] step::10 low::4 high::4 

arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::11 low::5 high::9 mid::7 
arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::12 low::5 high::7 mid::6 
arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::13 low::5 high::6 mid::5 
return arr[lo] step::14 low::5 high::5 
return arr[lo] step::15 low::6 high::6 
return arr[lo] step::16 low::7 high::7 

arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi) step::17 low::8 high::9 mid::8 
return arr[lo] step::18 low::8 high::8 
return arr[lo] step::19 low::9 high::9