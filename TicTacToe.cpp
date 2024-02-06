#include<iostream>
#include<vector>

class CrestikiNoliki {
private:
	char pole[3][3] = {};
	// Определение логики
	bool _crestikNolik(int row, int column, char crestikOrNolik) {
		if (pole[row][column] != ' ') {
			pole[row][column] = crestikOrNolik;
			return true;
		}
		else
			return false;
	}
	// Проверка всех комбинаций выиграша
	bool ifWinNolik() {
		// Проверка горизантальных комбинаций
		if (pole[0][0] == 'o' &&
			pole[0][1] == 'o' &&
			pole[0][2] == 'o')
			return true;
		else if (pole[1][0] == 'o' &&
			pole[1][1] == 'o' &&
			pole[1][2] == 'o')
			return true;
		else if (pole[2][0] == 'o' &&
			pole[2][1] == 'o' &&
			pole[2][2] == 'o')
			return true;
		// Проверка диагональных комбинаций
		else if (pole[0][0] == 'o' &&
			pole[1][1] == 'o' &&
			pole[2][2] == 'o')
			return true;
		else if (pole[0][2] == 'o' &&
			pole[1][1] == 'o' &&
			pole[2][0] == 'o')
			return true;
		// Проверка вертикальных комбинаций
		else if (pole[0][0] == 'o' &&
			pole[1][0] == 'o' &&
			pole[2][0] == 'o')
			return true;
		else if (pole[0][1] == 'o' &&
			pole[1][1] == 'o' &&
			pole[2][1] == 'o')
			return true;
		else if (pole[0][2] == 'o' &&
			pole[1][2] == 'o' &&
			pole[2][2] == 'o')
			return true;
		return false;
	}
	bool ifWinCrestik() {
		if (pole[0][0] == 'x' &&
			pole[0][1] == 'x' &&
			pole[0][2] == 'x')
			return true;
		else if (pole[1][0] == 'x' &&
			pole[1][1] == 'x' &&
			pole[1][2] == 'x')
			return true;
		else if (pole[2][0] == 'x' &&
			pole[2][1] == 'x' &&
			pole[2][2] == 'x')
			return true;
		// Проверка диагональных комбинаций
		else if (pole[0][0] == 'x' &&
			pole[1][1] == 'x' &&
			pole[2][2] == 'x')
			return true;
		else if (pole[0][2] == 'x' &&
			pole[1][1] == 'x' &&
			pole[2][0] == 'x')
			return true;
		// Проверка вертикальных комбинаций
		else if (pole[0][0] == 'x' &&
			pole[1][0] == 'x' &&
			pole[2][0] == 'x')
			return true;
		else if (pole[0][1] == 'x' &&
			pole[1][1] == 'x' &&
			pole[2][1] == 'x')
			return true;
		else if (pole[0][2] == 'x' &&
			pole[1][2] == 'x' &&
			pole[2][2] == 'x')
			return true;
		return false;
	}
	bool ifHodP(int row, int column, char crestikOrNolik) {
		if (crestikOrNolik == 'o') {
			if (pole[row][column] == 'x')
				return true;
			else
				return false;
		}
		else if (crestikOrNolik == 'x') {
			if (pole[row][column] == 'o')
				return true;
			else
				return false;
		}
	}

	// Ходы нолика и крестика
	void _startGame() {
		setlocale(NULL, "Russian");
		// Запис ходов
		int hodNolik, hodCrestik;
		// Переменные для разбеения числа на цифры
		int row, column;
		std::cout << "ВНИМАНИЕ! Указывайте ход так (пример): 12, где 1 - это столбец, а 2 - это ряд" << std::endl;
		// Ходы
		while (!ifWinNolik() && !ifWinCrestik()) {
			// Определине логики для хода
			std::cout << "Ход нолика: ";
			std::cin >> hodNolik;
			row = (hodNolik % 10) - 1;
			column = (hodNolik / 10) - 1;
			if (!ifHodP(row, column, 'o'))
				_crestikNolik(row, column, 'o');
			else {
				std::cout << "Клетка занята!" << std::endl;
				std::cout << "Ход нолика: ";
				std::cin >> hodNolik;
				row = (hodNolik % 10) - 1;
				column = (hodNolik / 10) - 1;
			}
			coutPole();

			std::cout << "Ход крестика: ";
			std::cin >> hodCrestik;
			row = (hodCrestik % 10) - 1;
			column = (hodCrestik / 10) - 1;
			if (!ifHodP(row, column, 'x'))
				_crestikNolik(row, column, 'x');
			else {
				std::cout << "Ход крестика: ";
				std::cin >> hodCrestik;
				row = (hodCrestik % 10) - 1;
				column = (hodCrestik / 10) - 1;
			}
			coutPole();
		}
		if (ifWinCrestik())
			std::cout << "Выиграл крестик" << std::endl;
		if (ifWinNolik())
			std::cout << "Выиграл нолик" << std::endl;
	}
public:

	// Начало игры
	CrestikiNoliki(char yesOrNo) {
		setlocale(NULL, "Russian");
		switch (yesOrNo) {
		case 'y':
			std::cout << "Итак, играть нужно вдвоём, впринципе все :)" << std::endl;
			_startGame();
			break;
		case 'n':
			exit(0);
			break;
		}
	}

	inline void coutPole() const {
		std::cout << "1 | " << pole[0][0] << " | " << pole[0][1] <<
			" | " << pole[0][2] << " |\n2 | " << pole[1][0] << " | " << pole[1][1]
			<< " | " << pole[1][2] << " |\n3 | " << pole[2][0] << " | " << pole[2][1] << " | " << pole[2][2] << " |\n"
			"   1" << "   2" << "   3" << std::endl;
	}
};

int main() {
	setlocale(NULL, "Russian");
	// Переменная типа char yesOrNo
	char yesOrNo;
	std::cout << "Привет! Это игра крестики нолики, вы готовы? (y - да, n - нет)" << std::endl;
	std::cin >> yesOrNo;
	CrestikiNoliki obj(yesOrNo);
	obj.coutPole();
	return 0;
}