#include<stdio.h>
#include<conio.h>
#include<math.h>
void nhap(int a[100][100], int m, int n) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("nhap a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
}
void xuat(int a[100][100], int m, int n) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) 
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}
void docFile(FILE*f,int A[100][100],int&m,int&n){
	if(f!=NULL){
		fscanf(f,"%d",&m);
		fscanf(f,"%d",&n);
     	for(int i=1;i<=m;i++){
	    	for(int j=1;j<=n;j++){
		    	if(!feof(f))
		        	fscanf(f,"%d",&A[i][j]);
		        else{
			        printf("Du lieu khong hop le");
			        getch();
	    	    }
		}
	}
	}
	else printf("File khong ton tai\n");
	
}
void ghiFile(FILE*f,int A[100][100],int m,int n){
	fprintf(f,"%d",m);
	putc('\t',f);
	fprintf(f,"%d",n);
	putc('\n',f);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			fprintf(f,"%d",A[i][j]);
			putc('\t',f);
		}
		putc('\n',f);
	}
}
int lon_nhat(int a[100][100], int m, int n) {
	int max = a[1][1];
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) 
			if (a[i][j] > max)max = a[i][j];
	return max;
}
int nho_nhat(int a[100][100], int m, int n) {
	int min = a[1][1];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] < min)min = a[i][j];
	return min;
}
void hoandoi(int a[100][100], int m, int n, int x, int y) {

	for (int i = 1; i <= n; i++) {
		int t = a[x][i];
		a[x][i] = a[y][i];
		a[y][i] = t;
	}
}
void xoa_cot(int a[100][100], int m, int &n, int k) {
	for (int i = k; i <= n-1; i++) {
		for (int j = 1; j <= m; j++) {
			a[j][i] = a[j][i + 1];
		}
	
	}
	n--;

}
void xoa_hangMin(int a[100][100], int &m, int n) {
	int k, min = a[1][1];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] < min) {
				min = a[i][j]; k = i;
			}
	for (int i = k; i <= m-1; i++) 
		for (int j = 1; j <= n; j++) 
			a[i][j] = a[i + 1][j];
		
	m--;
}
int tongcotmax(int a[100][100],int m,int n){
	int max = a[1][1];
	int t=1;
	int tong=0;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) 
			if (a[i][j] > max){
			    max = a[i][j];
			    t=j;
			}
	for(int k=1;k<=m;k++)
	   tong+=a[k][t];
	return tong;
	
}
void mtLe(int a[100][100],int m,int n,int b[100]){
	int t=0;
	for(int i=1;i<=n;i++){
	    t++;
		b[t]=0;
		for(int j=1;j<=m;j++){
			if(a[j][i]%2!=0){
				b[t]=a[j][i];
				break;
			}
		}
	}
}
void nhan(int a[100][100],int b[100][100],int c[100][100],int n,int m,int y){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=y;j++){
			c[i][j]=0;
		    for(int t=1;t<=n;t++){
		    	c[i][j]+=a[i][t]*b[t][j];
			}
		}
	}
	FILE *f=fopen("tich.txt","w");
	ghiFile(f,c,m,y);
	fclose(f);
	
}
void conghaimang(int a[100][100],int m,int n,int b[100][100]){
	int c[100][100];
    for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
    }
    FILE * f;
    f= fopen("tong.txt","w");
    ghiFile(f,c,m,n);
	fclose(f);
	xuat(c,m,n);
}
void menu(){
	printf ("\n-----------------------------MENU-------------------------\n");
	printf ("1.\tNhap truc tiep ma tran\n");
    printf ("2.\tNhap ma tran cac so nguyen vao file \n");
    printf ("3.\tXuat ma tran tu file\n");
	printf ("4.\tXuat mang cac so nguyen\n");
	printf ("5.\tTim phan tu lon nhat\n");
	printf ("6.\tTim phan tu nho nhat\n");
	printf ("7.\tHoan doi 2 dong cho nhau\n");
	printf ("8.\tXoa cot\n");
	printf ("9.\tXoa dong chua phan tu nho nhat\n");
	printf ("10.\tTinh tong cua cot chua phan tu lon nhat\n");
	printf ("11.\tTim mang x chua cac phan tu le cua ma tran\n");
	printf ("12.\tTong 2 ma tran\n");
	printf ("13.\tTich 2 ma tran\n");
	printf ("0.\tKet thuc\n");
	printf("-------------------------------------------------------\n");

	
	
}
int main() {
	int a[100][100],c[100][100], m=-1, n=-1,x,y,k,kt=1;
	int b[100];
	FILE* f;
	while(kt){
		menu();
		printf("nhap vao lua chon cua ban:");
		scanf("%d",&kt);
		if((m==-1 || n==-1)&&(kt>3||kt==2)){
			printf("Ma tran chua ton tai, ban phai nhap vao ma tran moi duoc thuc hien nhung chuc nang nay\n");
			continue;
		}
	
		switch(kt){
			case 1:
				printf("Nhap vao ma tran cac so nguyen\n");
				printf("nhap so hang m=");
                scanf("%d",& m);
                printf("nhap so cot  n=");
                scanf("%d",& n);
                while(m<1 || n<1){
                	printf(" So hang cot ban nhap vao khong hop le\n");
                	printf("Nhap lai\n");
                	printf("nhap so hang m=");
                    scanf("%d",& m);
                    printf("nhap so cot  n=");
                    scanf("%d",& n);
				}
                nhap(a,m,n);
			case 2:
			    f= fopen("matran.txt","w");
				ghiFile(f,a,m,n);
				fclose(f);
				getch();
				break;
		
			case 3:
				
				f=fopen("matran.txt","r");
			    docFile(f,a,m,n);
			    fclose(f);
			    xuat(a,m,n);
			    getch();
			    break;
			    
			case 4:
				
				printf("ma tran ban vua nhap la:\n");
            	xuat(a, m, n);
            	getch();
            	break;
            case 5:
            	printf("ma tran da cho la: \n");
            	xuat(a,m,n);
            	printf("phan tu lon nhat cua ma tran:%d\n", lon_nhat(a, m, n));
            	getch();
            	break;
            case 6:
            	printf("Ma tran da cho la:\n");
            	xuat(a,m,n);
            	printf("phan tu nho nhat cua ma tran la:%d\n", nho_nhat(a, m, n));
            	getch();
            	break;
            case 7:
            	printf("nhap 2 hang can hoan doi:");
            	scanf("%d%d", &x, &y);
            	while(x<1||x>m||y<1||y>m) 
            	{
            		printf("hai hang nhap vao khong hop le\n");
            		printf("nhap 2 hang can hoan doi:");
            		scanf("%d%d", &x, &y);
            	}  
				printf("Ma tran truoc khi hoan doi:\n");
				xuat(a,m,n);    	
	            hoandoi(a, m, n, x, y);
	            printf("Ma tran sau khi hoan doi 2 dong %d va %d:\n",x,y);
	            xuat(a, m, n);
	            getch();
			    break;
			case 8:
				printf("nhap cot ban muon xoa:");
            	scanf("%d", &k);
            	while(k<1||k>n){
            		printf("so cot ban nhap vao khong hop le\n");
            		printf("nhap lai cot ban muon xoa:");
            	    scanf("%d", &k);
                }
                printf("Ma tran ban dau :\n");
                xuat(a,m,n);
	            xoa_cot(a, m, n, k);
	            printf("Ma tran sau khi xoa cot thu %d\n",k);
	            xuat(a,m,n);
	            getch();
	            break;
	        case 9:
	        	printf("Ma tran ban dau\n");
	        	xuat(a,m,n);
	        	xoa_hangMin(a, m, n);
	            printf("ma tran sau khi xoa hang chua phan tu nho nhat:\n");
	            xuat(a, m, n);
	            getch();
	            break;
	        case 10:
	        	printf("Ma tran ban dau\n");
	        	xuat(a,m,n);
	        	printf("tong cua cot chua phan tu lon nhat:%d\n",tongcotmax(a,m,n));
	        	getch();
	        	break;
	        case 11:
	        	printf("Ma tran ban dau\n");
	        	xuat(a,m,n);
	        	mtLe(a,m,n,b);
	        	printf("mang x chua cac phan tu le cua ma tran\n");
	        	for(int i=1;i<=n;i++){
	        		printf("%d   ",b[i]);
				}
				getch();
				break;
			case 12:
				xuat(a,m,n);
				printf("Ban co muon su dung ma tran ban dau de tinh tong k ? yes(1)/no(0))");
				int h;
				scanf("%d",&h);
				if(h==0){
					int d[100][100];
					int x1,y1;
					printf("Nhap vao ma tran thu nhat:");
			    	printf("\nNhap vao so hang: ");
				    scanf("%d",&x1);
				    printf("Nhap vao so cot: ");
				    scanf("%d",&y1);
				    nhap(d,x1,y1);
				    printf("Nhap vao ma tran thu hai:");
			    	printf("\nNhap vao so hang: ");
				    scanf("%d",&x);
				    printf("Nhap vao so cot: ");
				    scanf("%d",&y);
				   
				    while ( x1!=x||y1!=y){
					    printf( " Ma tran ban nhap vao khong hop le");
					    printf("Nhap lai ma tran thu hai:");
					    printf("\nNhap vao so hang: ");
				        scanf("%d",&x);
				        printf("Nhap vao so cot: ");
				        scanf("%d",&y);
				        
				   }
				    nhap(c,x,y);
				    printf(" Ma tran thu nhat\n");
				    xuat(d,x1,y1);
				    printf(" Ma tran thu hai\n");
				    xuat(c,x,y);
				    printf("Tong hai ma tran la: \n");
				    conghaimang(d,x,y,c);
				}
				else if(h==1){
			
			     	printf("Nhap vao ma tran ");
				    printf("\nNhap vao so hang: ");
					scanf("%d",&x);
					printf("Nhap vao so cot: ");
					scanf("%d",&y);
				
					while ( x!=m||y!=n){
						printf( " Ma tran ban nhap vao khong hop le\n");
						printf("Nhap lai ma tran:");
						printf("\nNhap vao so hang: ");
				    	scanf("%d",&x);
				    	printf("Nhap vao so cot: ");
				    	scanf("%d",&y);
				    	
					}
					nhap(c,x,y);
					printf(" Ma tran thu nhat\n");
					xuat(a,x,y);
					printf(" Ma tran thu hai\n");
					xuat(c,x,y);
					printf("Tong hai ma tran la: \n");
					conghaimang(a,m,n,c);
				}
				else{
					printf("Lua chon khong hop le");
				}
				break;           	
	        case 13:            
				int x1,y1,x2,y2,c[100][100],d[100][100],f[100][100],kt;
				xuat(a,m,n);
				printf ("Ban co muon dung ma tran tren de tinh tich khong(Y-1/N-0)?");
				scanf ("%d",&kt);
				if (kt==0){
					printf ("Nhap hai ma tran\n");
					printf ("Nhap vao so hang và so cot cua ma tran thu nhat:  ");
					scanf ("%d %d",&x1,&y1);
					nhap(c,x1,y1);
					do{
						printf ("Nhap vao so hang và so cot cua ma tran thu hai ");
						scanf ("%d %d",&x2,&y2);
						if (y1==x2){
							nhap(d,x2,y2);
							printf ("Ma tran thu nhat\n");
							xuat(c,x1,y1);
							printf ("Ma tran thu hai\n");
							xuat(d,x2,y2);
							printf ("Tich hai ma tran\n");
							nhan(c,d,f,y1,x1,y2);
							xuat(f,x1,y2);
						}
						else{
							printf ("Ma tran khong hop le, so cot cua ma tran thu nhat phai bang so hang cua ma tran thu hai\n");
						}
					}while(y1!=x2);
				}
				else if (kt==1) {
					printf ("Nhap vao ma tran\n");
					do{
						printf ("Nhap vao so hang và so cot cua ma tran thu hai");
						scanf ("%d %d",&x2,&y2);
						if (n==x2){
							nhap(d,x2,y2);
							printf ("Ma tran thu nhat\n");
							xuat(a,m,n);
							printf ("Ma tran thu hai\n");
							xuat(d,x2,y2);
							printf ("Tich hai ma tran\n");
							nhan(a,d,f,n,m,y2);
							xuat(f,m,y2);
						}
						else{
							printf ("Ma tran khong hop le, so cot cua ma tran thu nhat phai bang so hang cua ma tran thu hai\n");
						}
					}while(n!=x2);
				}
				else {
					printf ("\nLua chon khong hop le");
				}
				getch();
				break;

    	}
	}
}
