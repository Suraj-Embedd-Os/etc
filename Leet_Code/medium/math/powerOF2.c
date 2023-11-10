
/*
	power of 2 in any number means there only binary number '1' in any number.
	
	so if n=4
	the 4 & (4-1)==0, then 4 is square of 2
	if n=5
		5 & (5-1) ==1 ,5 is not square of 2
*/

bool isPowerOfTwo(int n){

 return n<1?false :(n & (n-1) )==0?true:false;

}