// lr5.cpp Нелепа сдесь был
#include <iostream>
#include <iomanip>
using namespace std;

//------------------ НАЧАЛО КЛАССА СОЗДАНИЯ МАТРИЦ ---------------------------
class Matrix
{
protected:
    int row, col, i, j;
public:
    int arr[10][10];
    int q = 1, w = 1;
    Matrix() { row = 0; col = 0; }

    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
    }

    void getData()
    {
        cout << ">>> Введите " << (row * col) << " элементов через Enter:\n";
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                cout << ">>> [ " << q << " ] [ " << w << " ] = "; cin >> arr[i][j];
                w = w + 1;
            }
            w = 1;
            q = q + 1;
        }
        cout << endl;
    }

    void print()
    {
        for (i = 0; i < row; i++)
        {
            cout << ">>> ";
            for (j = 0; j < col; j++)
            {
                cout << setw(3) << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    ~Matrix() {}
};//-----------------КОНЕЦ КЛАССА СОЗДАНИЯ МАТРИЦ ----------------------------

//------------------ 1 НАЧАЛО КЛАСА СЛОЖЕНИЯ----------------------------------
class Operation_addition : public Matrix
{
public:
    void Addition(Matrix& obj1, Matrix& obj2, int row, int col)
    {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = obj1.arr[i][j] + obj2.arr[i][j];
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};//---------------- КОНЕЦ КЛАСА СЛОЖЕНИЯ-------------------------------------

// ----------------- 2 НАЧАЛО КЛАССА РАЗНИЦЫ ---------------------------------
class Operation_difference : public Matrix
{
public:
    void Difference(Matrix& obj1, Matrix& obj2, int col, int row)
    {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = obj1.arr[i][j] - obj2.arr[i][j];
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};// --------------- КОНЕЦ КЛАССА РАЗНИЦЫ ----------------------------------

// ----------------- 3 НАЧАЛО КЛАССА УМНОЖЕНИЕ -------------------------------
class Operation_multiplication : public Matrix
{
public:
    void Multiplication(Matrix& obj1, Matrix& obj2, int row, int col)
    {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = 0;
                for (int k = 0; k < col; k++) {
                    arr[i][j] += obj1.arr[i][k] * obj2.arr[k][j];
                }
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};// --------------- КОНЕЦ КЛАССА УМНОЖЕНИЕ ----------------------------------

//------------------ 4 НАЧАЛО КЛАСС ТРАНСПОРТИРОВАНИЯ МАТРИЦЫ ----------------
class Operation_transpose : public Matrix
{
public:
    void Transpose(Matrix& obj1, int row, int col)
    {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = obj1.arr[j][i];
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};//---------------- КОНЕЦ КЛАСС ТРАНСПОРТИРОВАНИЯ МАТРИЦЫ -------------------

//------------------ 5 НАЧАЛО КЛАСС ОПРЕДЕЛИТЕЛЯ МАТРИЦЫ ---------------------
class Operation_determinant : public Matrix
{
public:
    void Determinant(Matrix& obj) //процедура вычеркивания строки и столбца
    {
        int det = obj.arr[0][0] * obj.arr[1][1] * obj.arr[2][2] + obj.arr[1][0] * obj.arr[0][2] * obj.arr[2][1] +
            obj.arr[0][1] * obj.arr[1][2] * obj.arr[2][0] - obj.arr[2][0] * obj.arr[1][1] * obj.arr[0][2] -
            obj.arr[0][1] * obj.arr[1][0] * obj.arr[2][2] - obj.arr[0][0] * obj.arr[1][2] * obj.arr[2][1];

        cout << det;
    }
};//---------------- КОНЕЦ КЛАСС ОПРЕДЕЛИТЕЛЯ МАТРИЦЫ ------------------------

//------------------ 6 НАЧАЛО КЛАСС УМНОЖЕНИЯ МАТРИЦЫ НА ЧИСЛО ---------------
class Operation_multiplication_by_number : public Matrix
{
public:
    void Multiplication_by_number(Matrix& obj1, int row, int col, double number)
    {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = obj1.arr[i][j] * number;
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};//---------------- КОНЕЦ КЛАСС УМНОЖЕНИЯ МАТРИЦЫ НА ЧИСЛО ------------------

//------------------ 7 НАЧАЛО КЛАСС НАХОЖДЕНИЯ ОБРАТНОЙ МАТРИЦЫ --------------
class Operation_inverse_matrix : public Matrix
{
public:
    void Inverse_matrix(Matrix& obj1, int row, int col)
    {
        arr[0][0] = 1 * (obj1.arr[1][1] * obj1.arr[2][2] - obj1.arr[1][2] * obj1.arr[2][1]);
        arr[0][1] = -1 * (obj1.arr[1][0] * obj1.arr[2][2] - obj1.arr[1][2] * obj1.arr[2][0]);
        arr[0][2] = 1 * (obj1.arr[1][0] * obj1.arr[2][1] - obj1.arr[1][1] * obj1.arr[2][0]);
        arr[1][0] = -1 * (obj1.arr[0][1] * obj1.arr[2][2] - obj1.arr[0][2] * obj1.arr[2][1]);
        arr[1][1] = 1 * (obj1.arr[0][0] * obj1.arr[2][2] - obj1.arr[0][2] * obj1.arr[2][0]);
        arr[1][2] = -1 * (obj1.arr[0][0] * obj1.arr[2][1] - obj1.arr[0][1] * obj1.arr[2][0]);
        arr[2][0] = 1 * (obj1.arr[0][1] * obj1.arr[1][2] - obj1.arr[0][2] * obj1.arr[1][1]);
        arr[2][1] = -1 * (obj1.arr[0][0] * obj1.arr[1][2] - obj1.arr[0][2] * obj1.arr[1][0]);
        arr[2][2] = 1 * (obj1.arr[0][0] * obj1.arr[1][1] - obj1.arr[0][1] * obj1.arr[1][0]);
        
        //Выводим на экран матрицу
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};//---------------- КОНЕЦ КЛАСС НАХОЖДЕНИЯ ОБРАТНОЙ МАТРИЦЫ -----------------

//------------------ 8 НАЧАЛО КЛАСС ВОЗВЕДЕНИЕ В СТЕПЕНЬ ---------------------
class Operation_exponentiation : public Matrix
{
public:
    void Exponentiation(Matrix& obj1, int row, int col)
    {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = 0;
                for (int k = 0; k < col; k++) {
                    arr[i][j] += obj1.arr[i][k] * obj1.arr[k][j];
                }
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }     
};//---------------- КОНЕЦ КЛАСС ВОЗВЕДЕНИЕ В СТЕПЕНЬ ------------------------

//------------------ НАЧАЛО МЕНЮ ---------------------------------------------
void menu()
{
    cout << "*********** М Е Н Ю ***********\n\n"
        << ">>>[1]-Сложение матриц (A+B).\n"
        << ">>>[2]-Разность матриц (A-B).\n"
        << ">>>[3]-Умножение матриц (A*B).\n"
        << ">>>[4]-Транспонирование матрицы A или В.\n"
        << ">>>[5]-Определитель матрицы A или В.\n"
        << ">>>[6]-Умножение матрицы А или В на число.\n"
        << ">>>[7]-Нахождение обратной матрицы алгоритм.\n"
        << ">>>[8]-Возведение в квадрат матрицы А или В.\n\n";
};//---------------- КОНЕЦ МЕНЮ ----------------------------------------------

// ----------------- ГЛАВНАЯ ФУНКЦИЯ -----------------------------------------
int main()
{
    setlocale(LC_ALL, "Ru");

    int row = 3;
    int col = 3;

    Matrix A(row, col);
    A.getData();

    Matrix B(row, col);
    B.getData();

    Operation_addition addition;
    Operation_difference difference;
    Operation_multiplication multiplication;
    Operation_transpose transpose;
    Operation_determinant determinant;
    Operation_multiplication_by_number multiplication_by_number;
    Operation_inverse_matrix inverse_matrix;
    Operation_exponentiation exponentiation;

    cout << "\n>>>Матрица A\n"; A.print();
    cout << "\n>>>Матрица B\n"; B.print();

    menu();

    int x, y, number;
    cout << "\n>>>Выберете опцию в меню: "; cin >> x;
    if (x == 1)
    {
        cout << "\n>>>Сложение матриц (A+B)\n";
        addition.Addition(A, B, row, col);
    }
    else if (x == 2)
    {
        cout << "\n>>>Разность матриц (A-B)\n";
        difference.Difference(A, B, row, col);
    }
    else if (x == 3)
    {
        cout << "\n>>>Умножение матриц (A*B)\n";
        multiplication.Multiplication(A, B, row, col);
    }
    else if (x == 4)
    {
        cout << "\n>>>Транспонирование матрицы A или В\n";
        cout << "\n>>>Какую матрицу вы хотите транспонировать 1 или 2? "; cin >> y;
        if (y == 1)
            transpose.Transpose(A, row, col);
        else if (y == 2)
            transpose.Transpose(B, row, col);
    }
    else if (x == 5)
    {
        cout << "\n>>>Определитель матрицы A или В";
        cout << "\n>>>В какой матрице вы хотите найти определитель 1 или 2? "; cin >> y;
        if (y == 1)
            determinant.Determinant(A);

        else if (y == 2)
            determinant.Determinant(B);
    }
    else if (x == 6)
    {
        cout << "\n>>>Умножение матрицы А или В на число\n";
        cout << "\n>>>Выберите матрицу 1 или 2 : "; cin >> y;
        cout << "\n>>>На какое цисло вы хотите умножить? "; cin >> number;
        if (y == 1)
            multiplication_by_number.Multiplication_by_number(A, row, col, number);
        else if (y == 2)
            multiplication_by_number.Multiplication_by_number(B, row, col, number);
    }
    else if (x == 7)
    {
        cout << "\n>>>Нахождение обратной матрицы алгоритм\n";
        cout << "\n>>>Выберите матрицу 1 или 2: "; cin >> y;
        if (y == 1)
            inverse_matrix.Inverse_matrix(A, row, col);

        else if (y == 2)
            inverse_matrix.Inverse_matrix(B, row, col);
    }
    else if (x == 8)
    {
        cout << "\n>>>Возведение в степень матрицы\n";
        cout << "\n>>>Выберите матрицу 1 или 2: "; cin >> y;
        if (y == 1)
            exponentiation.Exponentiation(A, row, col);

        else if (y == 2)
            exponentiation.Exponentiation(B, row, col);
    }
    else
    {
        return 0;
    }
};
