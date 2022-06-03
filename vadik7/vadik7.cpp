#include <iostream>
#include <clocale>
#include <clocale>
#include <windows.h>
using namespace std;
const int n = 25;
void sodanie_zapolnenie(int m, int array[n]) {
    srand(time(0));
    for (int i = 0; i < m; i++) { // Заполняем массив случайными целыми числами от 0 до 30
        array[i] = rand() % 40;
    }
}
void vivod(int m, int array[n]) { // Vivodim massiv na ekran
    for (int i = 0; i < m; i++) {
        cout << array[i];
        if (i < m - 1) { // Do poslednego elemanta massiva stavitsa zapyataya
            cout << ", ";
        }
    }
}
int srArif(int m, int array[n]) { // Ishem srednee arifmeticheskoe 
    int count = 0, sum = 0;
    for (int i = 0; i < m; i++) {
        sum += array[i];
        count += 1;
    }
    return sum / count;
}
void zapis(int m, int array[n], int array1[n]) {
    int e = 0;
    for (int i = 0; i < m; i++) {
        if (array[i] > srArif(m, array)) { // Esli element massiva bolshe chem srednee arifmeticheskoe dobavlyaem etot element v massiv Z
            array1[e] = array[i];
            e += 1;
        }
    }
    vivod(e, array1);
}
void udalenie(int m, int array[n], int array1[n]) { // Udalyaem elementi massiva yavlyausheesya prosimi chislami
    int e = 0, b = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 2; j < array[i]; j++) { // Простое число делится только на 1 и на себя без остатка, с помощью этого св-ва удалим простые числа из массива
            if (array[i] % j == 0) {
                array1[e] = array[i];
                b = 1;
            }
            else {
                b = 0;
            }
        if (b == 1) {
            e += 1; // Счетчик для выделения места в массиве, где не будет простых чисел 
            break;
        }
        }
        
    }
    vivod(e, array1);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    cout << "Введите размер массива Y: " << "\n";
    cin >> a;
    int Y[n], Z[n], Y2[n];
    sodanie_zapolnenie(a, Y);
    cout << "Массив Y, заполенный случайно сгенерированными числами: " << "\n";
    cout << "[";
    vivod(a, Y);
    cout << "]";
    cout << "\n" << "Среднее арифметическое чисел массива: " << srArif(a, Y) << "\n";
    cout << "Массив Z, заполненный числами из массива Y, большими, чем среднее арифметическое всех чисел массива Y: " << "\n";
    cout << "[";
    zapis(a, Y, Z);
    cout << "]";
    cout << "\n" << "Массив Y2, с удаленными простыми числами: ";
    cout << "[";
    udalenie(a, Y, Y2);
    cout << "]";

    
    

}