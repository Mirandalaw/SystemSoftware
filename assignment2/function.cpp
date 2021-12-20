#include "header.h"

vector<Book> information;
char parse[MAX/2][MAX];
bool cmp(Book a,Book b) {
	return a.id <= b.id ? true : false;
}

bool cmpstr(Book a, Book b) {
	return a.title <= b.title ? true : false;
}

void dat(char *n,char *data){
	char arr[MAX];
	sprintf(arr, "Book.dat");
	FILE *file;
	file = fopen(arr,n);
	fputs(data,file);
	fclose(file);
}

void cut(char *str, char *cutof){
	int cnt = 0;
	char arr[MAX];
	char *n;
	strcpy(arr,n);
	n = strtok(arr,cutof);
	strcpy(parse[cnt],n);
	cnt++;
	while(n!=NULL){
		n = strtok(NULL,cutof);
		if(n!=NULL){
			strcpy(parse[cnt],n);
			cnt++;
		}
	}
}

void read(){
	char arr[MAX]={0};
	FILE *n = NULL;
	n = fopen("Book.dat","r");
	if(n!=0){
		while(fgets(arr,sizeof(arr),n)){
			if(arr != NULL){
				cut(arr,"\n");
				if(strcmp(parse[1],"true")==0){
					menu3_1();
				}
				else if(strcmp(parse[1],"false")==0){
					menu3_1();
				}
			}
		}
	}
}

void write(){
	char arr[MAX];
	int check=0;
	for(int i=0;i<information.size();++i){
		sprintf(arr,"%d %s %s %s %s %d\n",information[i].id,information[i].title,information[i].author,information[i].date,information[i].publisher,information[i].price);
		if(i==0) dat("w",arr);
		else dat ("a+",arr);
	}
}

void info() {
	cout<<"\t*****<Book Management>*****\n";
	cout<<"\t*****<1901078 KimBoHyeon>*****\n";
	cout<<"------------------------------------------------------------------\n";
	cout<<"\t1. List up All Book(Sort by id)\n";
	cout<<"\t2. List up All Book(Sort by title)\n";
	cout<<"\t3. Add New Book\n";
	cout<<"\t4. Update Book\n";
	cout<<"\t5. Remove a Book\n";
	cout<<"\t6. Search Book Information by Title(minimum 2char)\n";
	cout<<"\t0. Quit\n\n";
	cout<<"------------------------------------------------------------------\n";
	cout<<"Choose num > ";

}
void showInfo() {
	cout<<"\tID\tTITLE\tAUTHOR\tDATE(YYYYMMDD)\tPUBLISHER\tPRICE\n";
}
void menu1() {//show
	showInfo();
	for (int i = 0; i < information.size(); ++i) {
		cout << "\t\t"<<information[i].id << "\t" << information[i].title  <<information[i].author<<"\t"<< information[i].date << "\t" << information[i].publisher <<"\t"<< information[i].price<< "\t" << '\n';
	}
}
void menu3_1() {//Add New Book
	Book a;
	cout<<"id : ";
	cin >> a.id;
	cout<<"title : ";
	cin >> a.title;
	cout<<"author : ";
	cin >> a.author;
	cout<<"date : ";
	cin >> a.date;
	cout<<"publisher : ";
	cin >> a.publisher;
	cout<<"price : ";
	cin>> a.price;
	information.push_back(a);
}
void menu3() {
	menu3_1();
	write();
	string answer;
	string delimeter = "y";
	cout<<"Would you like to borrow more?[y/n] : ";
	cin >> answer;
	if (answer==delimeter) {
		menu3();
	}
	else cout<<"No,i wouldn't\n";
}
void menu4() {//update
	FILE *file = NULL;
	file = fopen("Book.dat","r");
	fseek(file,0,SEEK_SET);
	int selectNumber;
	cout << "What you want to change? \n";
	cout << "1. id\n2. title\n";
	cin >> selectNumber;
	cout << "You selectNumber is : " << selectNumber;
	if (selectNumber == 1) {
		cout << "Input number : ";
		int selectId;
		cin >> selectId;
		for (int i = 0; i < information.size(); ++i) {
			if (selectId == information[i].id) {
				fseek(file,i,SEEK_CUR);
				cout<<"id : ";
				cin >> information[i].id;
				cout<<"title : ";
				cin >> information[i].title;
				cout<<"author : ";
				cin >> information[i].author;
				cout<<"date : ";
				cin >> information[i].date;
				cout<<"publisher : ";
				cin >> information[i].publisher;
				cout<<"price : ";
				cin >> information[i].price;
				write();
			}
		}
	}
	fclose(file);
}
void menu5() {//remove
	cout<<"If you want to erase , you would selectNumber : ";
	int selectId;
	cin >> selectId;
	for (int i = 0; i < information.size(); ++i) {
		if (selectId == information[i].id) {
			information.erase(information.begin() + i);
			write();
			cout << "Id : " << selectId << " delete \n";
		}
	}
}
void menu6() {//Search Book Information by Title
	cout<<"If you want to find information, you 'd inputTitle : ";
	string title;
	cin >> title;
	for (int i = 0; i < information.size(); ++i) {
		if (information[i].title.find(title) != string::npos) {
			cout << "Find\n";
			cout << "\t" << information[i].id << "\t" << information[i].title << "\t" << information[i].date << "\t" << information[i].publisher << "\t" << information[i].price << "\t" << '\n';
		}
		else continue;
	}
}
void menu0() {
	cout << "End Program";
	exit(0);
}
void start() {
	
	while (1) {
		info();
		int inputNumber;
		cin >> inputNumber;
		switch (inputNumber)
		{
		case 1:
			cout<<"\t\t*******1. List up All Book(Sort by id)*******\n";
			cout<<"------------------------------------------------------------------\n";
			sort(information.begin(), information.end(), cmp);
			menu1();
			cout<<"------------------------------------------------------------------\n";
			break;

		case 2:
			cout<<"\t\t*******2. List up All Book(Sort by title)*******\n";
			cout<<"------------------------------------------------------------------\n";
			sort(information.begin(),information.end(), cmpstr);
			menu1();
			cout<<"------------------------------------------------------------------\n";
			break;

		case 3:
			cout<<"\t\t*******3. Add New Book*******\n";
			cout<<"------------------------------------------------------------------\n";
			menu3();
			cout<<"------------------------------------------------------------------\n";
			break;

		case 4:
			cout<<"\t\t*******4. Update Book*******\n";
			cout<<"------------------------------------------------------------------\n";
			menu4();
			cout<<"------------------------------------------------------------------\n";
			break;
			
		case 5:
			cout<<"\t\t*******5. Remove a Book*******\n";
			cout<<"------------------------------------------------------------------\n";
			menu5();
			cout<<"------------------------------------------------------------------\n";
			break;
		case 6:
			cout<<"\t\t*******6. Search Book Information by Title(minimum 2char)*******\n";
			cout<<"------------------------------------------------------------------\n";
			menu6();
			cout<<"------------------------------------------------------------------\n";
			break;
			
		case 0:
			cout<<"------------------------------------------------------------------\n";
			menu0();
			cout<<"------------------------------------------------------------------\n";
			break;
			}
		}
	}

int main() {
	start();
	return 0;
}