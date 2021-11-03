#include "AccountBook.h"

int currentAmount = 0;
void intro() {
printf("\t*****가계부 프로그램*****\n");
printf("------------------------------------------------------------------\n");
printf("\t0. 전제 사용 목록 보기\n");
printf("\t1. 입금 목록만 보기\n");
printf("\t2. 출금 목록만 보기\n");
printf("\t3. 입금 정보 추가\n");
printf("\t4. 출금 정보 추가\n");
printf("\t5. 입출금 정보 검색 보기(항목명 검색)\n\t(동일 항복 있을 시 모두 출력)\n");
printf("\t6. 입출금 항목명 수정\n");
printf("\t7. 입출금 항목 삭제\n");
printf("\t8. 종료\n");
printf("------------------------------------------------------------------\n");

}

void showAllData(Book* account, s *statusMoney,int cnt) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******0. 전체 사용 목록 보기*******\n");
printf("\t번호\t구분\t항목\t날짜\t\t금액\t잔여금액\n");
for (int i = 0; i < cnt; ++i) {
printf("\t %d\t%s\t%s\t%s\t%d\t%d\n", (account + i)->number, (account + i)->deposit, (account + i)->item, (account + i)->date, (account + i)->usedAmount, (account + i)->currentAmount);
}
printf("\t총 입출금 횟수 : %d회\n",statusMoney->count);
printf("\t총 입급액: %d원\n", statusMoney->deposit);
printf("\t총 출금액: %d원\n", statusMoney->withdraw);
printf("------------------------------------------------------------------\n");
}
void showDeposit(Book* account, int cnt) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******1. 입금 목록만 보기*******\n");
printf("\t번호\t구분\t항목\t날짜\t\t금액\t잔여금액\n");
for (int i = 0; i < cnt; ++i) {
if (strcmp(account[i].deposit, "입금") == 0) {
printf("\t %d\t%s\t%s\t%s\t%d\t%d\n", (account + i)->number, (account + i)->deposit, (account + i)->item, (account + i)->date, (account + i)->usedAmount, (account + i)->currentAmount);
}
}
printf("------------------------------------------------------------------\n");
}
void showWithdraw(Book* account, int cnt) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******2. 출금 목록만 보기*******\n");
printf("\t번호\t구분\t항목\t날짜\t\t금액\t잔여금액\n");
for (int i = 0; i < cnt; ++i) {
if (strcmp(account[i].deposit, "출금") == 0) {
printf("\t %d\t%s\t%s\t%s\t%d\t%d\n", (account + i)->number, (account + i)->deposit, (account + i)->item, (account + i)->date, (account + i)->usedAmount, (account + i)->currentAmount);
}
}
printf("------------------------------------------------------------------\n");
}
void addDepositInformation(Book* a,s* b) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******3. 입금 정보 추가*******\n");
int number;
char deposit[10] = "입금";
char item[20];
char date[20];
int usedAmount;
printf("번호 : ");
scanf("%d", &number);
printf("항목 : ");
scanf("%s", item);
printf("날짜 : ");
scanf("%s", date);
printf("금액 : ");
scanf("%d", &usedAmount);
a->number = number;
strcpy(a->deposit, deposit);
strcpy(a->item, item);
strcpy(a->date, date);
a->usedAmount = usedAmount;
currentAmount += usedAmount;
a->currentAmount = currentAmount;
b->deposit+=usedAmount;
b->count++;
printf("------------------------------------------------------------------\n");

}
void addWithdrawInformation(Book* a,s* b) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******4. 출금 정보 추가*******\n");
int number;
char deposit[10] = "출금";
char item[20];
char date[20];
int usedAmount;
printf("번호 : ");
scanf("%d", &number);
printf("항목 : ");
scanf("%s", item);
printf("날짜 : ");
scanf("%s", date);
printf("금액 : ");
scanf("%d", &usedAmount);
a->number = number;
strcpy(a->deposit, deposit);
strcpy(a->item, item);
strcpy(a->date, date);
a->usedAmount = usedAmount;
currentAmount -= usedAmount;
a->currentAmount = currentAmount;
b->withdraw+=usedAmount;
b->count++;
printf("------------------------------------------------------------------\n");
}
void showToFindItem(Book* account, int cnt) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******5. 입출금 정보 검색 보기(항목별 검색)*******\n");
char item[20];
printf("검색 : ");
scanf("%s", item);
printf("\t번호\t구분\t항목\t날짜\t\t금액\t잔여금액\n");
for (int i = 0; i < cnt; ++i) {
if (strcmp(account[i].item, item) == 0) {
printf("\t %d\t%s\t%s\t%s\t%d\t%d\n", (account + i)->number, (account + i)->deposit, (account + i)->item, (account + i)->date, (account + i)->usedAmount, (account + i)->currentAmount);
}
}
printf("------------------------------------------------------------------\n");
}

void fixItem(Book* account, int cnt) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******6. 입출금 항목명 수정*******\n");
printf("번호 : ");
int number;
char item[20];
scanf("%d", &number);
for (int i = 0; i < cnt; ++i) {
if (account[i].number == number) {
printf("수정 내용 : ");
scanf("%s", item);
strcpy(account[i].item, item);
}
}
printf("%d번 항목을 %s로 수정했습니다.\n", number, item);
printf("------------------------------------------------------------------\n");
}
void eraseData(Book* account, s *leftMoney,int cnt) {
printf("------------------------------------------------------------------\n");
printf("\t\t*******7. 입출금 항목 삭제*******\n");
printf("번호 : ");
int number;
scanf("%d", &number);
for (int i = 0; i < cnt; ++i) {
if (account[i].number == number) {
int a=account[i].usedAmount;
if(strcmp(account[i].deposit,"입금")==0){
leftMoney->deposit=(leftMoney->deposit)-a;
currentAmount=currentAmount-a;
}
else if(strcmp(account[i].deposit,"출금")==0){
leftMoney->withdraw=(leftMoney->withdraw)-a;
currentAmount=currentAmount+a;
}
(account+(i+1))->currentAmount=currentAmount;
for(int j=i;j<cnt;++j){
account[j]=account[j+1];
}
leftMoney->count--;
}
}
printf("%d번 항목을 삭제 하였습니다.\n", number);
printf("------------------------------------------------------------------\n");

}
void endProgram() {
printf("가계부 프로그램을 종료하겠습니다.");
exit(0);
}
void goProgram() {
int cnt = 0;
while (1) {
intro();
Book account[MAX];
s statusMoney[2];
printf("선택 : ");
int pickNumber;
scanf("%d", &pickNumber);
switch (pickNumber)
{
case 0:
showAllData(account, statusMoney,cnt);
break;
case 1:
showDeposit(account, cnt);
break;

case 2:
showWithdraw(account, cnt);
break;

case 3:
addDepositInformation(account + cnt,statusMoney);
cnt++;
if (cnt ==100)break;
break;

case 4:
addWithdrawInformation(account + cnt,statusMoney);
cnt++;
if (cnt == 100)break;
break;

case 5:
showToFindItem(account, cnt);
break;

case 6:
fixItem(account, cnt);
break;

case 7:
eraseData(account, statusMoney,cnt);
cnt--;
break;

case 8:
endProgram();
break;
}
}
}
