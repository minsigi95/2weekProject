#include <iostream>
#include <string>
using namespace std;

// �߻� Ŭ���� (�⺻ Ŭ����)
class Player {
protected:
    string job_name;
    string nickname;
    int level;
    int HP, MP;
    int power, defence, accuracy, speed;

public:
    // ������
    Player(string nickname) : nickname(nickname), level(1), HP(100), MP(50),
        power(10), defence(5), accuracy(5), speed(5) {
    }

    // ���� ���� �Լ�
    virtual void attack() = 0;

    // �÷��̾� ���� ���
    void printPlayerStatus();
};

// Player::printPlayerStatus �Լ� ����
void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* ���� �ɷ�ġ" << endl;
    cout << "�г���: " << nickname << endl;
    cout << "����: " << job_name << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "���ݷ�: " << power << endl;
    cout << "����: " << defence << endl;
    cout << "��Ȯ��: " << accuracy << endl;
    cout << "�ӵ�: " << speed << endl;
    cout << "------------------------------------" << endl;
}

// ���� Ŭ����
class Warrior : public Player {
public:
    Warrior(string nickname) : Player(nickname) {
        job_name = "Warrior";
        power = 20;
        defence = 15;
    }
    void attack() override {
        cout << nickname << " (����): ������ ���� �ֵθ��ϴ�!" << endl;
    }
};

// ������ Ŭ����
class Magician : public Player {
public:
    Magician(string nickname) : Player(nickname) {
        job_name = "Magician";
        MP = 100;
        power = 25;
    }
    void attack() override {
        cout << nickname << " (������): ȭ������ �߻��մϴ�!" << endl;
    }
};

// ���� Ŭ����
class Thief : public Player {
public:
    Thief(string nickname) : Player(nickname) {
        job_name = "Thief";
        speed = 20;
        accuracy = 15;
    }
    void attack() override {
        cout << nickname << " (����): �׸��ڿ��� �ܰ����� ��ϴ�!" << endl;
    }
};

// �ü� Ŭ����
class Archer : public Player {
public:
    Archer(string nickname) : Player(nickname) {
        job_name = "Archer";
        accuracy = 20;
        speed = 15;
    }
    void attack() override {
        cout << nickname << " (�ü�): ��ī�ο� ȭ���� ���ϴ�!" << endl;
    }
};

// ���� �Լ�
int main() {
    Player* players[4]; // Player ������ �迭

    int choice;
    string name;

    cout << "ĳ���͸� �����ϼ��� (1. ���� 2. ������ 3. ���� 4. �ü�): ";
    cin >> choice;

    cout << "�г����� �Է��ϼ���: ";
    cin >> name;

    switch (choice) {
    case 1: players[0] = new Warrior(name); break;
    case 2: players[0] = new Magician(name); break;
    case 3: players[0] = new Thief(name); break;
    case 4: players[0] = new Archer(name); break;
    default:
        cout << "�߸��� �Է��Դϴ�!" << endl;
        return 0;
    }

    // ���� ���
    players[0]->printPlayerStatus();

    // ���� ����
    players[0]->attack();

    // �޸� ����
    delete players[0];

    return 0;
}