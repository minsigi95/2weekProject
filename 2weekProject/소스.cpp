#include <iostream>
#include <string>
using namespace std;

// 추상 클래스 (기본 클래스)
class Player {
protected:
    string job_name;
    string nickname;
    int level;
    int HP, MP;
    int power, defence, accuracy, speed;

public:
    // 생성자
    Player(string nickname) : nickname(nickname), level(1), HP(100), MP(50),
        power(10), defence(5), accuracy(5), speed(5) {
    }

    // 순수 가상 함수
    virtual void attack() = 0;

    // 플레이어 상태 출력
    void printPlayerStatus();
};

// Player::printPlayerStatus 함수 정의
void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << nickname << endl;
    cout << "직업: " << job_name << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "정확도: " << accuracy << endl;
    cout << "속도: " << speed << endl;
    cout << "------------------------------------" << endl;
}

// 전사 클래스
class Warrior : public Player {
public:
    Warrior(string nickname) : Player(nickname) {
        job_name = "Warrior";
        power = 20;
        defence = 15;
    }
    void attack() override {
        cout << nickname << " (전사): 강력한 검을 휘두릅니다!" << endl;
    }
};

// 마법사 클래스
class Magician : public Player {
public:
    Magician(string nickname) : Player(nickname) {
        job_name = "Magician";
        MP = 100;
        power = 25;
    }
    void attack() override {
        cout << nickname << " (마법사): 화염구를 발사합니다!" << endl;
    }
};

// 도적 클래스
class Thief : public Player {
public:
    Thief(string nickname) : Player(nickname) {
        job_name = "Thief";
        speed = 20;
        accuracy = 15;
    }
    void attack() override {
        cout << nickname << " (도적): 그림자에서 단검으로 찌릅니다!" << endl;
    }
};

// 궁수 클래스
class Archer : public Player {
public:
    Archer(string nickname) : Player(nickname) {
        job_name = "Archer";
        accuracy = 20;
        speed = 15;
    }
    void attack() override {
        cout << nickname << " (궁수): 날카로운 화살을 쏩니다!" << endl;
    }
};

// 메인 함수
int main() {
    Player* players[4]; // Player 포인터 배열

    int choice;
    string name;

    cout << "캐릭터를 선택하세요 (1. 전사 2. 마법사 3. 도적 4. 궁수): ";
    cin >> choice;

    cout << "닉네임을 입력하세요: ";
    cin >> name;

    switch (choice) {
    case 1: players[0] = new Warrior(name); break;
    case 2: players[0] = new Magician(name); break;
    case 3: players[0] = new Thief(name); break;
    case 4: players[0] = new Archer(name); break;
    default:
        cout << "잘못된 입력입니다!" << endl;
        return 0;
    }

    // 상태 출력
    players[0]->printPlayerStatus();

    // 공격 실행
    players[0]->attack();

    // 메모리 해제
    delete players[0];

    return 0;
}