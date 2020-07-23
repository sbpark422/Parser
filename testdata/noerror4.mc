int fib2(int n) {

	int arr[100] , i;

	if (n < 2)
		return n;

	else {
		arr[0] = 0;
		arr[1] = 1;
		i = 2;
		while(i<=n) {
			arr[i] = arr[i - 1] + arr[i - 2];
 			i++;
		}
	}
	
	endif;

	return arr[n];

}