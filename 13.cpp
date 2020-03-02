#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
using namespace std;

void input(int* mas,int &n);
void random(int* mas,int &n);
void min9(const int* mas,int n,int &min);
void max_otric(const int* mas, int n, int min);
void file_input(int* mas, int &n);
void print(const int* mas, int n);
void file_print(const int* mas,int n);

	int main(){
		int v,mas[100],n,min;
		setlocale(LC_ALL,"Russian");
		do{
			system("cls");
			do{
				cout<<"1 - ������ ������"<<endl;
				cout<<"2 - ��������� ����� �� a �� b"<<endl;
				cout<<"3 - ����� �� �����"<<endl;
				cin>>v;
				switch (v){
					case 1:input(mas,n);break;
					case 2:random(mas,n);break;
					case 3:file_input(mas,n);break;
					default: cout<<"�� ����� �������� ��������!";
				}
					
	
			}while(v!=1 && v!=2 && v!=3);	
			min9(mas,n,min);
			max_otric(mas,n,min);
			system("pause");
			system("cls");
			do {
				cout<<"1 - ������� �� �����"<<endl;
				cout<<"2 - ������� � ����"<<endl;
				cin>>v;
				switch (v){
					case 1:print(mas,n);break;
					case 2:file_print(mas,n);break;
					default: cout<<"�� ����� �������� ��������!";
				}
			}while(v!=1 && v!=2);
			cout<<"0 - �����, 1 - ����������"<<endl;
			cin>>v;	
		}while(v!=0);
			
			system("pause");
			return 1;	
	}
	
	void input(int* mas,int &n){
		
		system("cls");
		
		do{
			cout<<"������� ��������� ����� �������?(�� ����� 100): ";
			cin>>n;
			if(n<=0 || n>100){
				system("cls");
				cout<<"�� ����� �������� ��������!";
			}	
		}while(n<=0 || n>100);
		for(int i=0;i<n;i++){
			cout << "mas[" << i << "] = ";
			 cin >> mas[i];
		}
			
	}
	
	void random(int* mas,int &n){
		
		system("cls");
		
		int a,b;
		do{
			cout<<"������� ��������� ����� �������?(�� ����� 100): ";
			cin>>n;
			if(n<=0 || n>100){
				system("cls");
				cout<<"�� ����� �������� ��������!";
			}	
		}while(n<=0 || n>100);
		
		do{
			cout<<"������� a: ";
			cin>>a;
			cout<<"������� b: ";
			cin>>b;
			
			if(a>b){
				system("cls");
				cout<<"�� ����� �������� ��������!";
			}
		}while(a>b);
		for(int i=0;i<n;i++)
			mas[i]= rand()%(b+1-a)+a;
	}
	
		void file_input(int* mas, int &n) {
		
		system("cls");
		int n1;
		char name [255];
		cout<<"������� ��� ����� � �����������: ";
		cin>>name;
		FILE* f = fopen(name,"rt");
		do{
			cout<<"������� ��������� ����� �������?(�� ����� 100): ";
			cin>>n1;
			if(n1<=0 || n1>100){
				system("cls");
				cout<<"�� ����� �������� ��������!";
			}
		}while(n1<=0 || n1>100);
		
		n=0;
		while(!feof(f)){
			if(n==n1) break;
			fscanf(f,"%d",&mas[n]);
			n++;
		}
		system("pause");
		fclose(f);
	}

	
	void min9(const int* mas,int n,int &min){
		
		system("cls");
		
		int k=0;
		min=mas[0];
		for(int i=1;i<n;i++)
			if(mas[i]<min)
				min=mas[i];
		for(int i=0;i<n;i++)
			if(abs(mas[i]-min)==9)
				k++;
		cout<<"��������� ������������ �� ������������ �� 9: "<<k<<endl;
	}
	
	void max_otric(const int* mas, int n, int min){
		int max_otr = min;
		for(int i=1;i<n;i++)
			if(mas[i]>max_otr && mas[i]<0)
				max_otr=mas[i];
			if (max_otr>0)
				cout<<"����� ����� ���"<<endl;
			else
				cout<<"���������� ������������� �����: "<<max_otr<<endl;
	}
	

	
	void print(const int* mas, int n)	{
		
		system("cls");
		cout<<"�������� �������:"<<endl;
		for(int i=0;i<n;i++)
			cout<<mas[i]<<" ";
		cout<<endl;
	}
	void file_print(const int* mas,int n){
		
		system("cls");
		FILE* f = fopen("output.txt","wt");
		for(int i=0;i<n;i++)
		fprintf(f,"%d\n",mas[i]);
		fclose(f);
	}
	
	
	
	
	
	
	
	
