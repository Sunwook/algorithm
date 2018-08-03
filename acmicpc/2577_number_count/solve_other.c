void main(){
	int i=10,j,k,f,b[19]={0};
	scanf("%d\n%d\n%d",&j,&k,&f);
	j*=k*f;
	while(i==10||j!=0)
		b[b[i++]=j%10]++,j/=10;
	while(j<10)
		printf("%d\n",b[j++]);
}
