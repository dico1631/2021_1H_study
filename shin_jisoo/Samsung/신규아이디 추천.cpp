#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {

	//1�ܰ� : new_id �� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ
	for (int i = 0;i < new_id.length();i++) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			new_id[i] = tolower(new_id[i]);
	}

	//2�ܰ� :  new_id ���� ���ĺ� �ҹ���, ����, ����, ����, ��ħǥ�� ������ ��� ���ڸ� ����
	for (int i = 0;i < new_id.length();) {
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
			|| new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
			i++;
			continue;
		}

		new_id.erase(new_id.begin() + i);
	}

	//3�ܰ� : new_id ���� ��ħǥ�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ�� ġȯ
	for (int i = 1;i < new_id.length();) {
		if (new_id[i] == '.' && new_id[i - 1] == '.') {
			new_id.erase(new_id.begin() + i);
			continue;
		}
		else i++;
	}

	//4�ܰ� : new_id ���� ��ħǥ�� ó���̳� ���� ��ġ�ϸ� ����
	if (new_id.front() == '.') new_id.erase(new_id.begin());
	if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

	//5�ܰ� : new_id �� �� ���ڿ��̶��, new_id �� "a" ����
	if (new_id.length() == 0)
		new_id = 'a';

	//6�ܰ� : new_id �� ���̰� 16�̻��̶��, 
	//new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� ����
	//���� ���� �� ��ħǥ�� new_id �� ���� ��ġ�Ѵٸ� ���� ��ġ�� 
	//��ħǥ ���� ����
	if (new_id.length() >= 16) {
		while (new_id.length() != 15) {
			new_id.erase(new_id.begin() + 15);
		}
	}
	if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

	//7�ܰ� : new_id �� ���̰� 2�� ���϶��, new_id �� ������ ���ڸ�
	//new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���̱�
	if (new_id.length() <= 2) {
		while (new_id.length() != 3) {
			new_id += new_id.back();
		}
	}

	return new_id;
}