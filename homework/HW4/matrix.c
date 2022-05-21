#include <stdio.h>
#include <stdlib.h>	//���� �޸� �Ҵ� �� �̿�
#include <time.h>	//���� ���� �� �̿�

/* Method Declaration */
int** create_matrix(int row, int col);	//���� �޸� �Ҵ��� �̿��ؼ� ����� ����� �Լ�
void print_matrix(int** matrix, int row, int col);	//row*col ũ���� ����� ����ϴ� �Լ�
int free_matrix(int** matrix, int row, int col);	//���� �޸� �Ҵ��� �����ϴ� �Լ�
int fill_data(int** matrix, int row, int col);		//����� ���Ҹ� ������ ä��� �Լ�
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);		//����� ���� ������ �ϴ� �Լ�
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);	//����� ���� ������ �ϴ� �Լ�
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);		//��ġ����� �����ϴ� �Լ�
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);		//����� ���� ������ �ϴ� �Լ�

int main()
{
    char command;	//��ɾ ������ char�� ���� ����
    printf("[----- [�迹��]  [2021039010] -----]\n");

    int row, col;	//����� �� ũ��� �� ũ�⸦ ������ int�� ���� ����
    srand(time(NULL));	//������ �ٸ��� �����ϱ� ���� �ð��� seed�� �ϱ�

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);	//��� ���� �Է¹���
    int** matrix_a = create_matrix(row, col);	//create_matrix()�� ���a(�ּҰ�)�� ����
    int** matrix_b = create_matrix(row, col);	//create_matrix()�� ���b(�ּҰ�)�� ����
    int** matrix_a_t = create_matrix(col, row);	//create_matrix()�� ���a_t(�ּҰ�)�� ����

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) { return -1; }	 //���a�� b�� ������� ���, -1�� return.

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
        scanf(" %c", &command);             //��ɾ� �����ϱ�

        switch (command) {                   //switch case�� ���ǹ� �̿�
        case 'z': case 'Z':                 //z(Z)�� �Է����� ���(Initialize Matrix)
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);	//fill_data()�� ���a�� ���Ҹ� ������ ä��
            fill_data(matrix_b, row, col);	//fill_data()�� ���b�� ���Ҹ� ������ ä��
            break;
        case 'p': case 'P':                 //p(P)�� �Է����� ���(Print Matrix)
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);   //print_matrix()�� ���a ���
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);   //print_matrix()�� ���b ���
            break;
        case 'a': case 'A':                 //a(A)�� �Է����� ���(Add Matrix)
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);  //addition_matrix()�� ���a�� ���b�� ���� ���� ����
            break;
        case 's': case 'S':                 //s(S)�� �Է����� ���(Subtract Matrix)
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);   //subtraction_matrix()�� ���a�� ���b�� ���� ���� ����
            break;
        case 't': case 'T':                //t(T)�� �Է����� ���(Transpose matrix_a)
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);	   //transpose_matrix()�� ���a�� ��ġ����� ���a_t�� ����
            print_matrix(matrix_a_t, col, row);						//print_matrix()�� ���a�� ��ġ����� ���a_t�� ���
            break;
        case 'm': case 'M':                 //m(M)�� �Է����� ���(Multiply Matrix)
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);   //transpose_matrix()�� ���a�� ��ġ����� ���a_t�� ����
            multiply_matrix(matrix_a, matrix_a_t, row, col);    //multiply_matrix()�� ���a�� ���a_t�� ���� ������ ����
            break;
        case 'q': case 'Q':                 //q(Q)�� �Է����� ���(Quit)
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);  //free_matrix()�� ���a_t �޸� �Ҵ� ����
            free_matrix(matrix_a, row, col);    //free_matrix()�� ���a �޸� �Ҵ� ����
            free_matrix(matrix_b, row, col);    //free_matrix()�� ���b �޸� �Ҵ� ����
            break;
        default:                           //�̿��� ���� �Է����� ���
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');	//do-while : q(Q)�� �Էµ� ������ ��� �ݺ���

    return 1;
}

//���� �޸� �Ҵ��� �̿��ؼ� ����� ����� �Լ�
int** create_matrix(int row, int col)
{
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return NULL;
    }
    //2���� �迭�� ���� ���� 1���� �迭ó�� �����Ͽ� ���� ũ�⸸ŭ �Ҵ�
    int** matrix = (int**)malloc(sizeof(int*) * row);
    //�� �࿡ ���� ���� ũ�⸸ŭ �����Ҵ�. ���������� 2�����迭�� ���� �Ҵ��
    for (int r = 0; r < row; r++) {
        matrix[r] = (int*)malloc(sizeof(int) * col);
    }

    //��ó�� �˻� - matrix�� �޸� �Ҵ��� ������ ��� NULL�� ������
    if (matrix == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        return NULL;
    }

    return matrix;  //matrix(�ּҰ�)�� ����
}

// row*col ũ���� ����� ����ϴ� �Լ�
void print_matrix(int** matrix, int row, int col)
{
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return;
    }
    //���� for loop�� ����ؼ� 2���� �迭�� ���Ҹ� ���ʴ�� �����
    for (int matrix_row = 0; matrix_row < row; matrix_row++) {
        for (int matrix_col = 0; matrix_col < col; matrix_col++)
            printf("%3d ", matrix[matrix_row][matrix_col]);
        printf("\n");   //���� row�� �Ѿ
    }
    printf("\n");
    //��ó�� �˻� - matrix�� ���� ���������� ����ִ���
    if (matrix == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        return;
    }

    return;
}

//���� �޸� �Ҵ��� �����ϴ� �Լ�
int free_matrix(int** matrix, int row, int col)
{
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return -1;
    }
    //���� �޸� �Ҵ��� �����ϴ� �κ�
    for (int r = 0; r < row; r++) {
        free(matrix[r]);    //�� ���� ���� matrix[r] �޸� �Ҵ� ���� ��
    }
    free(matrix);  //matrix �޸� �Ҵ� ����
    return 1;
}

//����� ���Ҹ� ������ ä��� �Լ�
int fill_data(int** matrix, int row, int col)
{
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return -1;
    }
    //������ ä��� �κ�
    for (int matrix_row = 0; matrix_row < row; matrix_row++)
        for (int matrix_col = 0; matrix_col < col; matrix_col++)
            matrix[matrix_row][matrix_col] = rand() % 20;     //������ 0~19 ������ ���� ���� ���������� ä��
    //��ó�� �˻� - matrix�� ���� ���������� ����ִ���
    if (matrix == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        return -1;
    }
    return 1;
}

//����� ���� ������ �ϴ� �Լ�
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    //����� ���� ������ �� ����� ������ matrix ����, ũ�Ⱑ ���� �� ������ �� �����Ƿ� ũ��� �״�� row, col��
    int** matrix_tmp = create_matrix(row, col);
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return -1;
    }
    //����� ���� ���� ����
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix_tmp[r][c] = matrix_a[r][c] + matrix_b[r][c];
        }
    }
    //��ó�� �˻� - matrix�� ���� ���������� ����ִ���
    if (matrix_a == NULL || matrix_b == NULL || matrix_tmp == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        return -1;
    }

    print_matrix(matrix_tmp, row, col); //print_matrix()�� ����� ���
    free_matrix(matrix_tmp, row, col);  //free_matrix()�� �ӽ� ����� �޸� �Ҵ� ����
    return 1;
}

//����� ���� ������ �ϴ� �Լ�
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    //����� ���� ������ �� ����� ������ matrix ����, ũ�Ⱑ ���� �� ������ �� �����Ƿ� ũ��� �״�� row, col��
    int** matrix_tmp = create_matrix(row, col);
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return -1;
    }
    //����� ���� ���� ����
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix_tmp[r][c] = matrix_a[r][c] - matrix_b[r][c];
        }
    }
    //��ó�� �˻� - matrix�� ���� ���������� ����ִ���
    if (matrix_a == NULL || matrix_b == NULL || matrix_tmp == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        return -1;
    }

    print_matrix(matrix_tmp, row, col); //print_matrix()�� ����� ���
    free_matrix(matrix_tmp, row, col);  //free_matrix()�� �ӽ� ����� �޸� �Ҵ� ����
    return 1;
}

//��ġ����� �����ϴ� �Լ�
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return -1;
    }
    //��ġ���(��� ���� �ٲ�) �����
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix_t[r][c] = matrix[c][r];
        }
    }
    //��ó�� �˻� - matrix�� ���� ���������� ����ִ���
    if (matrix == NULL || matrix_t == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        return -1;
    }
    return 1;
}

//����� ���� ������ �ϴ� �Լ�
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    //����� ���� ������ �� ����� ������ matrix ����, ����� ������ ũ��� row*row��
    int** matrix_tmp = create_matrix(row, row);
    //��ó�� �˻� - row�� col�� 0���ϸ� �ȵ�
    if (row <= 0 || col <= 0) {
        printf("�߸��� ��� �� ũ���Դϴ�.\n");
        return -1;
    }
    //����� ���� ���� ����
    for (int r = 0; r < row; r++) {
        for (int R = 0; R < row; R++) {
            matrix_tmp[r][R] = 0;   //������ �����̹Ƿ� �̸� 0���� �ʱ�ȭ
            for (int c = 0; c < col; c++)
                matrix_tmp[r][R] += matrix_a[r][c] * matrix_t[c][R];
        }
    }

    //��ó�� �˻� - matrix�� ���� ���������� ����ִ���
    if (matrix_a == NULL || matrix_t == NULL || matrix_tmp == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        return -1;
    }
    print_matrix(matrix_tmp, row, row); //print_matrix()�� ����� ���
    free_matrix(matrix_tmp, row, row);  //free_matrix()�� �ӽ� ����� �޸� �Ҵ� ����
    return 1;
}