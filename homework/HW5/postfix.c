#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack 내에서 우선순위는 내림차순, lparen = 0 가장 낮음 */
typedef enum{
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;	//우선순위

char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  //postfixStack용 top 선언 및 초기화
int evalStackTop = -1;	   //evalStack용 top 선언 및 초기화

int evalResult = 0;	   //계산 결과를 저장할 변수 evalResult 선언

void postfixpush(char x);	//후위표기식으로 변환할 때 원소 삽입
char postfixPop();		//후위표기식으로 변환할 때 원소 삭제 연산 후 그 값을 반환
void evalPush(int x);		//연산할 때 원소 삽입
int evalPop();		//연산할 때 원소 삭제 후 그 값을 반환
void getInfix();	//infix expression을 입력받음
precedence getToken(char symbol);	//문자를 받아들여서 우선순위를 리턴
precedence getPriority(char x);	//getToken() 수행
void charCat(char* c);	//문자하나를 전달받아, postfixExp에 추가
void toPostfix();	//infixExp의 문자를 하나씩 읽어가며 postfix로 변경
void debug();	//디버그
void reset();	//초기화
void evaluation();	//연산

int main()
{
	char command;	//명령어 저장할 변수 command 선언
	printf("[----- [김예경] [2021039010] -----]\n");

	do{	//계속 반복
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//command 입력받음

		switch(command) {
		case 'i': case 'I':		//i나 I를 입력했을 경우
			getInfix();			//infix 표기식을 입력받음
			break;
		case 'p': case 'P':		//d나 D를 입력했을 경우
			toPostfix();		//infix를 postfix로 변환
			break;
		case 'e': case 'E':		//e나 E를 입력했을 경우
			evaluation();		//연산 과정 수행
			break;
		case 'd': case 'D':		//d나 D를 입력했을 경우
			debug();			//디버그
			break;
		case 'r': case 'R':		//r나 R를 입력했을 경우
			reset();			//초기화
			break;
		case 'q': case 'Q':		//q나 Q를 입력했을 경우
			break;
		default:				//그 외의 것을 입력했을 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");	//경고 문구 출력
			break;
		}
	//q나 Q를 입력할 때까지 반복
	}while(command != 'q' && command != 'Q');

	return 1;
}
//후위표기식으로 변환할 때 원소 삽입
void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;	//top을 한 칸 증가시킨 후 거기에 x를 저장
}
//후위표기식으로 변환할 때 원소 삭제 연산 후 그 값을 반환
char postfixPop()
{
    char x;
    if(postfixStackTop == -1)	//postfixStack용 top이 -1이면 (스택이 공백이면)
        return '\0';			//'\0'리턴
    else {						//스택이 공백이 아니면
    	x = postfixStack[postfixStackTop--];	//top의 원소를 x에 저장하고 top을 한 칸 감소시킴
    }
    return x;	//x를 반환
}
//연산할 때 원소 삽입
void evalPush(int x)	
{
    evalStack[++evalStackTop] = x;	//top을 한 칸 증가시킨 후 거기에 x를 저장
}
//연산할 때 원소 삭제 후 그 값을 반환
int evalPop()
{
    if(evalStackTop == -1)	//스택이 비었으면 -1 리턴
        return -1;
    else
        return evalStack[evalStackTop--];	//top의 원소를 x에 저장하고 top을 한 칸 감소시킴
}

//infix expression을 입력받음
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);	//infixExp에 입력된 값 저장
}
//문자를 받아들여서 우선순위를 리턴
precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;	//(일 경우 
	case ')' : return rparen;	//)일 경우 
	case '+' : return plus;		//+일 경우 
	case '-' : return minus;	//-일 경우 
	case '/' : return divide;	///일 경우 
	case '*' : return times;	//*일 경우 
	default : return operand;	//그 외(=수)일 경우
	}
}
//getToken() 수행
precedence getPriority(char x)
{
	return getToken(x);
}

//문자하나를 전달받아, postfixExp에 추가
void charCat(char* c)
{
	if (postfixExp == '\0')	//비었으면 한 글자를 postfixExp에 복사
		strncpy(postfixExp, c, 1);
	else	//문자가 있으면 한 글자를 postfixExp에 이어 붙임
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;	
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */

	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while(*exp != '\0')	//*exp가 \0이 아닐때까지 (infixExp 문자열 끝까지)
	{
		if(getPriority(*exp)==operand) {	//*exp가 피연산자이면
			x = *exp;
			charCat(&x);	//postfixExp에 문자 하나 추가
		}
		else if (getPriority(*exp)==lparen) {	//*exp가 lparen이면
			postfixPush(*exp);	//스택에 lparen 삽입
		}
		else if (getPriority(*exp)==rparen) {	//rparen이면
			while((x=postfixPop())!= '(') {		//lparen을 만날 때까지
				charCat(&x);	//그 문자들을 postfixExp에 추가
			}
		}
		else {	//(,)가 아닌 연산자이면
			while(getPriority(postfixStack[postfixStackTop]) >= getPriority(*exp)) {	//*exp의 우선순위가 스택의 top에 있는 원소의 우선순위보다 크지 않을 경우
            	x = postfixPop();	//스택에 있는 원소를 삭제 후 그 값을 x에 저장
            	charCat(&x);	//이 x를 postfixExp에 추가
            }
            postfixPush(*exp);	//우선순위가 클 경우 스택에 삽입
        }
        exp++;	//exp 증가시킴
		}
	while(postfixStackTop != -1)	//스택에 아무것도 남아있지 않을 때까지
    {
    	x = postfixPop();	//스택에 있는 원소를 삭제 후 그 값을 x에 저장
    	charCat(&x);	//x를 postfixExp에 추가
    }
}
//디버그
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);		//중위표기식 출력
	printf("postExp =  %s\n", postfixExp);		//후위표기식 출력
	printf("eval result = %d\n", evalResult);	//연산결과 출력

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)		
		printf("%c  ", postfixStack[i]);		//postfixStack에 있는 모든 원소 출력

	printf("\n");

}
//초기화
void reset()
{
	infixExp[0] = '\0';		//중위표기식 0으로 초기화
	postfixExp[0] = '\0';	//후위표기식 0으로 초기화

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';	//postfixStack에 있는 모든 원소 0으로 초기화
         
	postfixStackTop = -1;	//postfixStackTop을 -1로 초기화
	evalStackTop = -1;	//evalStackTop을 -1로 초기화
	evalResult = 0;		//연산결과 0으로 초기화
}
//연산
void evaluation()
{
	int op1, op2;						//연산자 저장 변수
	int length = strlen(postfixExp);	//strlen()를 이용해 후위표기식의 길이를 length에 저장
	char symbol;						
	evalStackTop = -1;					//연산스택에서 top의 위치를 -1로 초기화
	for(int i = 0; i < length; i++)		//i=0~(길이-1)까지 반복하면서
	{
		symbol = postfixExp[i];			//표기식 한 글자씩 symbol에 저장
		if(getToken(symbol) == operand) {	//피연산자(숫자)이면
			evalPush(symbol - '0');		//문자-48을 스택에 삽입
		}
		else {	//피연산자가 아니면(연산자이면)
			op2 = evalPop();	//스택에 원소를 삭제하여 그 값을 op2에 저장
			op1 = evalPop();	//스택에 원소를 삭제하여 그 값을 op1에 저장
			switch(getToken(symbol)) {
			case plus: evalPush(op1 + op2); break;	//plus 연산자이면 + 연산을 한 후 연산스택에 삽입
			case minus: evalPush(op1 - op2); break;	//minus 연산자이면 - 연산을 한 후 연산스택에 삽입
			case times: evalPush(op1 * op2); break;	//times 연산자이면 * 연산을 한 후 연산스택에 삽입
			case divide: evalPush(op1 / op2); break;	//divide 연산자이면 / 연산을 한 후 연산스택에 삽입
			default: break;	//그 외
			}
		}
	}
	evalResult = evalPop();	//스택에 원소를 삭제하여 그 값을 evalResult에 저장
}

