void TOH(int n, char src, char dest, char aux)
{
	if(n==1)
	{
		printf("Move disk 1 from %c to %c\n",src,dest);
		return;
	}
	TOH(n-1,src,aux,dest);
	printf("Move disk %d from %c to %c\n",n,src,dest);
	TOH(n-1,aux,dest,src);
}
void main()
{
	int n;
	printf("Enter the number of disk: ");
	scanf("%d",&n);
	TOH(n,'A','C','B');
}
