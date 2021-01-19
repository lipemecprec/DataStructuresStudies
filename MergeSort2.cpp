# include <stdio.h>

const int MAXN = 100010; 

int n;

long long int v[MAXN];
long long int aux[MAXN];

void print(int* v, int n);
void mergeSort(int* v , int l, int r);
void merge( int* v , int l , int mid, int r);


int main(){
    int value;
    
	while( scanf("%d",&value) == 1 )
	    v[++n] = value;
	
	mergeSort(v , 1, n);
	
	print(v, n);
}

void mergeSort(int* v , int l, int r){
	    // printf("l = %d | r = %d \n", l, r);
	if ( l == r ) return;
	int mid = (l + r) / 2;
	    // printf("l = %d | mid = %d | v[%d] = %d | v[%d] = %d \n", l, mid, l, v[l], mid, v[mid]);
	mergeSort(v , l , mid);
	    // printf("mid + 1 = %d | r = %d | v[%d] = %d | v[%d] = %d \n", mid + 1 , r , mid + 1 , v[mid+1] , r, v[r]);
	mergeSort(v , mid + 1 , r);
        //     printf("\n Vetor l -> ");
        //     for (int i = l ; i <= mid; i++ )
        // 		printf("%d ", v[i]);
        // 	printf("\n Vetor r -> ");
        // 	for (int i = mid + 1 ; i <= r; i++ )
        // 		printf("%d ", v[i]);
    merge(v , l , mid , r);
}

void merge( int* v , int l , int mid, int r){
	int ia = l, il = l, ir = mid + 1;
	
	while ( il <= mid && ir <= r ){
		if (v[il] <= v[ir]) aux[ia++] = v[il++];
		else aux[ia++] = v[ir++];		
	}
	while ( il <= mid ){
		aux[ia++] = v[il++];		
	}
	while ( ir <= r ){
		aux[ia++] = v[ir++];		
	}
	
	for ( int i = l ; i <= r ; i++){
		v[i] = aux[i];
	}
        // 	print(aux, r);
}


void print(int* v, int n){
        // 	printf("\n Vetor final -> ");
	for (int i = 1 ; i < n + 1; i++ )
		printf("%d ", v[i]);
        // 	printf("\n");
}
