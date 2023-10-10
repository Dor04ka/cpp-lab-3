#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long f(const long* m, long temp, const long size, long sum1, long sum2) {
	/*
	использую const для того, чтобы массив m и переменная size(задает в начале main() размер
	массива / кол-во вводимых чисел) не вызывались постоянно при каждом новом вызове ф-ии f(),
	а были равны соотв заданным значениям в main()
	*/
	if (temp < size) {
		long first = f(m, temp + 1, size, sum1 + m[temp], sum2); //отдаем кашу 1ому
		long second = f(m, temp + 1, size, sum1, sum2 + m[temp]); //отдаем кашу 2ому
		return min(first, second);
	}
	else { return abs(sum1 - sum2); }
	/*
	если произошло равенство, то это значит, что мы перебрали все доступные миски
	(переданные в массив числа), можно считать разницу
	*/

}

int main() {

	long size; // размер массива
	cin >> size;
	long* m = new long[size]; // сам массив
	for (long temp = 0; temp < size; ++temp) { //пока счетчик меньше заявленного кол-ва чисел
		long a;
		cin >> a;
		m[temp] = a;
	}

	cout << f(m, 0, size, 0, 0);
}