#include<iostream>
#include<vector>

class CrestikiNoliki {
private:
	char pole[3][3] = {};
	// ����������� ������
	bool _crestikNolik(int row, int column, char crestikOrNolik) {
		if (pole[row][column] != ' ') {
			pole[row][column] = crestikOrNolik;
			return true;
		}
		else
			return false;
	}
	// �������� ���� ���������� ��������
	bool ifWinNolik() {
		// �������� �������������� ����������
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
		// �������� ������������ ����������
		else if (pole[0][0] == 'o' &&
			pole[1][1] == 'o' &&
			pole[2][2] == 'o')
			return true;
		else if (pole[0][2] == 'o' &&
			pole[1][1] == 'o' &&
			pole[2][0] == 'o')
			return true;
		// �������� ������������ ����������
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
		// �������� ������������ ����������
		else if (pole[0][0] == 'x' &&
			pole[1][1] == 'x' &&
			pole[2][2] == 'x')
			return true;
		else if (pole[0][2] == 'x' &&
			pole[1][1] == 'x' &&
			pole[2][0] == 'x')
			return true;
		// �������� ������������ ����������
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

	// ���� ������ � ��������
	void _startGame() {
		setlocale(NULL, "Russian");
		// ����� �����
		int hodNolik, hodCrestik;
		// ���������� ��� ��������� ����� �� �����
		int row, column;
		std::cout << "��������! ���������� ��� ��� (������): 12, ��� 1 - ��� �������, � 2 - ��� ���" << std::endl;
		// ����
		while (!ifWinNolik() && !ifWinCrestik()) {
			// ���������� ������ ��� ����
			std::cout << "��� ������: ";
			std::cin >> hodNolik;
			row = (hodNolik % 10) - 1;
			column = (hodNolik / 10) - 1;
			if (!ifHodP(row, column, 'o'))
				_crestikNolik(row, column, 'o');
			else {
				std::cout << "������ ������!" << std::endl;
				std::cout << "��� ������: ";
				std::cin >> hodNolik;
				row = (hodNolik % 10) - 1;
				column = (hodNolik / 10) - 1;
			}
			coutPole();

			std::cout << "��� ��������: ";
			std::cin >> hodCrestik;
			row = (hodCrestik % 10) - 1;
			column = (hodCrestik / 10) - 1;
			if (!ifHodP(row, column, 'x'))
				_crestikNolik(row, column, 'x');
			else {
				std::cout << "��� ��������: ";
				std::cin >> hodCrestik;
				row = (hodCrestik % 10) - 1;
				column = (hodCrestik / 10) - 1;
			}
			coutPole();
		}
		if (ifWinCrestik())
			std::cout << "������� �������" << std::endl;
		if (ifWinNolik())
			std::cout << "������� �����" << std::endl;
	}
public:

	// ������ ����
	CrestikiNoliki(char yesOrNo) {
		setlocale(NULL, "Russian");
		switch (yesOrNo) {
		case 'y':
			std::cout << "����, ������ ����� �����, ��������� ��� :)" << std::endl;
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
	// ���������� ���� char yesOrNo
	char yesOrNo;
	std::cout << "������! ��� ���� �������� ������, �� ������? (y - ��, n - ���)" << std::endl;
	std::cin >> yesOrNo;
	CrestikiNoliki obj(yesOrNo);
	obj.coutPole();
	return 0;
}