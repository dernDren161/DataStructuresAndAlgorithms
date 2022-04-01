// Problem Link: https://workat.tech/problem-solving/practice/trains-and-platforms

int minPlatforms(vector<Train*> &trains) {

	int n = trains.size();
	int a[n]; int d[n];

	for(int i=0;i<n;i++){
		a[i] = trains[i]->arrival;
		d[i] = trains[i]->departure;
	}

	sort(a,a+n); sort(d,d+n);
	int i,j; i = 1; j=0;
	int plat = 1;
	int mini = 1;

	while(i<n && j<n){
		if(a[i]<=d[j]){
			plat++; i++;
		}else if(a[i]>d[j]){
			plat--; j++;
		}
		mini = max(mini,plat);
	}

	return mini;
}
