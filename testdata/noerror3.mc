int add(int a, int b)   
{
    return a + b;   
}

int sub(int a, int b)
{
    return a - b;   
}

int main()
{
    int arr[2];

    arr[0] = add(10, 20);     
    arr[1] = sub(10, 20); 

    printf("%d %d\n", arr[0], arr[1]);   

    return 0;
}