#include <stdio.h>
#include <string.h>

struct Student{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};

void deleteStudent();

int main(){
	int n=5,id;
	struct Student students[50]={
        {1,"Nguyen Van A",18,"0123456789"},
        {2,"Tran Thi B",19,"0987654321"},
        {3,"Le Van C",20,"0765432198"},
        {4,"Pham Thi D", 18,"0345678901"},
        {5,"Hoang Van E",21,"0567890123"}
    };
	printf("vui long nhap id muon xoa: ");
	scanf("%d",&id);
	deleteStudent(id,students,&n);
	return 0;
}

void deleteStudent(int id,struct Student students[50],int *n){
	int check=-1,i=0;
	while(i<*n){
		if(id==students[i].id){
			int j=i;
			while(j<*n-1){
				students[j]=students[j+1];
				j++;
			}
			check=0;
			(*n)--;
			break;
		}
		i++;
	}
	if(check){
		printf("khong tim thay id");
		return;
	}
	i=0;
	while(i<*n){
		printf("\nhoc sinh so id: %d\n",students[i].id);
		printf("	ho va ten: %s\n",students[i].name);
		printf("	tuoi: %d\n",students[i].age);
		printf("	so dien thoai: %s",students[i].phoneNumber);
		i++;
	}
}
