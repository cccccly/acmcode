const int MAXN = 1e7*2;
bool check[MAXN + 5];
int phi[MAXN + 5];
int prime[MAXN +5];
int tot; //素数的个数
void pht_prime_table(int N){
	memset(check,false,sizeof(check));
	phi[1] = 1;
	tot = 0;
	for(int i = 2;i <= N;i++){
		if(!check[i]){  //素数的欧拉函数为p-1 
			prime[tot++] = i;
			phi[i] = i-1;
		}
		for(int j = 0;j < tot;j++){
			if(i*prime[j] > N) break;
			cheak[i * prime[j]] = true;
			if(i % prime[j] == 0){
			 	phi[i * prime[j]] = phi[i]*prime[j];
				break; 
			}
			else{
				phi[i * prime[j]] = phi[i]*(prime[j] - 1);
			} 
	}
} 
