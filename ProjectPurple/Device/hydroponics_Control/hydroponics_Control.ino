#include <SoftwareSerial.h>

#define RELAY_IN1 4
#define RELAY_IN2 5
#define RELAY_IN3 6
#define RELAY_IN4 7
#define RELAY_PUMP 8
#define fan1 11
#define fan2 12
#define fan3 13		//�ð��� �ɹ�ȣ

SoftwareSerial Serial_M(2, 3);	//�����ͺ���� ���

void Relay_Control(int cmd) {
	if (cmd == 4) {
		for (int i = RELAY_IN1; i <= RELAY_IN4; i++) {
			if (i == 6) {
				digitalWrite(i, HIGH);
				continue;
			}
			digitalWrite(i, LOW);
		}
	}
	else if (cmd == 5) {
		for (int i = RELAY_IN1; i <= RELAY_IN4; i++) {
			if (i == 6) {
				digitalWrite(i, LOW);
				continue;
			}
			digitalWrite(i, HIGH);
		}
	}
	else if (cmd == 12) {
		digitalWrite(RELAY_PUMP, LOW);
	}
	else if (cmd == 13) {
		digitalWrite(RELAY_PUMP, HIGH);
	}
}

void fan_control(int cmd) {
	if (cmd == 8) {
		digitalWrite(fan1, HIGH);
		digitalWrite(fan2, HIGH);
		digitalWrite(fan3, HIGH);

	}
	else if (cmd == 9) {
		digitalWrite(fan1, LOW);
		digitalWrite(fan2, LOW);
		digitalWrite(fan3, LOW);
	}
}

void setup()
{
	Serial.begin(9600);		//�����̺� ����� ���
	Serial_M.begin(9600);	//������ ����� ���
	pinMode(fan1, OUTPUT);
	pinMode(fan2, OUTPUT);
	pinMode(fan3, OUTPUT);		//�ð��� �ɸ�� : ���
	pinMode(RELAY_IN1, OUTPUT);
	pinMode(RELAY_IN2, OUTPUT);
	pinMode(RELAY_IN3, OUTPUT);
	pinMode(RELAY_IN4, OUTPUT);			//LED����� ������ �ɸ��.
	for (int i = RELAY_IN1; i <= RELAY_IN4; i++) {
		if (i == 6) {
			digitalWrite(i, LOW);
			continue;
		}
		digitalWrite(i, HIGH);
	}
	digitalWrite(fan1, LOW);
	digitalWrite(fan2, LOW);
	digitalWrite(fan3, LOW);
}

void loop()
{	//�ڵ������ ��� �����̺� ���忡�� ����.
	if (Serial.available()) {		//�����̺� ���忡�� ������ ������ ������ ���
		int cmd = Serial.parseInt();
		switch (cmd) {
		case 4:			//LED ON
			Relay_Control(4);
			Serial.print(1);
			break;
		case 5:			//LED OFF
			Relay_Control(5);
			Serial.print(0);
			break;
		case 8:			//FAN ON
			fan_control(8);
			Serial.print(1);
			break;
		case 9:			//FAN OFF
			fan_control(9);
			Serial.print(0);
			break;
		}
	}
	//������� ��� �����ͺ��忡�� ����.
	if (Serial_M.available()) {
		int cmd = Serial_M.parseInt();
		switch (cmd) {
		case 4:			//LED ON
			Relay_Control(4);
			Serial.print(1);
			break;
		case 5:			//LED OFF
			Relay_Control(5);
			Serial.print(0);
			break;
		case 8:			//FAN ON
			fan_control(8);
			break;
		case 9:			//FAN OFF
			fan_control(9);
			break;
		}
	}
}