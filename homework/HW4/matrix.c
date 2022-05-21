#include <stdio.h>
#include <stdlib.h>	//동적 메모리 할당 시 이용
#include <time.h>	//난수 생성 시 이용

/* Method Declaration */
int** create_matrix(int row, int col);	//동적 메모리 할당을 이용해서 행렬을 만드는 함수
void print_matrix(int** matrix, int row, int col);	//row*col 크기의 행렬을 출력하는 함수
int free_matrix(int** matrix, int row, int col);	//동적 메모리 할당을 해제하는 함수
int fill_data(int** matrix, int row, int col);		//행렬의 원소를 난수로 채우는 함수
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);		//행렬의 덧셈 연산을 하는 함수
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);	//행렬의 뺄셈 연산을 하는 함수
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);		//전치행렬을 구현하는 함수
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);		//행렬의 곱셈 연산을 하는 함수

int main()
{
    char command;	//명령어를 저장할 char형 변수 선언
    printf("[----- [김예경]  [2021039010] -----]\n");

    int row, col;	//행렬의 행 크기와 열 크기를 저장할 int형 변수 선언
    srand(time(NULL));	//난수를 다르게 생성하기 위해 시간을 seed로 하기

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);	//행과 열을 입력받음
    int** matrix_a = create_matrix(row, col);	//create_matrix()로 행렬a(주소값)를 생성
    int** matrix_b = create_matrix(row, col);	//create_matrix()로 행렬b(주소값)를 생성
    int** matrix_a_t = create_matrix(col, row);	//create_matrix()로 행렬a_t(주소값)를 생성

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) { return -1; }	 //행렬a와 b가 비어있을 경우, -1을 return.

    do {
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);             //명령어 선택하기

        switch (command) {                   //switch case로 조건문 이용
        case 'z': case 'Z':                 //z(Z)를 입력했을 경우(Initialize Matrix)
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);	//fill_data()로 행렬a의 원소를 난수로 채움
            fill_data(matrix_b, row, col);	//fill_data()로 행렬b의 원소를 난수로 채움
            break;
        case 'p': case 'P':                 //p(P)를 입력했을 경우(Print Matrix)
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);   //print_matrix()로 행렬a 출력
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);   //print_matrix()로 행렬b 출력
            break;
        case 'a': case 'A':                 //a(A)를 입력했을 경우(Add Matrix)
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);  //addition_matrix()로 행렬a와 행렬b의 덧셈 연산 수행
            break;
        case 's': case 'S':                 //s(S)를 입력했을 경우(Subtract Matrix)
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);   //subtraction_matrix()로 행렬a와 행렬b의 뺄셈 연산 수행
            break;
        case 't': case 'T':                //t(T)를 입력했을 경우(Transpose matrix_a)
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);	   //transpose_matrix()로 행렬a의 전치행렬인 행렬a_t를 구함
            print_matrix(matrix_a_t, col, row);						//print_matrix()로 행렬a의 전치행렬인 행렬a_t를 출력
            break;
        case 'm': case 'M':                 //m(M)를 입력했을 경우(Multiply Matrix)
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);   //transpose_matrix()로 행렬a의 전치행렬인 행렬a_t를 구함
            multiply_matrix(matrix_a, matrix_a_t, row, col);    //multiply_matrix()로 행렬a와 행렬a_t의 곱셈 연산을 수행
            break;
        case 'q': case 'Q':                 //q(Q)를 입력했을 경우(Quit)
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);  //free_matrix()로 행렬a_t 메모리 할당 해제
            free_matrix(matrix_a, row, col);    //free_matrix()로 행렬a 메모리 할당 해제
            free_matrix(matrix_b, row, col);    //free_matrix()로 행렬b 메모리 할당 해제
            break;
        default:                           //이외의 값을 입력했을 경우
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');	//do-while : q(Q)가 입력될 때까지 계속 반복함

    return 1;
}

//동적 메모리 할당을 이용해서 행렬을 만드는 함수
int** create_matrix(int row, int col)
{
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return NULL;
    }
    //2차원 배열을 행이 모인 1차원 배열처럼 생각하여 행의 크기만큼 할당
    int** matrix = (int**)malloc(sizeof(int*) * row);
    //각 행에 대해 열의 크기만큼 동적할당. 최종적으로 2차원배열이 동적 할당됨
    for (int r = 0; r < row; r++) {
        matrix[r] = (int*)malloc(sizeof(int) * col);
    }

    //후처리 검사 - matrix에 메모리 할당을 실패한 경우 NULL을 리턴함
    if (matrix == NULL) {
        printf("메모리 할당에 실패하였습니다.\n");
        return NULL;
    }

    return matrix;  //matrix(주소값)를 리턴
}

// row*col 크기의 행렬을 출력하는 함수
void print_matrix(int** matrix, int row, int col)
{
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return;
    }
    //이중 for loop를 사용해서 2차원 배열의 원소를 차례대로 출력함
    for (int matrix_row = 0; matrix_row < row; matrix_row++) {
        for (int matrix_col = 0; matrix_col < col; matrix_col++)
            printf("%3d ", matrix[matrix_row][matrix_col]);
        printf("\n");   //다음 row로 넘어감
    }
    printf("\n");
    //후처리 검사 - matrix에 값이 정상적으로 들어있는지
    if (matrix == NULL) {
        printf("메모리 할당에 실패하였습니다.\n");
        return;
    }

    return;
}

//동적 메모리 할당을 해제하는 함수
int free_matrix(int** matrix, int row, int col)
{
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return -1;
    }
    //동적 메모리 할당을 해제하는 부분
    for (int r = 0; r < row; r++) {
        free(matrix[r]);    //각 열에 대한 matrix[r] 메모리 할당 해제 후
    }
    free(matrix);  //matrix 메모리 할당 해제
    return 1;
}

//행렬의 원소를 난수로 채우는 함수
int fill_data(int** matrix, int row, int col)
{
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return -1;
    }
    //난수로 채우는 부분
    for (int matrix_row = 0; matrix_row < row; matrix_row++)
        for (int matrix_col = 0; matrix_col < col; matrix_col++)
            matrix[matrix_row][matrix_col] = rand() % 20;     //성분을 0~19 사이의 값을 갖는 랜덤값으로 채움
    //후처리 검사 - matrix에 값이 정상적으로 들어있는지
    if (matrix == NULL) {
        printf("메모리 할당에 실패하였습니다.\n");
        return -1;
    }
    return 1;
}

//행렬의 덧셈 연산을 하는 함수
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    //행렬의 덧셈 연산을 한 결과를 저장할 matrix 선언, 크기가 같을 때 연산할 수 있으므로 크기는 그대로 row, col임
    int** matrix_tmp = create_matrix(row, col);
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return -1;
    }
    //행렬의 덧셈 연산 수행
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix_tmp[r][c] = matrix_a[r][c] + matrix_b[r][c];
        }
    }
    //후처리 검사 - matrix에 값이 정상적으로 들어있는지
    if (matrix_a == NULL || matrix_b == NULL || matrix_tmp == NULL) {
        printf("메모리 할당에 실패하였습니다.\n");
        return -1;
    }

    print_matrix(matrix_tmp, row, col); //print_matrix()로 결과를 출력
    free_matrix(matrix_tmp, row, col);  //free_matrix()로 임시 행렬의 메모리 할당 해제
    return 1;
}

//행렬의 뺄셈 연산을 하는 함수
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    //행렬의 뺄셈 연산을 한 결과를 저장할 matrix 선언, 크기가 같을 때 연산할 수 있으므로 크기는 그대로 row, col임
    int** matrix_tmp = create_matrix(row, col);
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return -1;
    }
    //행렬의 뺄셈 연산 수행
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix_tmp[r][c] = matrix_a[r][c] - matrix_b[r][c];
        }
    }
    //후처리 검사 - matrix에 값이 정상적으로 들어있는지
    if (matrix_a == NULL || matrix_b == NULL || matrix_tmp == NULL) {
        printf("메모리 할당에 실패하였습니다.\n");
        return -1;
    }

    print_matrix(matrix_tmp, row, col); //print_matrix()로 결과를 출력
    free_matrix(matrix_tmp, row, col);  //free_matrix()로 임시 행렬의 메모리 할당 해제
    return 1;
}

//전치행렬을 구현하는 함수
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return -1;
    }
    //전치행렬(행과 열이 바뀜) 만들기
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix_t[r][c] = matrix[c][r];
        }
    }
    //후처리 검사 - matrix에 값이 정상적으로 들어있는지
    if (matrix == NULL || matrix_t == NULL) {
        printf("메모리 할당에 실패하였습니다.\n");
        return -1;
    }
    return 1;
}

//행렬의 곱셈 연산을 하는 함수
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    //행렬의 곱셈 연산을 한 결과를 저장할 matrix 선언, 행렬의 연산결과 크기는 row*row임
    int** matrix_tmp = create_matrix(row, row);
    //전처리 검사 - row와 col이 0이하면 안됨
    if (row <= 0 || col <= 0) {
        printf("잘못된 행과 열 크기입니다.\n");
        return -1;
    }
    //행렬의 곱셈 연산 수행
    for (int r = 0; r < row; r++) {
        for (int R = 0; R < row; R++) {
            matrix_tmp[r][R] = 0;   //더해질 예정이므로 미리 0으로 초기화
            for (int c = 0; c < col; c++)
                matrix_tmp[r][R] += matrix_a[r][c] * matrix_t[c][R];
        }
    }

    //후처리 검사 - matrix에 값이 정상적으로 들어있는지
    if (matrix_a == NULL || matrix_t == NULL || matrix_tmp == NULL) {
        printf("메모리 할당에 실패하였습니다.\n");
        return -1;
    }
    print_matrix(matrix_tmp, row, row); //print_matrix()로 결과를 출력
    free_matrix(matrix_tmp, row, row);  //free_matrix()로 임시 행렬의 메모리 할당 해제
    return 1;
}