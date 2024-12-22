#include <stdio.h>
#include <string.h>

struct Student{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};

void sortStudent();

int main(){
	int n=5;
	struct Student students[50]={
        {1,"Le Van C",18,"0123456789"},
        {2,"Tran Thi B",19,"0987654321"},
        {3,"Hoang Van E",20,"0765432198"},
        {4,"Pham Thi D", 18,"0345678901"},
        {5,"Nguyen Van A",21,"0567890123"}
    };
	sortStudent(students,n);
	return 0;
}

void sortStudent(struct Student students[50],int n){
	struct Student save;
	int check,i=0,j;
	char arr[n],saveArr;
	while(i<n){
		j=0;
		check=-1;
		while(j<strlen(students[i].name)){
			if(students[i].name[strlen(students[i].name)-j-1]==' '){
				arr[i]=students[i].name[strlen(students[i].name)-j];
				check=0;
				break;
			}
			j++;
		}
		if(check){
			arr[i]=students[i].name[0];
		}
		i++;
	}
	i=0;
	while(i<n){
		j=0;
		while(j<n-i-1){
			if(arr[j]>arr[j+1]){
				save=students[j];
				saveArr=arr[j];
				students[j]=students[j+1];
				arr[j]=arr[j+1];
				students[j+1]=save;
				arr[j+1]=saveArr;
			}
			j++;
		}
		i++;
	}
	i=0;
	while(i<n){
		printf("\nhoc sinh so id: %d\n",students[i].id);
		printf("	ho va ten: %s\n",students[i].name);
		printf("	tuoi: %d\n",students[i].age);
		printf("	so dien thoai: %s",students[i].phoneNumber);
		i++;
	}
}
