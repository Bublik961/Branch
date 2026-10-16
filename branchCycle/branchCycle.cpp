/*************************************************
 * Автор: Тенц Ангелина                          *
 * Вариант: 30                                   *
 * Задание: Циклы с ветвлением                   *
 *************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double pi;
  double l, d, p, v, w;
  double Re, lambda, deltaP, P, Q;
  double millimetrInMeter;
  int stepCount, decimalPlaces;

  cout << "Enter tube length, m: ";
  cin >> l;

  cout << "Enter inside diameter, mm: ";
  cin >> d;

  cout << "Enter water density: ";
  cin >> p;

  cout << "Enter kinematic viscosity: ";
  cin >> v;

  cout << "Enter number of speed values: ";
  cin >> stepCount;

  decimalPlaces = 6;
  millimetrInMeter = 1000.0;
  pi = acos(-1.0);
  d = d / millimetrInMeter;

  cout << fixed << setprecision(decimalPlaces);
  cout << "w, m/s \t\tRe \t\tlambda \t\tdelta p, Pa \tP, W\n";

  for (int stepIndex = 0; stepIndex < stepCount; ++stepIndex) {
    cout << "Enter average speed: ";
	cin >> w;

	Re = (w * d) / v;

	if (Re < 2300.0) {
	  lambda = 64.0 / Re;
	} else if (Re >= 4000.0) {
	  lambda = 0.3164 / pow(Re, 0.25);
	}

	deltaP = (lambda * l * p * pow(w, 2.0)) / (d * 2.0);
	Q = (pi * pow(d, 2.0) * w) / 4.0;
	P = deltaP * Q;

	cout << w
		 << "\t" << Re
		 << "\t" << lambda
		 << "\t" << deltaP
		 << "\t" << P << "\n";
  }

  return 0;
}

