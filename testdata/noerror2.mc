int apple = 1;
int banana = 2;
int grape = 3;
void fruit = 0;

//Check fruit type
int fruitType(int fnum){
	printf("input number\n");
	fruit=7;
	
	if(fnum == fruit)
		return 1;		//true
	else
		return 0;		//false
	endif;
}

//main function
void main(){
	int answer = -1;
	answer = fruitType(1);
	printf("result\n");
}