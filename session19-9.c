#include <stdio.h>
#include <string.h>

struct Student{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void printStudents();

void addStudent();

void updateStudent();

void deleteStudent();

void sortStudents();

void findStudent();

int main(){
    struct Student students[50]={
        {1,"Le Van C",18,"0123456789"},
        {2,"Tran Thi B",19,"0987654321"},
        {3,"Hoang Van E",20,"0765432198"},
        {4,"Pham Thi D", 18,"0345678901"},
        {5,"Nguyen Van A",21,"0567890123"}
    };
    int n=5,type;
    do{
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Sap xep danh sach sinh vien\n");
        printf("6. Tim kiem sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d",&type);
        fflush(stdin);
        switch(type){
            case 1:
                printStudents(students,n);
                break;
            case 2:
                addStudent(students,&n);
                break;
            case 3:
                updateStudent(students,n);
                break;
            case 4:
                deleteStudent(students,&n);
                break;
            case 5:
                sortStudents(students,n);
                break;
            case 6:
                findStudent(students,n);
                break;
        }
    }while(type!=7);
    return 0;
}

void printStudents(struct Student students[],int n){
    printf("\nDanh sach sinh vien:\n");
    int i=0;
	while(i<n){
		printf("\nhoc sinh so id: %d\n",students[i].id);
		printf("	ho va ten: %s\n",students[i].name);
		printf("	tuoi: %d\n",students[i].age);
		printf("	so dien thoai: %s",students[i].phoneNumber);
		i++;
	}
}

void addStudent(struct Student students[],int *n){
    struct Student newStudent;
    printf("Nhap ID: ");
    scanf("%d",&newStudent.id);
    printf("Nhap ten: ");
    fflush(stdin);
    fgets(newStudent.name,sizeof(newStudent.name),stdin);
    newStudent.name[strcspn(newStudent.name,"\n")]='\0';
    printf("Nhap tuoi: ");
    scanf("%d",&newStudent.age);
    printf("Nhap so dien thoai: ");
    fflush(stdin);
    fgets(newStudent.phoneNumber,sizeof(newStudent.phoneNumber),stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber,"\n")]='\0';
    students[*n]=newStudent;
    (*n)++;
}

void updateStudent(struct Student students[],int n){
    int index;
    printf("Nhap vi tri sua (1-%d): ",n);
    scanf("%d",&index);
    index--;
    if(index<0||index>=n){
        return;
    }
    printf("Nhap ID: ");
    scanf("%d",&students[index].id);
    printf("Nhap ten: ");
    fflush(stdin);
    fgets(students[index].name,sizeof(students[index].name),stdin);
    students[index].name[strcspn(students[index].name,"\n")]='\0';
    printf("Nhap tuoi: ");
    scanf("%d",&students[index].age);
    printf("Nhap so dien thoai: ");
    fflush(stdin);
    fgets(students[index].phoneNumber,sizeof(students[index].phoneNumber),stdin);
    students[index].phoneNumber[strcspn(students[index].phoneNumber,"\n")]='\0';;
}

void deleteStudent(struct Student students[],int *n){
    int index;
    printf("Nhap vi tri xoa (1-%d): ",*n);
    scanf("%d",&index);
    index--;
    if(index<0||index>=*n){
        return;
    }
    int i=index;
    while(i<*n-1){
        students[i]=students[i+1];
        i++;
    }
    (*n)--;
}

void sortStudents(struct Student students[],int n){
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
}

void findStudent(struct Student students[],int n){
    char name[50];
    printf("Nhap ten sinh vien can tim: ");
    fflush(stdin);
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';
    int i=0;
    while(i<n){
        if(strstr(students[i].name,name)){
            printf("Tim thay: ID: %d, Name: %s, Age: %d, Phone: %s\n",
                students[i].id,students[i].name,students[i].age,students[i].phoneNumber);
        }
        i++;
    }
}

