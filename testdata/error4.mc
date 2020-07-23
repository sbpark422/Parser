int (int n) {   //NOFUNCNAME

	int arr[100] , i;
	char $apple;                     //ILLEGALCHAR

	if (n < 2 )
		return n;

	else {
		arr[0] = 0;
		arr[1] = 1;
		2 = i;  			//2=i (X) i=2 (O) INVALIDASSIGN
		while(i<=n) {   
			arr[i] = arr[i - 1] + arr[i - 2];
 			i++;
		}
	}
	
	endif;

	return arr[n];

}