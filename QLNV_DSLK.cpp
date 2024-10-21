	#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
	#include <iostream>
	#include <string.h>
	using namespace std;

	//typedef int ElementType;
	
	struct Nhanvien
	{
		char  Msnv[10];
		char  Hoten[40];
		int   Sonamct;
		float Pccv, Hsl, Luong;
	};
	
	typedef Nhanvien ElementType;
	typedef struct Node
	{
		ElementType Element;
		Node    *Next;
	}pNode;

	typedef Node *PtrToNode;
	typedef PtrToNode Position;
	typedef PtrToNode List;

	void Makenull_List( List &L );
	int IsEmpty_List( List L );
	int IsLast( Position P);
	//Position Locate( ElementType X, List L );
	//void Delete_List( ElementType X, List L );
	//Position LocatePrevious( ElementType X, List L );
	void Insert_List( ElementType X, Position P, List L );
	void Delete_All_List( List L );
	Position Header( List L );
	Position First_List( List L );
	Position End_List( List L);
	Position Advance( Position P );
	ElementType Retrieve( Position P );
	void Read_List(List L);
	void Write_List(List L);
	void PC_NV(List L);
	//void Sort_List(List L);
	void Luong_NV(List L);
	void nvLuong_max(List L);
	void lietke_hsl(List L);
	float tbl_NV(List L);
	void lietke_tbl_nv(List L);
	void timthongtin_nv(List L);
	void sort_list(List L);
	
/* MAIN PROGRAM */
int main()
{
	List L;
	
	printf("\n Nhap vao danh sach \n");
	Makenull_List(L);
	Read_List(L);
	PC_NV(L);
	Luong_NV(L);
	printf("\n Danh sach  vua nhap \n");
	Write_List(L);
	nvLuong_max(L);
	lietke_hsl(L);
	printf("\ntrung binh luong nv = %.2f", tbl_NV(L));
	lietke_tbl_nv(L);
	timthongtin_nv(L);
	sort_list(L);
	printf("\ndanh sach sau khi sap sep theo ho ten la: ");
	Write_List(L);
	//printf("\n Danh sach sau khi sap xep\n");
	//Sort_List(L);	
	//Write_List(L);
	getch();
	return 1;

}

/* Cai dat cac ham*/
	/*Tao 1 danh sach rong*/
	void  Makenull_List(List  &L)
	{
		L = new Node;
		if (L== NULL){
			printf("Khong du bo nho");
			exit(1);
		}
		L->Next = NULL;
	}

	/* Kiem tra danh sach rong? */
	int IsEmpty_List( List L )
	{
		return L->Next == NULL;
	}

	/* Kiem tra P co tro den phan tu cuoi cua ds khong? */

	int IsLast( List P )
	{
		return P->Next == NULL;
	}

	/* Tim vi tri phan tu x trong ds */
	/*
	Position  Locate( ElementType X, List L )
	{
	  Position P;

	  P = L->Next;
	  while( P != NULL && P->Element != X )
		  P = P->Next;

	  return P;
	}
	*/
	
	/* Xoa 1 phan tu */
	/*
	void	Delete_List( ElementType X, List L )
	{
		Position P, TmpCell;
		P = LocatePrevious( X, L );
		if( !IsLast(P) )
		{
			TmpCell = P->Next;
			P->Next = TmpCell->Next;
			free( TmpCell );
		}
	}
	*/
	
	/* Tim vi tri cua phan tu X  */
	/*
	Position	LocatePrevious( ElementType X, List L )
	{
		Position P;

	  P = L;
	  while( P->Next != NULL && P->Next->Element != X )
		  P = P->Next;

	  return P;
	}
	*/
	

	/* Chen 1 phan tu vao danh sach */
	void  Insert_List( ElementType X, List P, List L )
	{
		Position TmpCell;
		TmpCell = new Node;
		
		if (TmpCell == NULL)
		{
			printf("Khong du bo nho");
			exit(1);
		}
		TmpCell->Element = X;
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}

	
	/* Tim phan tu header */
	Position	Header( List L )
	{
		return L;
	}

	/* Tim phan tu dau tien */
	Position       First_List( List L )
	{
		return L->Next;
	}

	/* Tim phan tu ke tiep */
	Position	Advance( Position P )
	{
		return P->Next;
	}

	/* Tim gia tri cua 1 phan tu */
	ElementType	Retrieve( Position P )
	{
		return P->Element;
	}

	/* Nhap danh sach */
	/* Gia su gia tri cac phan tu la so nguyen - int */
	
	//SUA CODE NAY CHO QL NHAN VIÊN
	void Read_List(List L)
	{	int i,n;
		ElementType x;		Position P;
		printf("So nhan vien cua danh sach = "); 
		scanf("%d",&n);
		P = Header(L);
		i = 1;
		while(i<=n)
		{	printf("\nPhan tu %d ",i); 
			printf("\nnhap MSNV = "); scanf("%s", &x.Msnv);
			fflush(stdin);
			printf("nhap ho ten = "); gets(x.Hoten);
			fflush(stdin);
			printf("nhap so nam cong tac = "); scanf("%d", &x.Sonamct);
			do
			{
				printf("nhap he so luong = "); scanf("%f", &x.Hsl);
			}while(3.0 > x.Hsl || x.Hsl > 10.0); //dieu kien chay
				
			Insert_List(x,P,L); //Chen x vao sau vi tri P
			P = P->Next;
			i++;
		}
	}
	//SUA CODE NAY CHO QL NHAN VIÊN
	/* In danh sach */
	void Write_List(List L)
	{	Position P;
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				printf("\nMSNV = %s", P->Element.Msnv);
				printf(" - ho ten = %s", P->Element.Hoten);
				printf(" - so nam cong tac = %d", P->Element.Sonamct);
				printf(" - hsl = %.2f", P->Element.Hsl);
				printf(" - phu cap nhan vien = %.2f", P->Element.Pccv);
				printf(" - luong nhan vien = %.2f", P->Element.Luong);
				P = P->Next;
			}
		}
		else
			printf("List is empty!");
		printf("\n");
	}
	//tinh phu cap nv
	void PC_NV(List L)
	{	Position P;
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				if(P->Element.Sonamct >= 20) 
					P->Element.Pccv = 0.5;
				if((P->Element.Sonamct >= 10) && (P->Element.Sonamct < 20))
					P->Element.Pccv = 0.3;
				if((P->Element.Sonamct >= 5) && (P->Element.Sonamct < 10))
					P->Element.Pccv = 0.2;
				if(P->Element.Sonamct < 5)
					P->Element.Pccv = 0.0;
				P = P->Next;
			}
		}
		else
			printf("List is empty!");
		printf("\n");
	}
//tinh luong nhan vien
	void Luong_NV(List L)
	{	Position P;
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				P->Element.Luong = (P->Element.Hsl + P->Element.Pccv) * 1850;
				P = P->Next;
			}
		}
		else
			printf("List is empty!");
		printf("\n");
	}
//xuat nhan vien cos luong cao nhat
void nvLuong_max(List L)
	{	Position P, nvluong_max;
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			nvluong_max = First_List(L);
			while(P != NULL)
			{
				if(P->Element.Luong > nvluong_max->Element.Luong)
				{
					nvluong_max = P;
				}
				P = P->Next;
			}
			printf("\nnhan vien co luong cao nhat: ");
			printf("\nMSNV = %s", nvluong_max->Element.Msnv);
			printf(" -ho ten = %s", nvluong_max->Element.Hoten);
			printf(" -so nam cong tac = %d", nvluong_max->Element.Sonamct);
			printf(" -he so luong = %.2f", nvluong_max->Element.Hsl);
			printf(" -phu cap cong viec = %.2f", nvluong_max->Element.Pccv);
			printf("\nluong nhan vien = %.2f", nvluong_max->Element.Luong);
			
		}
		else
			printf("List is empty!");
		printf("\n");
	}
	//liet ke nv co hsl >= he so luong da cho
	void lietke_hsl(List L)
	{	Position P; float hsl;
		printf("\nnhap he so luong de so sanh = ");
		scanf("%.2f",&hsl);
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				if(P->Element.Hsl >= hsl)		
				{
					printf("\nMSNV = %s", P->Element.Msnv);
					printf(" - ho ten = %s", P->Element.Hoten);
					printf(" - so nam cong tac = %d", P->Element.Sonamct);
					printf(" - hsl = %.2f", P->Element.Hsl);
					printf(" - phu cap nhan vien = %.2f", P->Element.Pccv);
					printf(" - luong nhan vien = %.2f", P->Element.Luong);
					
				}
				P = P->Next;
			}
		}
		else
			printf("List is empty!");
		printf("\n");
	}
//tinh trung binh luong nhan vien
	float tbl_NV(List L)
	{	Position P; int count = 0; float tbl = 0;
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				tbl += P->Element.Luong;
				count++;
				P=P->Next;
			}
			return (float)tbl / count;
		}
		else
			return 0;
	}
//liet ke nv co luong tb cao hon tbl
	void lietke_tbl_nv(List L)
	{	Position P; float tbl_nv = tbl_NV(L);  
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				if(tbl_nv < P->Element.Luong)
				{
					printf("\nMSNV = %s", P->Element.Msnv);
					printf(" - ho ten = %s", P->Element.Hoten);
					printf(" - so nam cong tac = %d", P->Element.Sonamct);
					printf(" - hsl = %.2f", P->Element.Hsl);
					printf(" - phu cap nhan vien = %.2f", P->Element.Pccv);
					printf(" - luong nhan vien = %.2f", P->Element.Luong);
				}
				P=P->Next;				
			}
		}
		else
			printf("List is empty!");
		printf("\n");
	}
	//nhap ma so can tim xuat thong tin nhan vien co ma so can tim
	void timthongtin_nv(List L)
	{	Position P; char x[10];  
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				if(P->Element.Msnv == x)
				{	
					printf("\ntim thay nv: ");
					printf("\nMSNV = %s", P->Element.Msnv);
					printf(" - ho ten = %s", P->Element.Hoten);
					printf(" - so nam cong tac = %d", P->Element.Sonamct);
					printf(" - hsl = %.2f", P->Element.Hsl);
					printf(" - phu cap nhan vien = %.2f", P->Element.Pccv);
					printf(" - luong nhan vien = %.2f", P->Element.Luong);
				}
				P=P->Next;				
			}
		}
		else
			printf("\nkhong tim thay nv trong danh sach!");
	}	
	void sort_list(List L)
	{
		{	Position P, Q;
			ElementType temp; 
		if(!IsEmpty_List(L))
		{	P = First_List(L);
			while(P != NULL)
			{
				Q=P->Next;
				while(Q != NULL)
				{
					if(strcmp(Q->Element.Hoten, P->Element.Hoten) > 0)
					{
						temp = P->Element;
						P->Element = Q->Element;
						Q->Element = temp;
					}
					Q = Q->Next;
				}
				P=P->Next;				
			}
		}
		else
			printf("List is empty!");
	 }
   }

